#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// yapi
typedef struct veri{ 

	char site_adres[30];

    struct veri *next;
    struct veri *tail;

}stack; 

// degisken
stack *root=NULL;
stack *iterator=NULL;
stack *temp = NULL;

// site islem
void site_islem(stack *temp, int a){

	system("cls");

	if(a==0){

		printf("\n\n Bir sonraki adrese gecilmistir.");

		printf(" - site adresi : %s", temp->site_adres);

		printf("\n\n Site icerigi :  Ahmet Furkan DEMIR");

	}

	else{

		printf("\n\n Bir Onceki adrese donulmustur.");

		printf(" - site adresi : %s", temp->site_adres);

		printf("\n\n Site icerigi : DEMIR Furkan Ahmet");
	}

	printf("\n\n Ana menuye donmek icin herhangi bir sayi giriniz : ");

	scanf("%d",&a);

}

// ekle
void site_ekle(){

	system("cls");

	printf("\n  --Firefox (Site ekle)--");

	printf("\n\n Yeni site adresi : ");

	if(root==NULL){

		root = (stack *)malloc(sizeof(stack));
        root->next = root;
        root->tail = root;

        scanf("%s",&root->site_adres);

        iterator = root;

	}

	else{

        temp = (stack *)malloc(sizeof(stack));
        temp->next = root;
        temp->tail = root->tail;
        root->tail->next = temp;
        root->tail = temp;

        root=temp;
        iterator = root;

        scanf("%s",&root->site_adres);

	}


}

void ileri(){

	system("cls");

	int temp;

	printf("\n  --Firefox (Ileri)--");

	if(root==NULL){
		printf("\n\n Herhangi bir adres bulamadim.");
		printf("\n\n Ana menuye donmek icin herhangi bir sayi giriniz : ");

		scanf("%d",&temp);
	}

	else{

		iterator=iterator->next;
		site_islem(iterator, 0);

	}

	

}

void geri(){

	system("cls");

	int temp;

	printf("\n  --Firefox (Geri)--");

	if(root==NULL){
		printf("\n\n Herhangi bir adres bulamadim.");

		printf("\n\n Ana menuye donmek icin herhangi bir sayi giriniz : ");

		scanf("%d",&temp);
		
	}

	else{

		iterator=iterator->tail;
		site_islem(iterator, 1);

	}

}

void suan(){

	system("cls");

	int temp;

	if(root==NULL){
		printf("\n\n Herhangi bir adres bulamadim.");

		printf("\n\n Ana menuye donmek icin herhangi bir sayi giriniz : ");

		scanf("%d",&temp);
		
	}
	else{

		printf("\n  --Firefox (Suanki site)--");

		printf("\n\n Suanki Site");

		printf(" - site adresi : %s", iterator->site_adres);

		printf("\n\n Site icerigi :  Ahmet Furkan DEMIR - Suan");

		printf("\n\n Ana menuye donmek icin herhangi bir sayi giriniz : ");

		scanf("%d",&temp);

	}


}

int main(){

	int secim;

	while(1){

		system("cls");

		printf("\n  --Firefox--");

		printf("\n\n 1-) Yeni site adresi ");
		printf("\n 2-) Suanki site ");
		printf("\n 3-) Ileri tusu ");
		printf("\n 4-) Geri tusu ");
		printf("\n   Secim : ");

		scanf("%d",&secim);

		switch(secim){

			case 1:

				site_ekle();
				break;

			case 2:
				suan();
				break;

			case 3:
				ileri();
				break;

			case 4:
				geri();
				break;


		}

	}


	return 0;
}