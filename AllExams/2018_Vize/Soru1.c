#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Linux/Unix = clear
// Windows = cls
#define clear() system("clear");


typedef struct n{

    int basim;
    int ISBN;
    struct n * next;

}node;


node *yer_belirle(node *root, int basim, int ISBN){

    node *iterator = root;
    node *temp;
    int c=0;

    if(root->basim > basim){

        do{

            iterator=iterator->next;

        }while(iterator->next!=root);

        temp = (node *)malloc(sizeof(node));
        iterator->next=temp;
        temp->next=root;
        root=temp;
        root->basim = basim;
        root->ISBN = ISBN;
    }

    else{


        while(1){

            if(iterator->next==root){
                c=1;
                break;
            }

            if(iterator->next->basim > basim){

                c=0;
                break;
            }

            iterator=iterator->next;
        }

        if(c==1){

            temp = (node *)malloc(sizeof(node));
            temp->basim = basim;
            temp->ISBN = ISBN;
            iterator->next=temp;
            temp->next=root;    

        }

        else{

            temp = iterator->next;
            iterator->next = (node *)malloc(sizeof(node));
            iterator->next->basim = basim;
            iterator->next->ISBN = ISBN;
            iterator->next->next = temp;
        }


    }

    return root;

}


node *ekle(node *root, int basim, int ISBN){

    node *iterator;

    if(root==NULL){

        root = (node *)malloc(sizeof(node));
        root->next=root;
        root->basim = basim;
        root->ISBN = ISBN;

        return root;

    }

    else{

        root = yer_belirle(root, basim, ISBN);

        return root;

    }

}

int sila(node *root, int ISBN){

    int asd=0;

    node *iterator;
    node *temp = root, *back;

    iterator=root;

    if(root->next==root && root->ISBN==ISBN){

        free(root);
        root=NULL;
        asd=1;
        return asd;
    }

    while(iterator->next!=root){

        iterator=iterator->next;

    }

    while(temp->ISBN==ISBN){

        iterator->next=root->next;
        root = root->next;
        free(temp);
        temp = root;

        asd=1;

        if(temp->next==root){
            
            if(temp->ISBN==ISBN){
                
                free(root);
                root=NULL;
                asd=1;
            }

            return asd;
        }
    }

    while(1){

        while (temp->ISBN!=ISBN){

            back = temp;
            temp = temp->next;

            if(temp==root){
                break;
            }
        }

        if (temp == root){
            return asd;
        }

        back->next = temp->next;
        free(temp);
        temp = back->next;

        asd=1;

        if(temp->next==root){

            if(temp->ISBN==ISBN){
                
                back->next=root;
                free(temp);

                asd=1;
            }

            break;

        }
    }

    return asd;

}

int main(){

    node *root=NULL, *iterator=NULL;

    root = ekle(root, 8, 20);
    root = ekle(root, 10, 40);
    root = ekle(root, 20, 80);
    root = ekle(root, 90, 70);
    root = ekle(root, -5, 90);
    root = ekle(root, 3, 10);

    sila(root, 10);

    iterator = root;

    do{

        printf("%d ",iterator->basim);
        iterator=iterator->next;

    }while(iterator!=root);

    return 0;
}
