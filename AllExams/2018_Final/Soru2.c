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

int plus(node *tree, int top){

	if(tree == NULL){
        return top;
    }

    top += tree->data;
    top = plus(tree->right, top);
    top = plus(tree->left, top);

    return top;
}

int main(){

    node * tree=NULL;

    tree=add(tree,56);
    tree=add(tree,200);


    int top = 0;
    top = plus(tree,top);

    printf("\n  top : %d",top);

}