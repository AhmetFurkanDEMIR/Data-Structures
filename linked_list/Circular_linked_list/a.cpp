#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// beyaz
#define KNRM  "\x1B[0m"

// kırmızı
#define KRED  "\x1B[31m"

// yesil
#define KGRN  "\x1B[32m"

// turuncu
#define KYEL  "\x1B[33m"

// mavi
#define KBLU  "\x1B[34m"

// turkuaz
#define KCYN  "\x1B[36m"

// Linux/Unix = clear
// Windows = cls
#define clear() system("clear");

typedef struct telefon{

	char tel_turu[20];
	char tel[11];
	
	telefon * next_no;

}tel;


typedef struct Kartvizit{

	char ad_soyad[30];
	
	tel * next_no;

	Kartvizit * next;

}node;

node *root, *iterator;
tel * iterator_tel, * tela;
int kn=0;

void ekle(){

	int temp, i = 1;

	if(kn==0){

		clear();
		printf("\n\n%s  --- demir.ai Kartvizit (Kişi ekle) --- \n%s",KBLU, KNRM);

		kn+=1;
		root = (node *)malloc(sizeof(node));
		root->next=root;
		getchar();

		printf("\n%s   Kisi Adi Ve Soyadi : ",KCYN);
		fgets(root->ad_soyad, sizeof(root->ad_soyad), stdin);
		
		root->next_no=(tel *)malloc(sizeof(tel));
		tela = root->next_no;
		iterator_tel = root->next_no;

		while(1){

			printf("\n\n%s      %d. Telefon numara türü (ev, iş, cep, vb.) : ", KGRN, i);
			scanf("%s",&iterator_tel->tel_turu);

			printf("\n\n      %d. Telefon numara : ", i);
			scanf("%s",&iterator_tel->tel);

			printf("\n\n%s         Numara eklemeyi sonlandırmak için 1'e basınız : ", KYEL);
			scanf("%d",&temp);

			i+=1;

			if(temp==1){

				iterator_tel->next_no=tela;

				printf("%s\n", KNRM);
				break;
			}
			
			iterator_tel->next_no = (tel *)malloc(sizeof(tel));;
			iterator_tel=iterator_tel->next_no;

			clear();
			printf("\n\n%s  --- demir.ai Kartvizit (Kişi ekle) --- \n%s",KBLU, KNRM);
			printf("\n%s   Kisi Adi Ve Soyadi : %s",KCYN, root->ad_soyad);

		}

	}

	else{

		clear();
		printf("\n\n%s  --- demir.ai Kartvizit (Kişi ekle) --- \n%s",KBLU, KNRM);

		node *tempa;
		iterator = root;

		while(iterator->next!=root){

			iterator=iterator->next;

		}

		tempa = (node *)malloc(sizeof(node));
		kn += 1;
		iterator->next = tempa;
		tempa->next=root;
		getchar();

		printf("\n%s   Kisi Adi Ve Soyadi : ",KCYN);
		fgets(tempa->ad_soyad, sizeof(tempa->ad_soyad), stdin);
		
		tempa->next_no=(tel *)malloc(sizeof(tel));
		tela = tempa->next_no;
		iterator_tel = tempa->next_no;

		while(1){

			printf("\n\n%s      %d. Telefon numara türü (ev, iş, cep, vb.) : ", KGRN, i);
			scanf("%s",&iterator_tel->tel_turu);

			printf("\n\n      %d. Telefon numara : ", i);
			scanf("%s",&iterator_tel->tel);

			printf("\n\n%s         Numara eklemeyi sonlandırmak için 1'e basınız : ", KYEL);
			scanf("%d",&temp);

			i+=1;

			if(temp==1){

				iterator_tel->next_no=tela;

				printf("%s\n", KNRM);
				break;
			}
			
			iterator_tel->next_no = (tel *)malloc(sizeof(tel));;
			iterator_tel=iterator_tel->next_no;

			clear();
			printf("\n\n%s  --- demir.ai Kartvizit (Kişi ekle) --- \n%s",KBLU, KNRM);
			printf("\n%s   Kisi Adi Ve Soyadi : %s",KCYN, tempa->ad_soyad);

		}

	}

}

void listele(){

	if (root == NULL){
        return; 
    }

	iterator = root;
	int temp, i, j = 1;

	clear();

	printf("\n\n%s  --- demir.ai Kartvizit (Listele) --- \n%s",KBLU, KNRM);

	do{

		printf("\n%s    %d. Kisi Adı Ve Soyadi : %s",KCYN, j, iterator->ad_soyad);
		
		i = 1;
		iterator_tel = iterator->next_no;
		tela = iterator->next_no;

		do{

			if(i%2==0){

				printf("\n\n%s       %d. Telefon numara türü (ev, iş, cep, vb.) : %s", KGRN, i, iterator_tel->tel_turu);

				printf("\n\n       %d. Telefon numara : %s", i, iterator_tel->tel);
			}

			else{

				printf("\n\n%s       %d. Telefon numara türü (ev, iş, cep, vb.) : %s", KYEL, i, iterator_tel->tel_turu);

				printf("\n\n       %d. Telefon numara : %s", i, iterator_tel->tel);

			}

			i+=1;
			iterator_tel = iterator_tel->next_no;

		}while(iterator_tel!=tela);

		printf("\n\n%s  -----------------------------\n%s",KBLU,KNRM);

		j+=1;
		iterator = iterator->next;


	}while(iterator!=root);


	printf("\n\n%s    Ana menüye dönmek için 1' e basınız : ", KYEL);
	scanf("%d",&temp);
	printf("%s\n", KNRM);

}

int sila(char *sil_ad){

	int asd=0;

    node *temp = root, *back;

    iterator=root;

    if(root->next==root && strcmp(root->ad_soyad,sil_ad)==0){

    	free(root);
    	root=NULL;
    	asd=1;
    	kn-=1;
    	return asd;
    }

    while(iterator->next!=root){

    	iterator=iterator->next;

    }

    while(strcmp(temp->ad_soyad,sil_ad)==0){

    	iterator->next=root->next;
        root = root->next;
        free(temp);
        temp = root;

        kn-=1;
        asd=1;

        if(temp->next==root){
        	
        	if(strcmp(temp->ad_soyad,sil_ad)==0){
        		
        		free(root);
        		root=NULL;
        		kn-=1;
        		asd=1;
        	}

        	return asd;
        }
    }

    while(1){

        while (strcmp(temp->ad_soyad,sil_ad)!=0){

            back = temp;
            temp = temp->next;

            if(temp==root){
            	break;
            }
        }

        if (temp == root){
            return asd;
        }

        back->next = temp->next;
        free(temp);
        temp = back->next;

        kn-=1;
        asd=1;

        if(temp->next==root){

        	if(strcmp(temp->ad_soyad,sil_ad)==0){
        		
        		back->next=root;
        		free(temp);

        		kn-=1;
        		asd=1;
        	}

        	break;

        }
    }

    return asd;

}

void sil(){

	if (root == NULL){
        return; 
    }

    char sil_ad[40];
    int tempb;
    getchar();

	clear();
	printf("\n\n%s  --- demir.ai Kartvizit (Kisi Sil) ---",KBLU);

	printf("\n\n%s    Silinecek Kisi Adi Ve Soyadi : ",KCYN);
	fgets(sil_ad, sizeof(sil_ad), stdin);

	int kntr = sila(sil_ad);

	if(kntr==1){
		printf("\n\n%s      Kisi basari ile silindi, Ana menü icin 1'e basınız : ",KYEL);
		scanf("%d",&tempb);
		printf("%s\n", KNRM);
	}

	else{

		printf("\n\n%s      Silinecek Kisi bulunamadi, Ana menü icin 1'e basınız : ",KRED);
		scanf("%d",&tempb);
		printf("%s\n", KNRM);

	}


}

int araaa(char *ara){

	int kntrl=0, byt, i=0, z=1, a=0, j=1,k=0;

	while(*(ara+i)!='\0'){

		i+=1;
	}

	byt = i;

	iterator=root;

	clear();
	printf("\n\n%s  --- demir.ai Kartvizit (Kisi Ara) ---\n",KBLU);

	do{

		a=0;

		for(i=0; i<byt-1; ++i){
		
			if(*(iterator->ad_soyad+i)==*(ara+i)){
				z+=1;
			}

			else{

				z=1;
				break;
			}

			if(z==byt){
				a=1;
				kntrl=1;
				z=1;
				break;
			}

		}

		if(a==1){

			printf("\n%s    %d. Kisi Adı Ve Soyadi : %s",KCYN, j, iterator->ad_soyad);

			k=1;
			j+=1;

			tela = iterator->next_no;
			iterator_tel = iterator->next_no;

			do{

				if(k%2==0){

					printf("\n\n%s       %d. Telefon numara türü (ev, iş, cep, vb.) : %s", KGRN, k, iterator_tel->tel_turu);

					printf("\n\n       %d. Telefon numara : %s", k, iterator_tel->tel);
				}

				else{

					printf("\n\n%s       %d. Telefon numara türü (ev, iş, cep, vb.) : %s", KYEL, k, iterator_tel->tel_turu);

					printf("\n\n       %d. Telefon numara : %s", k, iterator_tel->tel);

				}

				iterator_tel = iterator_tel->next_no;
				k+=1;
			}while(iterator_tel!=tela);

			printf("\n\n%s  -----------------------------\n%s",KBLU,KNRM);
		}

		iterator=iterator->next;

	}while(iterator!=root);

	if(kntrl==1){
		
		printf("\n\n%s    Ana menüye dönmek için 1' e basınız : ", KYEL);
		scanf("%d",&k);
		printf("%s\n", KNRM);
	}

	return kntrl;

}

void araa(){

	if (root == NULL){
        return; 
    }

    char ara[40];
    int tempb;

    clear();
    getchar();
	printf("\n\n%s  --- demir.ai Kartvizit (Kisi Ara) ---",KBLU);

	printf("\n\n%s    Kartvizitte Aranacak Kisi Adi Ve Soyadi : ",KCYN);
	fgets(ara, sizeof(ara), stdin);

	int kntr = araaa(ara);

	if(kntr==0){

		printf("\n\n%s    Kisi bulunamadi, Ana menü icin 1'e basınız : ",KRED);
		scanf("%d",&tempb);
		printf("%s\n", KNRM);

	}

}

int tel_araaa(char *ara){

	int kntrl=0, byt, i=0, z=1, a=0, j=1,k=0;

	while(*(ara+i)!='\0'){

		i+=1;
	}

	byt = i;

	iterator=root;

	clear();
	printf("\n\n%s  --- demir.ai Kartvizit (Kisi Ara) ---\n",KBLU);

	do{

		tela = iterator->next_no;
		iterator_tel = iterator->next_no;

		do{

			a=0;

			for(i=0; i<byt-1; ++i){
			
				if(*(iterator_tel->tel+i)==*(ara+i)){
					z+=1;
				}

				else{

					z=1;
					break;
				}

				if(z==byt){
					a=1;
					kntrl=1;
					z=1;
					break;
				}

			}

			if(a==1){
				break;
			}

			iterator_tel=iterator_tel->next_no;

		}while(iterator_tel!=tela);

		if(a==1){

			printf("\n%s    %d. Kisi Adı Ve Soyadi : %s",KCYN, j, iterator->ad_soyad);

			k=1;
			j+=1;

			tela = iterator->next_no;
			iterator_tel = iterator->next_no;

			do{

				if(k%2==0){

					printf("\n\n%s       %d. Telefon numara türü (ev, iş, cep, vb.) : %s", KGRN, k, iterator_tel->tel_turu);

					printf("\n\n       %d. Telefon numara : %s", k, iterator_tel->tel);
				}

				else{

					printf("\n\n%s       %d. Telefon numara türü (ev, iş, cep, vb.) : %s", KYEL, k, iterator_tel->tel_turu);

					printf("\n\n       %d. Telefon numara : %s", k, iterator_tel->tel);

				}

				iterator_tel = iterator_tel->next_no;
				k+=1;
			}while(iterator_tel!=tela);

			printf("\n\n%s  -----------------------------\n%s",KBLU,KNRM);
		}

		iterator=iterator->next;

	}while(iterator!=root);

	if(kntrl==1){
		
		printf("\n\n%s    Ana menüye dönmek için 1' e basınız : ", KYEL);
		scanf("%d",&k);
		printf("%s\n", KNRM);
	}

	return kntrl;

}

void tel_ara(){

	if (root == NULL){
        return; 
    }

    char tele[11];
    int tempb;

    clear();
    getchar();
	printf("\n\n%s  --- demir.ai Kartvizit (Kisi Ara) ---",KBLU);

	printf("\n\n%s    Kartvizitte Aranacak Kisinin Telefon Numarasi : ",KCYN);
	fgets(tele, sizeof(tele), stdin);

	int kntr = tel_araaa(tele);

	if(kntr==0){

		printf("\n\n%s    Kisi bulunamadi, Ana menü icin 1'e basınız : ",KRED);
		scanf("%d",&tempb);
		printf("%s\n", KNRM);

	}

}

void swap(node *a, node *b){

    char temp_ad_soyad[30];
    strcpy(temp_ad_soyad, a->ad_soyad);
    strcpy(a->ad_soyad, b->ad_soyad);
    strcpy(b->ad_soyad, temp_ad_soyad);

	tela = a->next_no;
	a->next_no = b->next_no;
	b->next_no = tela;

}

void sirala(int laal){

	if(root==NULL){
        return; 
    }

	int swapped, i, sn; 
    node *ptr1; 
    node *lptr = NULL; 

    do{ 
        swapped = 0; 
        ptr1 = root; 
  
        do{

        	sn = strcmp(ptr1->ad_soyad, ptr1->next->ad_soyad);
            
            if(sn>0){

                swap(ptr1, ptr1->next); 
                swapped = 1; 
            }

            ptr1 = ptr1->next;

        }while(ptr1->next!=root);

        lptr = ptr1; 

    }while(swapped);

    if(laal==1){
    	listele();
    }


}

node *yer_belirle(char *ara){

	iterator = root;
	node *temp;

	int sn = strcmp(root->ad_soyad, ara), c=0;

	if(sn>=0){

		do{

			iterator=iterator->next;

		}while(iterator->next!=root);

		temp = (node *)malloc(sizeof(node));
		iterator->next=temp;
		temp->next=root;
		root=temp;
		kn+=1;

		return root;
	}

	while(1){

		if(iterator->next==root){
			c=1;
			break;
		}

		sn = strcmp(iterator->next->ad_soyad, ara);

		if(sn>=0){

			c=0;
			break;
		}

		iterator=iterator->next;
	}

	if(c==1){

		temp = (node *)malloc(sizeof(node));
		iterator->next=temp;
		temp->next=root;
		kn+=1;	

	}

	else{

		temp = iterator->next;
		iterator->next = (node *)malloc(sizeof(node));
		iterator->next->next = temp;
		kn+=1;
	}

	return iterator->next;

}

void sirali_ekle(){

    sirala(0);

    char add[30];
    int temp, i=1;

    clear();
	printf("\n\n%s  --- demir.ai Kartvizit (Sirali Kişi ekle) --- \n%s",KBLU, KNRM);
	getchar();

	printf("\n%s   Kisi Adi Ve Soyadi : ",KCYN);
	fgets(add, sizeof(add), stdin);

    iterator = yer_belirle(add);

    strcpy(iterator->ad_soyad, add);

    iterator->next_no=(tel *)malloc(sizeof(tel));
	tela = iterator->next_no;
	iterator_tel = iterator->next_no;

	while(1){

		printf("\n\n%s      %d. Telefon numara türü (ev, iş, cep, vb.) : ", KGRN, i);
		scanf("%s",&iterator_tel->tel_turu);

		printf("\n\n      %d. Telefon numara : ", i);
		scanf("%s",&iterator_tel->tel);

		printf("\n\n%s         Numara eklemeyi sonlandırmak için 1'e basınız : ", KYEL);
		scanf("%d",&temp);

		i+=1;

		if(temp==1){

			iterator_tel->next_no=tela;

			printf("%s\n", KNRM);
			break;
		}
			
		iterator_tel->next_no = (tel *)malloc(sizeof(tel));;
		iterator_tel=iterator_tel->next_no;

		clear();
		printf("\n\n%s  --- demir.ai Kartvizit (Kişi ekle) --- \n%s",KBLU, KNRM);
		printf("\n%s   Kisi Adi Ve Soyadi : %s",KCYN, root->ad_soyad);

	}

}

int main(){

	while(1){

		int secim;
		int temp;
		int knaaa = 0;

		clear();

		printf("\n\n%s  --- demir.ai Kartvizit ---",KBLU);
		printf("\n\n%s   1-) Kisi Ekle\n", KGRN);
		printf("\n%s   2-) Sirali Kisi Ekle\n", KCYN);
		printf("\n%s   3-) Kisi Sil\n",KGRN);
		printf("\n%s   4-) Listele\n",KCYN);
		printf("\n%s   5-) Sirali Listele\n",KGRN);
		printf("\n%s   6-) Ad ile Kisi Ara\n",KCYN);
		printf("\n%s   7-) Tel No ile Kisi Ara\n",KCYN);
		printf("\n%s   8-) Quit",KGRN);

		printf("\n\n%s     Secim : ",KYEL);
		scanf("%d",&secim);
		printf("%s",KNRM);

		switch(secim){


			case 1:
				ekle();
				break;

			case 2:
				if(kn==0){

					ekle();
				}

				else{

					sirali_ekle();
				}
				break;

			case 3:
				sil();
				break;

			case 4:
				listele();
				break;

			case 5:
				sirala(1);
				break;

			case 6:
				araa();
				break;

			case 7:
				tel_ara();
				break;

			case 8:
				system("clear");
				return 1;
				break;

			default:
				printf("\n\n%s    Hatali islem, Ana menüye donmek icin 1'e basınız, Çıkmak için 2'ye basınız : ",KRED);
				scanf("%d",&temp);
				printf("%s\n", KNRM);

				if(temp==2){
					return 0;
				}
		}

	}

	printf("\n\n");
	return 0;
}
