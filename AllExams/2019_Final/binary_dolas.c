#include <stdio.h>
#include <stdlib.h>

typedef struct n{

    int data;
    struct n * left;
    struct n * right;
}node;

node *add (node *tree, int x){

    if(tree == NULL){
        node *root= (node *)malloc(sizeof(node));
        root -> left = NULL;
        root -> right = NULL;
        root -> data = x;
        return root;
    }

    else if(tree->data < x){
        tree->right = add(tree->right,x);
        return tree;
    }

    else{

        tree->left = add (tree->left,x);
        return tree;

    }
}


void Inorder(node *tree){

    if(tree == NULL){
        return;
    }

    Inorder(tree->left);
    printf("%d ",tree->data);    
    Inorder(tree->right);
    
}

void Preorder(node *tree){

	if(tree == NULL){
        return;
    }

    printf("%d ",tree->data);
    Preorder(tree->left);
    Preorder(tree->right);

}

void Postorder(node *tree){

	if(tree == NULL){
        return;
    }

    Postorder(tree->left);
    Postorder(tree->right);
    printf("%d ",tree->data);
   
}

int main(){
    
    int i=0;
    node * tree=NULL;

    int A[] = {9,20,8,18,25,30,7,1,0,6};

    for(i=0;i<sizeof(A)/sizeof(A[0]);i++){

        tree=add(tree,A[i]);

    }

    printf("\n Inorder : ");
    Inorder(tree);

    printf("\n Preorder : ");
    Preorder(tree);

    printf("\n Postorder : ");
    Postorder(tree);

    printf("\n");

}

