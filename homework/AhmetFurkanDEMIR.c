// Ahmet Furkan DEMIR
// 19010011019

// Bu odevi Kotlin ve Cpp programlama dilleri ile android ortamda calisabilir hale getirdim.
// Lınk : https://github.com/AhmetFurkanDEMIR/Infix-to-postfix-and-postfix-evaluation-in-Android

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// veri yapimiz, stack (ilk giren en son cikar)
typedef struct Stack{

	// char&double karakterleri tutacak olan degisken
	double character;

	// sonraki yapiya yani karaktere gecer.
	struct Stack *next;

}Node;

// root, tum yapiya burdan erisilecek
Node *root;

// Yeni yigin olusturur ve yigina char&double atamasi yapar.
// Stack veri yapisi oldugu icin her gelen veriyi en basa aldim,
// Boylece ilk giren en son cikan oldu.
void push(double character){

	// basa gelecek Stack yapimiz.
	Node *temp = (Node *)malloc(sizeof(Node));

	// karekter atamasi
	temp->character=character;

	// tempin nextini root 'a baglayarak sirayi korudum.
	temp->next = root;

	// root=temp ile de gelen veriyi yani yapiyi en basa almis oldum.
	root=temp;
}

// yapidan ilk veriyi cikartir yani yapiya en son eklenen veri manasina gelir.
double pop(){

	// root null ise daha fazla ileriye gidilemeyecegi icin bos karakter dondurdum.
	if(root==NULL){
		return '\0';
	}

	// data return edilecek
	double data = root->character;

	// ve return edeilen data yapidan cikartilacak.
	root = root->next;

	return data;
}

// Stack yapisini return ettigim fonksiyon, boylece her adim sonrasinda ekrana bastirmis olacagim.
char *PrintStack(char *temp){

	Node *iterator=root;

	int i=0;
	while(iterator!=NULL){

		temp[i] = (char)iterator->character;
		iterator=iterator->next;

		i+=1;
	}

	return temp;

}

// infix den postfixe donusturme islemini adim adim ekrana yazdirmak icin yazilmis fonksiyon.
void PrintInfixPostfix(char *exp, char *expj){

	int i;
	printf("\n | %s",exp);

	for(i=0;i<31-strlen(exp);i++){
		printf(" ");
	}

	char temp[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
	char *stack=PrintStack(temp);

	printf("| %s",stack);

	for(i=0;i<8-strlen(stack);i++){
		printf(" ");
	}

	printf("| %s",expj);

	for(i=0;i<38-strlen(expj);i++){
		printf(" ");
	}

	printf("|");

	printf("\n |________________________________|_________|_______________________________________|");

}

// gelen karaktere gore, islem onceligi hesaplanir ve return edilir.
int value(char ch){

	// toplama, cikarma = 1
	if(ch=='+' || ch=='-'){
		return 1;
	}

	// carpma, bolme, mod = 2
	else if(ch=='*' || ch=='/' || ch=='%'){
		return 2;
	}

	// us alma =  3
	else if(ch=='^'){
		return 3;
	}

	// hic biri ise -1 doner, burada bir islem operatoru yoktur demek.
	else{
		return -1;
	}

}

// infix den postfix 'e ceviri yaptigim yer.
char *InfixPostfix(char *exp, char *expj){

	// indisleme icin degisken
	int i=0, k=-1;

	// root un ilk degeri NULL, veri eklenince son deger olcak ve donguleri NULL 'a kadar devam ettirecegim.
	root=NULL;

	// array ve stack print edilir
	PrintInfixPostfix(&exp[i], expj);

	// exp[i] nin son karakterine (\0) kadar donecek olan dongu
	for (i = 0; exp[i]!='\0'; ++i){

		// eger karakter sayi ise expj arrayine aktarilir (8, 9, 10.8, 50 icin bu bloga girilir.).
		if(exp[i]>='0' && exp[i]<='9' || exp[i]=='.'){

				expj[++k] = exp[i];

		}

		// (-8), (-50.5) icin bu bloga girilir, negatif sayilar.
		if(exp[i-1]=='(' && exp[i]=='-'){
			expj[++k] = exp[i];
		}

		// parantez baslangici mi diye kontrol edilir ve Stack yapımıza eklenir.
		else if (exp[i] == '('){

			push(exp[i]);
		}

		// parantez kapamayi gorunce bu bloga girer.
		else if (exp[i] == ')'){

			// iki parantez arasini alir, expj dizisine aktarir.
			while(root!=NULL && root->character != '('){

				//pop
				expj[++k] = ' ';
				expj[++k] = pop();

			}

			// burda '(' kismi yigindan cikartilir, artik ihtiyac yoktur.
			pop();

		}

		// parantezler ve sayilir yoksa bu bloga girilir, yani islemler blogu
		else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^' || exp[i]=='%'){

			expj[++k] = ' ';

			//root!=NULL ve islem onceligine gore bu bloga girilir ve expj dizisine aktarilir.
			while(root!=NULL && value(exp[i]) <= value(root->character)){

				expj[++k] = pop();
				expj[++k] = ' ';

			}

			// yigina islem eklenir.
			push(exp[i]);

		}

		// dongu sonunda array ve stack print edilir.
		PrintInfixPostfix(&exp[i+1], expj);

	}

	// yiginin geri kalani diziye aktarilir.
	while (root!=NULL){

		expj[++k] = ' ';
		expj[++k] = pop();

		// dongu sonunda array ve stack print edilir.
		PrintInfixPostfix(&exp[i], expj);
	}

	// sonu belirlenir
	expj[++k] = '\0';

	// son hali array ve stack print edilir.
	PrintInfixPostfix(&exp[i], expj);

	// ve return edilir.
	return expj;
}

// postfix bir ifadeyi hesaplama islemini adim adim ekrana yazdirmak icin yazilmis fonksiyon.
void PrintPostfixEvaluation(){

	int i=0,j, count=0;
	Node *iterator=root;


	printf("\n | ");

	while(iterator!=NULL){

		j=iterator->character;

		if((double)j<(double)0){
			count+=1;
		}

		do{

	        count++;

	        j /= 10;
    	}while(j != 0);

    	count+= 8;

		printf("%lf ",iterator->character);
		iterator=iterator->next;

	}

	for(i=0;i<62-count;i++){
		printf(" ");
	}
	printf("|");

	printf("\n |_______________________________________________________________|");

}

// matamatik operatorune gore islem yapilir ve return edilir.
double doMath(char op, double op1, double op2) {

	// carpma
    if(op == '*') {
        return (op1 * op2);
    }

    // bolme
    else if(op == '/') {
        return (op1 / op2);
    }

    // mod alma (double)
    else if(op == '%'){
        return fmod(op1 , op2);
    }

    // toplama
    else if(op == '+') {
        return (op1 + op2);
    }

    // cikartma
    else if(op == '-'){
        return (op1 - op2);
    }


    // us alma
    else if(op == '^'){
    	return pow(op1, op2);
    }

}

// postfix bir degeri hesapladigim fonksiyon
double postfixEval(char *postfixExpr) {

	// indisleme
	int i, temp_i=0,j;

	// root un ilk degeri NULL, veri eklenince son deger olcak ve donguleri NULL 'a kadar devam ettirecegim.
    root = NULL;

    // verileri sirayla buraya ekleyecegim, sonra bu verileri double sayi tipine donusturdum.
    char temp[10];

    // postfix ifadenin sonuna kadar donecek olan degisken
    for (i=0;postfixExpr[i]!='\0';i++) {

    	// eger karakter sayi ise temp dizisine aktarilir (8, 9, 10.8, 50 icin bu bloga girilir.).
        if((postfixExpr[i]>='0' && postfixExpr[i]<='9') || (postfixExpr[i]=='.')){

            temp[temp_i] = postfixExpr[i];
            temp_i+=1;
        }

        // eger karakter sayi degilse bu bloga girilir ve dizi sayiya donusturulup Stack 'a aktarilir.
        if(!(postfixExpr[i]>='0' && postfixExpr[i]<='9') && temp_i!=0 && postfixExpr[i]!='.'){

        	// eksi sayi icin girmez
        	if(!(postfixExpr[i]=='-' && (postfixExpr[i+1]>='0' && postfixExpr[i+1]<='9'))){

        		push(atof(temp));

        		// diziyi bosaltiyoruz.
        		for(j=0;j<temp_i;j++){
        			temp[j]='\0';
        		}

        		temp_i = 0;

        	}

        }

        // 6 islemden herhangi biri varsa bu bloga girilir ve islem yapilir.
        if (postfixExpr[i]=='+' || postfixExpr[i]=='-' || postfixExpr[i]=='*' || postfixExpr[i]=='/' || postfixExpr[i]=='^' || postfixExpr[i]=='%'){

        	// eksi sayi icin
        	if(postfixExpr[i]=='-' && (postfixExpr[i+1]>='0' && postfixExpr[i+1]<='9')){
        		temp[temp_i] = postfixExpr[i];
            	temp_i+=1;
            	continue;
        	}

        	// stack den sayilar alinir ve islem yapilip fonksiyona return edilir.

        	// sayi2
            double operand2 = pop();

            // sayi1
            double operand1 = pop();

            // islem yapilir ve return edilir.
            double result = doMath(postfixExpr[i], operand1, operand2);

            // sonuc stack 'a eklenir.
            push(result);

        }

        // adim adim print ettigim fonksiyon
        PrintPostfixEvaluation();

    }

    // stack daki son eleman islem sonucudur, pop edilip stack bosaltilir ve sonuc bulunur.
    return pop();
}

int main(){

    // Bu odev; +, -, *, /, ^, % islemlerini yapabilir.
    // tum bu islemleri (-) veya + sayilarda yapabilir.

	int i;
	double result;

	// infix veri
	char data[] = "((5*(80+90)-(-100))/4^4)%2";

	// postfix verinin depolanacagi array
	char expj[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

	// inifix ifade
	printf("\n  <-> Infix ifade : %s <->",data);

	// Infix to Postfix
	printf("\n  __________________________________________________________________________________");
	printf("\n |                              Infix to Postfix                                    |");
	printf("\n |__________________________________________________________________________________|");
	printf("\n |              Infix             |  Stack  |                Postfix                |");
	printf("\n |________________________________|_________|_______________________________________|");
	char *postfix = InfixPostfix(data, expj);

	// Evaluation of Postfix Expression
	printf("\n  _______________________________________________________________");
	printf("\n |                Evaluation of Postfix Expression               |");
	printf("\n |_______________________________________________________________|");
	printf("\n |                    Stack Visualization                        |");
	printf("\n |_______________________________________________________________|");
	result = postfixEval(postfix);
	printf("\n\n  <-> Postfix Evaluation Result : %lf <->",result);

	printf("\n\n");
	return 0;
}
