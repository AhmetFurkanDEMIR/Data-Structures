#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 10

typedef struct n1{

    char data[30];
    struct n1 *next;

}node1;

typedef struct n{

    struct n1 *next[size];

}node;

node *root;


void init(int x){

	root = (node *)malloc(sizeof(node));

	int i=0;

	for(i=0;i<x;i++){

		root->next[i]=NULL;
	}

}

void hashing(char data[]){

	int i=0, boyut, top=0;

	for(i=0;data[i]!='\0';i++){

	}

	boyut = i;

	for(i=0;i<boyut;i++){

		top+= (int)data[i];

	}

	top = top%size;

	if(root->next[top]==NULL){
		
		root->next[top] = (node1 *)malloc(sizeof(node1));
		root->next[top]->next=NULL;
		strcpy(root->next[top]->data,data);

	}

	else{

		node1 *temp = (node1 *)malloc(sizeof(node1));

		temp->next = root->next[top];
		root->next[top] = temp;
		strcpy(root->next[top]->data,data);

	}
}

void search(char data[]){

	int i=0, boyut, top=0;

	for(i=0;data[i]!='\0';i++){

	}

	boyut = i;

	for(i=0;i<boyut;i++){

		top+= (int)data[i];

	}

	top = top%size;

	node1 *iterator = root->next[top];

	while(iterator!=NULL){

		if(strcmp(iterator->data,data)==0){

			printf("\n Veri bulundu : %s",data);
		}

		iterator=iterator->next;

	}
}


void delete(char data[]){

	int i=0, boyut, top=0;

	for(i=0;data[i]!='\0';i++){

	}

	boyut = i;

	for(i=0;i<boyut;i++){

		top+= (int)data[i];

	}

	top = top%size;

	if(strcmp(root->next[top]->data,data)==0){
		root->next[top]=root->next[top]->next;
	}

	else{

		node1 *iterator = root->next[top];

		while(iterator->next!=NULL){

			if(strcmp(iterator->next->data,data)==0){

				iterator->next = iterator->next->next;
			}

			iterator=iterator->next;

		}

	}
}

void print(){

	int i=0;

	for(i=0;i<size;i++){

		if(root->next[i]!=NULL){

			node1 *temp = root->next[i];

			while(temp!=NULL){
				printf("%s ",temp->data);
				temp=temp->next;
			}
		}
	}
}

int main(){

	init(size);

	hashing("ad");
	hashing("afdd");
	hashing("ad");
	hashing("afdsd");
	hashing("ahgfd");
	hashing("akjhd");
	hashing("akjhd");
	hashing("adfds");

	delete("ahgfd");
	delete("ad");
	delete("ad");

	print();
	search("afdsd");


    return 0;
}
