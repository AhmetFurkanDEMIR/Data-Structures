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

int count(node *tree, int count_dg){

	if(tree == NULL){
        return count_dg;
    }

    count_dg +=1;
    count_dg = count(tree->right, count_dg);
    count_dg = count(tree->left, count_dg);

    return count_dg;

}

int main(){

    node * tree=NULL;

    tree=add(tree,200);
    tree=add(tree,26);
    tree=add(tree,213);
    tree=add(tree,18);
    tree=add(tree,28);
    tree=add(tree,12);

    int count_dg = 0; 
    count_dg = count(tree, count_dg);

    printf("%d", count_dg);
}