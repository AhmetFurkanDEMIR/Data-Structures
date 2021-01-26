#include<stdio.h>
#include<stdlib.h>

// yapi
typedef struct n{

    // data
    int data;

    // yukseklik, cevirme islemleri icin gereki
    int height;

    //  sol cocuk
    struct n * left;

    // sag cocuk
    struct n * right;

}node;
 
// avl agacdaki minumum degeri recursiv olarak tespit eder ve return eder.
node *min(node *avl){

	if(avl->left==NULL){
		return avl;
	}

	avl = min(avl->left);

}

// avl agacdaki maximum degeri recursiv olarak tespit eder ve return eder.
node *max(node *avl){

    if(avl->right==NULL){
        return avl;
    }

    avl = min(avl->right);

}

// sağa doğru rotation
// sol,sol ve sol, sag durumlarında kullanilir.
node *right(node *y){

    node *x = y->left;
    node *S = x->right;
 
    x->right = y;
    y->left = S;
 	
    int nb=1;

    int left0 = (y->left==NULL) ? 0 : y->left->height;
    int right0 = (y->right==NULL) ? 0 : y->right->height;

    y->height = ((left0>right0) ? left0 : right0) + 1;

    left0 = (x->left==NULL) ? 0 : x->left->height;
    right0 = (x->right==NULL) ? 0 : x->right->height;

    x->height = ((left0>right0) ? left0 : right0) + 1;

    return x;
}
 
// sola dogru rotation
// sag,sag ve sag,sol durumlarinda kullanilir.
node *left(node *x){

    node *y = x->right;
    node *S = y->left;
 

    y->left = x;
    x->right = S;

    int left0 = (y->left==NULL) ? 0 : y->left->height;
    int right0 = (y->right==NULL) ? 0 : y->right->height;
 
    y->height = ((left0>right0) ? left0 : right0) + 1;

    left0 = (x->left==NULL) ? 0 : x->left->height;
    right0 = (x->right==NULL) ? 0 : x->right->height;

    x->height = ((left0>right0) ? left0 : right0) + 1;
 

    return y;
}

// avl agaca yeni dugum ekleme, recursiv.
node *add(node *avl, int data){

    // avl null ise yeni dugum eklenir ve yukseklik 1 atanir.
    if (avl == NULL){

    	node *tree = (node *)malloc(sizeof(node));
    	tree->data   = data;
    	tree->left   = NULL;
    	tree->right  = NULL;
    	tree->height = 1; 

    	return tree;
    }
    
    // avl 'nin sagina ekleme yapma, BST deki ayni mantik.
    if (data < avl->data){
        avl->left  = add(avl->left, data);
    }

    // avl 'nin soluna ekleme yapma, BST deki ayni mantik.
    else{
        
        avl->right = add(avl->right, data);
    }
 

    // avl node'nin yükseklik hesaplamasi. En yuksek deger alinir.
    // deger null ise 0 donduren kisa bir if yazdim, degilse o dugumun yuksekligi alinir.
    int left0 = (avl->left==NULL) ? 0 : avl->left->height;
    int right0 = (avl->right==NULL) ? 0 : avl->right->height;

    // avl node 'nin sag ve sol kismindan gelen en yuksek deger +1, o node nin yuksegligi olur.
    avl->height = ((left0>right0) ? left0 : right0) + 1;
    // birbirinden cikartarak dengeyi ogrendim.
    int balance = left0 - right0;
    // sol,sol durumu
    if (balance > 1 && data < avl->left->data){
        return right(avl);
    }
    
    // sag, sag durumu
    if (balance < -1 && data > avl->right->data){
        return left(avl);
    }

    // sol, sag durumu
    if (balance > 1 && data > avl->left->data){

        avl->left =  left(avl->left);
        return right(avl);
    }

    // sag, sol durumu
    if (balance < -1 && data < avl->right->data){

        avl->right = right(avl->right);
        return left(avl);
    }
    
    // en sonda avl agaci return edilir.
    return avl;
}
 
// avl agacdan node silmek.
node *delete(node *avl, int data){
    
    // null ise return.
    if (avl == NULL){
        return avl;  
    }
    
    // istenilen data ise silinme islemi
    if(data==avl->data){

        // sag ve sol cocuklar yoksa null retur edilir ve silinir.
        if(avl->left==NULL && avl->right==NULL){
            return NULL;
        }

        // sag cocuk varsa
        else if(avl->right!=NULL){

            // en kucuk deger getirilir ve en kucuk degere sahip node silinir.
            avl->data = min(avl->right)->data;
            avl->right = delete(avl->right, min(avl->right)->data);
            return avl;
        }

        // sol cocuk yoksa
        else if(avl->left!=NULL){

            // en buyuk deger getirilir ve en buyuk degere sahip node silinir.
            avl->data = max(avl->left)->data;
            avl->left = delete(avl->left,max(avl->left)->data);
            return avl;

        }

    }

    // data kucuk ise sol taraftan aranmaya defam edilir.
    else if (data < avl->data){
        avl->left = delete(avl->left, data);  
    }
    
    // data buyuk ise sag taraftan aranmaya devam edilir. 
    else if(data > avl->data){

        avl->right = delete(avl->right, data);  
    }
  
    // bulunamadiysa null olarak return edilir.
    if (avl == NULL){
    
    	return avl;  
 	}

    // buraya kadarki silme islemi BST ile ayni idi.
    // simdi denge hesaplayarak gerekli döndürme islemlerini yapmaliyiz.

    // avl node'nin yükseklik hesaplamasi. En yuksek deger alinir.
    // deger null ise 0 donduren kisa bir if yazdim, degilse o dugumun yuksekligi alinir.
    int left0 = (avl->left==NULL) ? 0 : avl->left->height;
    int right0 = (avl->right==NULL) ? 0 : avl->right->height;

    // sag ve sol agacın en yuksek degeri +1 alinir ve atanir.
    avl->height = ((left0>right0) ? left0 : right0) + 1;
    
    // birbirinden cikartarak dengeyi ogrendim.
    int balance = left0 - right0;

    // sol,sol durumu 
    if (balance > 1 && (((avl->left->left==NULL) ? 0 : avl->left->left->height) - ((avl->left->right==NULL) ? 0 : avl->left->right->height)) >= 0){

        return right(avl);  
    }
  
    // sol, sag durumu
    if (balance > 1 && (((avl->left->left==NULL) ? 0 : avl->left->left->height) - ((avl->left->right==NULL) ? 0 : avl->left->right->height)) < 0){  

        avl->left = left(avl->left);  
        return right(avl);  
    }  
    
    // sag,sag durumu
    if (balance < -1 && (((avl->right->left==NULL) ? 0 : avl->right->left->height) - ((avl->right->right==NULL) ? 0 : avl->right->right->height)) <= 0){

        return left(avl);  
	}

    // sag,sol durumu
    if (balance < -1 && ((((avl->right->left==NULL) ? 0 : avl->right->left->height) - ((avl->right->right==NULL) ? 0 : avl->right->right->height)) > 0)){  

        avl->right = right(avl->right);  
        return left(avl);  
    }  
  
    return avl;  
}  

// inorder dolasma
void Inorder(node *tree){

    if(tree == NULL){
        return;
    }

    Inorder(tree->left);
    printf("(D=%d/H=%d) ",tree->data, tree->height);     
    Inorder(tree->right);
    
}

// preorder dolasma
void Preorder(node *tree){

    if(tree == NULL){
        return;
    }

    printf("(D=%d/H=%d) ",tree->data, tree->height);    
    Preorder(tree->left);
    Preorder(tree->right);

}

// postorder dolasma
void Postorder(node *tree){

    if(tree == NULL){
        return;
    }

    Postorder(tree->left);
    Postorder(tree->right);
    printf("(D=%d/H=%d) ",tree->data, tree->height);  
   
}

int main(){

	node *root = NULL;

	int A[] = {15,34,22,20,19,4,1};
	int B[] = {22,34,20};
	int i=0;

    printf("\n\n Add \n");
	for(i=0;i<sizeof(A)/sizeof(A[0]);i++){
		root = add(root, A[i]);
		printf("\n ");
		Preorder(root);
	}
 	
	printf("\n\n Delete \n");

	for(i=0;i<sizeof(B)/sizeof(B[0]);i++){
		root = delete(root, B[i]);
		printf("\n ");
		Preorder(root);
	}


	printf("\n");
 
	return 0;
}