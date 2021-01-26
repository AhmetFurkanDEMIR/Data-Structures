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
	
	int i=0;
	node * tree=NULL;

	int A[] = {61,109,149,111,34,2,24,119,122,125,27,145};
	int B[] = {122,61,2,34};

	for(i=0;i<sizeof(A)/sizeof(A[0]);i++){

		tree=add(tree,A[i]);

	}

	printf("agacın ilk durumu : ");
    iter(tree);

	printf("\n\n");

	for(i=0;i<sizeof(B)/sizeof(B[0]);i++){

		tree=remove0(tree,B[i]);
		
	}

	printf("agacın son durumu : ");
    iter(tree);

	printf("\n");

}