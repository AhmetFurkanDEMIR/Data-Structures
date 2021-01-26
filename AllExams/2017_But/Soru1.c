#include <stdio.h>
#include <stdlib.h>

typedef struct n{

    int data;
    struct n * next;

}node;

node *head;

node *ekle(node *root, int data){

	node *iterator=NULL;

	if(root==NULL){

		root = (node *)malloc(sizeof(node));
		root->next=NULL;
		root->data = data;

	}

	else{

		iterator = root;

		while(iterator->next!=NULL){
			iterator=iterator->next;
		}
		
		
		iterator->next = (node *)malloc(sizeof(node));
		iterator = iterator->next;
		iterator->next = NULL;
		iterator->data = data;


	}

	return root;

}

void listele(node *root){

	node *iterator=NULL;

	if (root == NULL){
        return; 
    }

	iterator = root;


	while(iterator!=NULL){

		printf("%d ",iterator->data);
		iterator = iterator->next;

	}

}

node *reverse(node* nodea){

    if (nodea == NULL) 
        return NULL; 
    if (nodea->next == NULL) { 
        head = nodea; 
        return nodea; 
    } 
    node *node1 = reverse(nodea->next); 
    node1->next = nodea; 
    nodea->next = NULL; 
    return nodea; 
} 


int main(){

	node *root=NULL;

	int data[] = {8,9,6,5,4,32,65};
	int i=0;

	for(i=0;i<sizeof(data)/sizeof(data[0]);i++){
		root = ekle(root,data[i]);
	}

	printf("Kullanıcının verisi : ");
	listele(root);

	root = reverse(root);

	printf("\n\nTers hali : ");
	listele(head);
	

	printf("\n\n");
	return 0;
}

