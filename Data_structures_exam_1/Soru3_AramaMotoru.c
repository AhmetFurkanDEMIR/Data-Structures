#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct veri{ 

    char kelime[10];
    int adetV; 
    struct veri *next;
    struct veri *tail;

}Node; 


Node *root=NULL, *iterator, *tempa;
int adet = 0;

void swap(Node *a, Node *b){

    char kelime[10];
    strcpy(kelime, a->kelime);
    strcpy(a->kelime, b->kelime);
    strcpy(b->kelime, kelime);

	int temp = a->adetV;
	a->adetV = b->adetV;
	b->adetV = temp;

}

void sirala(){

	if(root==NULL){
        return; 
    }

	int swapped, i, sn; 
    Node *ptr1; 
    Node *lptr = NULL; 

    do{ 
        swapped = 0; 
        ptr1 = root; 
  
        do{
            
            if(ptr1->adetV<ptr1->next->adetV){

                swap(ptr1, ptr1->next); 
                swapped = 1; 
            }

            ptr1 = ptr1->next;

        }while(ptr1->next!=root);

        lptr = ptr1; 

    }while(swapped);


}

void ekle(char a[]){

	int i = 0, kn=0;

	if(adet<=20){

		if(adet==0){

			root=(Node *)malloc(sizeof(Node));
			root->next = root;
			root->tail = root;
			strcpy(root->kelime, a);
			adet+=1;
			root->adetV += 1;

		}

		else{

			iterator = root;

			do{

				if(strcmp(iterator->kelime,a)==0){

					kn = 1;
					break;
				}

				iterator=iterator->next;

			}while(iterator!=root);

			if(kn==0){

				iterator = root->tail;

				tempa = (Node *)malloc(sizeof(Node));
				iterator->next = tempa;
				tempa->next=root;
				root->tail=tempa;
				strcpy(tempa->kelime, a);
				adet+=1;
				tempa->adetV += 1;

			}

			else if(kn==1){
				iterator->adetV += 1;
				adet+=1;
			}

		}
	}

	else{
		printf("Dolu\n");
	}

	sirala();


}

int main(){


	ekle("fdsa");
	ekle("fdsa");
	ekle("fdsa");
	ekle("fdsc");
	ekle("fdsv");
	ekle("fdsvdsa");
	ekle("fdsvdsa");
	ekle("fdsv");
	ekle("fdsv");
	ekle("fdsvdsa");
	ekle("fdsvdsa");
	ekle("fdsvdsa");
	ekle("fdsvdsa");


	iterator=root;
	
	do{

		printf("Kelime : %s\n", iterator->kelime);
		printf("Adet : %d\n", iterator->adetV);
		printf("\n\n");
		iterator=iterator->next;

	}while(iterator!=root);


}