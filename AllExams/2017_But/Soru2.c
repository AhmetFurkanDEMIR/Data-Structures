#include <stdio.h>
#include <stdlib.h>

// yapimiz, node
typedef struct n{

    int data;
    struct n * left;
    struct n * right;
}node;

// recursiv olarak yeni node(data) ekleme.
node *add (node *tree, int x){

    // tree==NULL ise yeni node olusturulur ve bu node return edilir.
    if(tree == NULL){
        node *root= (node *)malloc(sizeof(node));
        root -> left = NULL;
        root -> right = NULL;
        root -> data = x;
        return root;
    }

    // data buyuk ise, agacin sagina yeni node eklenir, recursiv olarak return ededen eklenir.
    else if(tree->data>x){

        tree->left = add (tree->left,x);
        return tree;

    }

    // data kucuk ise, agacin soluna yeni node eklenir, recursiv olarak return ededen eklenir.
    else if(tree->data <= x){
        tree->right = add(tree->right,x);
        return tree;
    }

}

// aranan veri var ise 1 dondurur.
int search(node * tree, int x){

    // tree==NULL 'a kadar geldi ve bisey bulamadiysa -1 doner.
    if(tree == NULL){
        return -1;
    }

    // data bulunduysa 1 doner
    if(tree->data == x){
        return 1;
    }

    // agacin saginda data bulundu ise 1 doner.
    if(search(tree->right,x)==1){
        return 1;
    }

    // agacin solunda data bulundu ise 1 doner.
    if(search(tree->left,x)==1){
        return 1;
    }

    // bulunmadiysa -1
    return -1;
}

// recursiv olarak agacin sagina gider ve en buyuk degeri alir.
int max(node *tree){

    while(tree->right!=NULL){
        tree=tree->right;
    }

    return tree->data;
}

// recursiv olarak agacin soluna gider ve en kucuk degeri alir.
int min(node *tree){

    while(tree->left!=NULL){
        tree=tree->left;
    }

    return tree->data;
}

// agac dan node silme
node *remove0(node *tree,int x){

    // tree==NULL ise return NULL
    if(tree==NULL){
        return NULL;
    }

    // data ile node eslesdi ise girer
    if(tree->data == x){


        // sag da ve solda cocuk yoksa direk siler
        if(tree->left==NULL && tree->right==NULL){
            return NULL;
        }

        // solda cocuk varsa
        else if(tree->left!=NULL){

            // solda eleman silerken, en buyuk deger alinir.
            tree->data = max(tree->left);
            // en butuk deger siliir.
            tree->left = remove0(tree->left,max(tree->left));
            return tree;

        }

        // sagda cocuk varsa girer
        else if(tree->right!=NULL){

            // sagda eleman silerken, en kucuk deger alinir.
            tree->data = min(tree->right);
            // en kucuk deger silinir.
            tree->right = remove0(tree->right, min(tree->right));
            return tree;
        }

    }

    // data, agacdaki node dan buyuk ise arama islemi sag tarafta surdurulur.
    // boylece arama ve silme isleminde maliyet yariya duser yani O(logn)
    if(tree->data <= x){

        tree->right = remove0(tree->right,x);
        return tree;
    }

    // data, agacdaki node dan kucuk ise sol tarafta arama islemi yapilir.
    else if(tree->data>x){

        tree->left= remove0(tree->left,x);
        return tree;

    }

}

// LNR
void Inorder(node *tree){

    if(tree == NULL){
        return;
    }

    Inorder(tree->left);
    printf("%d ",tree->data);    
    Inorder(tree->right);
    
}

// NLR
void Preorder(node *tree){

    if(tree == NULL){
        return;
    }

    printf("%d ",tree->data);
    Preorder(tree->left);
    Preorder(tree->right);

}

// LRN
void Postorder(node *tree){

    if(tree == NULL){
        return;
    }

    Postorder(tree->left);
    Postorder(tree->right);
    printf("%d ",tree->data);
   
}

// main
int main(){

    node * tree=NULL;

    tree=add(tree,56);
    tree=add(tree,200);
    tree=add(tree,26);
    tree=add(tree,213);
    tree=add(tree,18);
    tree=add(tree,28);
    tree=add(tree,12);
    tree=add(tree,26);

    tree = remove0(tree, 26);

    Postorder(tree);

}

