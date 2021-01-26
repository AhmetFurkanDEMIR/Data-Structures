#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct Kitaplik{

    char KitapAdi[20];
    int ISBN;

    struct Kitaplik *next;
    struct Kitaplik *tail;

}node;

node *root=NULL, *iterator=NULL;

node *yer_belirle(char *KitapAdi){

    node *temp;

    iterator=root->tail;

    int sn = strcmp(root->KitapAdi, KitapAdi), c=0;

    if(sn>=0){

        iterator->next=(node *)malloc(sizeof(node));
        iterator->next->tail = iterator;
        iterator->next->next=root;
        root->tail=iterator->next;
        root=iterator->next;

        return root;
    }

    iterator=root;

    while(1){

        if(iterator->next==root){
            c=1;
            break;
        }

        sn = strcmp(iterator->next->KitapAdi, KitapAdi);
        if(sn>=0){

            c=0;
            break;
        }

        iterator=iterator->next;
    }

    if(c==1){

        iterator->next=(node *)malloc(sizeof(node));
        iterator->next->tail = iterator;
        iterator->next->next=root;
        root->tail=iterator->next;

    }

    else{

        temp = iterator->next;
        iterator->next = (node *)malloc(sizeof(node));
        iterator->next->tail = iterator;
        iterator->next->next = temp;
        temp->tail = iterator->next;
    }

    return iterator->next;

}

void add(char KitapAdi[], int ISBN){

    if(root==NULL){

        root = (node *)malloc(sizeof(node));
        root->next = root;
        root->tail = root;

        memcpy(root->KitapAdi, KitapAdi,20);
        root->ISBN = ISBN;

    }


    else{

        iterator = yer_belirle(KitapAdi);

        memcpy(iterator->KitapAdi, KitapAdi ,20);
        iterator->ISBN = ISBN;

    }

}


void swap(node *a, node *b){

    char KitapAdi_temp[20];
    strcpy(KitapAdi_temp, a->KitapAdi);
    strcpy(a->KitapAdi, b->KitapAdi);
    strcpy(b->KitapAdi, KitapAdi_temp);

    int temp = a->ISBN;
    a->ISBN = b->ISBN;
    b->ISBN = temp;

}

void sirala(){

    int swapped, i; 
    node *ptr1; 

    if(root==NULL){
        return; 
    }

    do{ 
        swapped = 0; 
        ptr1 = root; 
  
        while(ptr1->next != root){ 
            
            if(ptr1->ISBN < ptr1->next->ISBN){

                swap(ptr1, ptr1->next); 
                swapped = 1; 
            }

            ptr1 = ptr1->next; 
        } 

    }while(swapped);

}

int main(){

    add("ab",80);
    add("zaa",60);
    add("asd",80);
    add("dsa",1);
    add("gfd",1000);

    iterator = root;
    int i=1;

    printf("\n -- Alfabetik olarak kitap ekleme sonucunda olusan cift yonlu dairesel bagli liste : --\n\n");
    do{

        printf(" (%d. Kitab adi : %s, Kitap ISBN : %d)\n",i,iterator->KitapAdi, iterator->ISBN);

        iterator = iterator->next;
        i+=1;

    }while(iterator!=root);

    iterator = root;
    i=1;

    sirala();

    printf("\n\n -- ISBN siralamasina gore olusan cift yonlu dairesel bagli liste : --\n\n");
    do{

        printf(" (%d. Kitab adi : %s, Kitap ISBN : %d)\n",i,iterator->KitapAdi, iterator->ISBN);

        iterator = iterator->next;
        i+=1;

    }while(iterator!=root);


    return 1;
}