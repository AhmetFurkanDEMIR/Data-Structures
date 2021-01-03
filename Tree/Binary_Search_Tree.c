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

void iter(node *tree){

    if(tree == NULL){
        return;
    }

    printf("%d ",tree->data);    
    iter(tree->right);
    iter(tree->left);
}

int search(node * tree, int x){

    if(tree == NULL){
        return -1;
    }

    if(tree->data == x){
        return 1;
    }

    if(search(tree->right,x)==1){
        return 1;
    }

    if(search(tree->left,x)==1){
        return 1;
    }

    return -1;
}

int max(node *tree){

    while(tree->right!=NULL){
        tree=tree->right;
    }

    return tree->data;
}
int min(node *tree){

    while(tree->left!=NULL){
        tree=tree->left;
    }

    return tree->data;
}

node *remove0(node *tree,int x){

    if(tree==NULL){
        return NULL;
    }

    if(tree->data == x){

        if(tree->left==NULL && tree->right==NULL){
            return NULL;
        }

        if(tree->right!=NULL){

            tree->data = min(tree->right);
            tree->right = remove0(tree->right, min(tree->right));
            return tree;
        }

        tree->data = max(tree->left);
        tree->left = remove0(tree->left,max(tree->left));
        return tree;
    }

    if(tree->data < x){

        tree->right = remove0(tree->right,x);
        return tree;
    }

    tree->left= remove0(tree->left,x);
    return tree;

}

int main(){

    node * tree=NULL;

    tree=add(tree,56);
    tree=add(tree,200);
    tree=add(tree,26);
    tree=add(tree,213);
    tree=add(tree,18);
    tree=add(tree,28);
    tree=add(tree,12);

    iter(tree);

    printf(",search result : %d ",search(tree,24));
    printf(",max = %d , min = %d, ",max(tree),min(tree));
    
    tree= remove0(tree,56);
    iter(tree);
}

