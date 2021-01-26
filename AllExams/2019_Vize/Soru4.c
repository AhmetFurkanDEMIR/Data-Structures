#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Linux/Unix = clear
// Windows = cls
#define clear() system("clear");


typedef struct n{

    int data;
    struct n * next;

}node;




node *ekle(node *root, int data){

    node *iterator;

    if(root==NULL){

        root = (node *)malloc(sizeof(node));
        root->next=root;
        root->data = data;

        return root;

    }

    else{


        node *tempa;
        iterator = root;

        while(iterator->next!=root){

            iterator=iterator->next;

        }

        tempa = (node *)malloc(sizeof(node));
        // sondan dairesel baglı liste
        iterator->next = tempa;
        tempa->next=root;
        tempa->data = data;

        return root;

    }

}

int coun(node *root, node *iterator, int count){


    if(iterator->next==root){
        return count+1;
    }

    count += 1;

    count = coun(root, iterator->next, count);

    return count;

}


int main(){

    node *root=NULL, *iterator=NULL;

    root = ekle(root, 8);
    root = ekle(root, 10);
    root = ekle(root, 20);
    root = ekle(root, 90);
    root = ekle(root, -5);
    root = ekle(root, 3);


    int count = 0;
    count = coun(root, root, count);

    printf("\n\n %d",count);

    return 0;
}
