#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// beyaz
#define KNRM  "\x1B[0m"

// kırmızı
#define KRED  "\x1B[31m"

// yesil
#define KGRN  "\x1B[32m"

// turuncu
#define KYEL  "\x1B[33m"

// mavi
#define KBLU  "\x1B[34m"

// turkuaz
#define KCYN  "\x1B[36m"

// Linux/Unix = clear
// Windows = cls
#define clear() system("clear");

// Veri, struct
typedef struct Ogr{

	int ogr_no;
	char ad[20];
	char soy_ad[20];
	char tc[11];
	int yas;
	int sinif;
	int ders_sayi;
	Ogr * next;

}node;

// ilk veriyi tutan gösterici
node *root, *iterator;

// programdaki toplam veri sayısı
int kn=0;

// ogrenci numarasi bagimsizmi diye kontrol eder.
int ogr_kn(int kn_no){

	iterator = root;

	while(iterator!=NULL){

		if(iterator->ogr_no==kn_no){
			return 1;
		}

		iterator = iterator->next;

	}

	return 0;

}

// yeni ogrenci ekleme.
// ilk defa veri ekleniyorsa her zaman bu fonksiyona gelinir.
// burada eklenen veriler baştan eklenir ve sıralamaya dikkat edilmez.
void ekle(){

	if(kn==0){

		int ogr_n, temp;

		clear();
		printf("\n\n%s  --- NEU Ogrenci Sistemi (Ogrenci Ekle) ---\n%s",KBLU, KNRM);
		printf("\n\n%s   Ogrenci No (Bagimsiz olmali) : ",KGRN);
		scanf("%d",&ogr_n);

		kn+=1;
		root = (node *)malloc(sizeof(node));
		root->next=NULL;
		root->ogr_no=ogr_n;

		printf("\n%s   Ogrenci Adi : ",KCYN);
		scanf("%s",&root->ad);

		printf("\n%s   Ogrenci Soyadi : ",KGRN);
		scanf("%s",&root->soy_ad);

		printf("\n%s   Ogrenci T.C No : ",KCYN);
		scanf("%s",&root->tc);

		printf("\n%s   Ogrenci Yasi : ",KGRN);
		scanf("%d",&root->yas);

		printf("\n%s   Ogrenci Kacinci Sinif : ", KCYN);
		scanf("%d",&root->sinif);

		printf("\n%s   Ogrencinin Aldigi Ders Sayisi : ",KGRN);
		scanf("%d",&root->ders_sayi);

		printf("\n\n%s    Ogrenci basari ile eklendi Ana menü icin 1'e basınız : %s",KYEL);
		scanf("%d",&temp);
		printf("%s\n", KNRM);

	}

	else{

		int ogr_n, tempa;

		clear();
		printf("\n\n%s  --- NEU Ogrenci Sistemi (Ogrenci Ekle) ---\n%s",KBLU, KNRM);
		printf("\n\n%s   Ogrenci No : ", KGRN);
		scanf("%d",&ogr_n);

		int kna = ogr_kn(ogr_n);

		node *temp;

		if(kna==0){			

			temp = (node *)malloc(sizeof(node));
			kn += 1;
			temp->next=root;
			root=temp;
			root->ogr_no=ogr_n;
		}

		else{

			printf("\n\n%s    Bu ogrenci no baska bir ogrenciye ait, Ana menü icin 1'e basınız : ",KRED);
			scanf("%d",&tempa);
			printf("%s\n", KNRM);
			return;
		}

		printf("\n%s   Ogrenci Adi : ", KCYN);
		scanf("%s",&root->ad);

		printf("\n%s   Ogrenci Soyadi : ", KGRN);
		scanf("%s",&root->soy_ad);

		printf("\n%s   Ogrenci T.C No : ", KCYN);
		scanf("%s",&root->tc);

		printf("\n   Ogrenci Yasi : ", KGRN);
		scanf("%d",&root->yas);

		printf("\n%s   Ogrenci Kacinci Sinif : ", KCYN);
		scanf("%d",&root->sinif);

		printf("\n%s   Ogrencinin Aldigi Ders Sayisi : ", KGRN);
		scanf("%d",&root->ders_sayi);
		printf("%s", KNRM);

		printf("\n\n%s    Ogrenci basari ile eklendi Ana menü icin 1'e basınız : %s",KYEL);
		scanf("%d",&tempa);
		printf("%s\n", KNRM);


	}


}

// ogrenci numarası girilen veri silinir.
void sila(int kn_no){

	int kont = 0;
	iterator=root;
	node *temp, *sk;

	if(root->ogr_no==kn_no){

		temp = root;
		root=root->next;
		free(temp);
		kn -= 1;
	}

	else{

		while(1){

			if(iterator->next->ogr_no==kn_no){

				break;
			}

			iterator=iterator->next;
		}


		temp = iterator->next;
		iterator->next = iterator->next->next;
		free(temp);

		kn -= 1;
					
	}
}

// ogrenci numarası kontrol edilir ve sila fonksiyonuna ilelernip, ogrenci silinir.
void sil(){

	if (root == NULL){
        return; 
    }

	int sl_no, tempb;

	clear();
	printf("\n\n%s  --- NEU Ogrenci Sistemi (Ogrenci Sil) ---\n%s",KBLU, KNRM);
	printf("\n\n%s   Silinecek Ogrenci No : ",KRED);
	scanf("%d",&sl_no);

	int knaa = ogr_kn(sl_no);

	if(knaa==1){
		sila(sl_no);
		printf("\n\n%s    Ogrenci basari ile silindi, Ana menü icin 1'e basınız : ",KYEL);
		scanf("%d",&tempb);
		printf("%s\n", KNRM);

	}
	else{
		
		printf("\n\n%s    Silinecek Ogrenci NO bulunamadi, Ana menü icin 1'e basınız : %s",KRED);
		scanf("%d",&tempb);
		printf("%s\n", KNRM);

	}

}

// ogrencileri bastan sona listeler.
// ilk yazılan veri en sonuncu veri olur.
void listele(){

	if (root == NULL){
        return; 
    }

	iterator = root;
	int temp;

	clear();
	printf("\n\n%s  --- NEU Ogrenci Sistemi (Listele) ---\n%s",KBLU, KNRM);

	while(iterator!=NULL){

		printf("\n%s    Ogrenci No : %d\n",KGRN, iterator->ogr_no);
		printf("\n%s    Ogrenci Ad : %s \n",KCYN, iterator->ad);
		printf("\n%s    Ogrenci Soyad : %s \n",KGRN, iterator->soy_ad);
		printf("\n%s    Ogrenci T.C. No : %s \n",KCYN, iterator->tc);
		printf("\n%s    Ogrenci Yas: %d \n",KGRN, iterator->yas);
		printf("\n%s    Ogrenci Sinif : %d \n",KCYN, iterator->sinif);
		printf("\n%s    Ogrenci Ders sayisi : %d \n",KGRN, iterator->ders_sayi);

		printf("\n\n%s -----------------------------\n%s",KBLU,KNRM);

		iterator = iterator->next;


	}

	printf("\n\n%s    Ana menüye dönmek için 1' e basınız : %s", KYEL);
	scanf("%d",&temp);
	printf("%s\n", KNRM);

}

// iki verideki degerleri birbiri ile degistirir.
void swap(node *a, node *b){

	int temp_ogr_no = a->ogr_no;
    a->ogr_no = b->ogr_no; 
    b->ogr_no = temp_ogr_no;

    char temp_ad[20];
    strcpy(temp_ad, a->ad);
    strcpy(a->ad, b->ad);
    strcpy(b->ad, temp_ad);

	char temp_soy_ad[20];
    strcpy(temp_soy_ad, a->soy_ad);
    strcpy(a->soy_ad, b->soy_ad);
    strcpy(b->soy_ad, temp_soy_ad);

    char temp_tc[11];
    strcpy(temp_tc, a->tc);
    strcpy(a->tc, b->tc);
    strcpy(b->tc, temp_tc);

    int temp_yas = a->yas;
    a->yas = b->yas; 
    b->yas = temp_yas;

    int temp_sinif = a->sinif;
    a->sinif = b->sinif; 
    b->sinif = temp_sinif;

    int temp_ders_sayi = a->ders_sayi;
    a->ders_sayi = b->ders_sayi; 
    b->ders_sayi = temp_ders_sayi;

}

// tüm verileri buyukten kucuge siralama islemi yapar.
void sirala(int knaaa){

	int swapped, i; 
    node *ptr1; 
    node *lptr = NULL; 

    if(root==NULL){
        return; 
    }

    do{ 
        swapped = 0; 
        ptr1 = root; 
  
        while(ptr1->next != lptr){ 
            
            if(ptr1->ogr_no < ptr1->next->ogr_no){

                swap(ptr1, ptr1->next); 
                swapped = 1; 
            }

            ptr1 = ptr1->next; 
        } 

        lptr = ptr1; 

    }while(swapped);

    if(knaaa == 0){

    	listele();
    }
}

// pointer türünde node veri tipi döndüren fonk.
// girilen ogrenci numarasına göre uygun bir yer bulunur ve o kısıma yeni veri oluşturulur.
node *yer_belirle(int kn_no){

	iterator = root;
	node *temp;

	if(root->ogr_no<=kn_no){

		temp = (node *)malloc(sizeof(node));
		temp->next=root;
		root=temp;

		return root;
	}

	int i=0;

	while(1){

		i++;

		if(i==kn-1){
			break;
		}

		if(iterator->next->ogr_no<kn_no){

			break;
		}

		iterator=iterator->next;
	}

	temp = iterator->next;
	iterator->next = (node *)malloc(sizeof(node));
	iterator->next->next = temp;

	return iterator->next;


}

// ogrenci numara sırasına göre yeni veri eklenir.
void sirali_ekle(){

	sirala(1);

	int ogr_n, tempa;

	clear();

	printf("\n\n%s  --- NEU Ogrenci Sistemi (Sirali Ogrenci Ekle) ---\n%s",KBLU, KNRM);
	printf("\n\n%s   Ogrenci No : ",KGRN);
	scanf("%d",&ogr_n);

	int kna = ogr_kn(ogr_n);

	node *temp;

	if(kna==0){

		kn += 1;
		
		}

	else{

		printf("\n\n%s    Bu ogrenci no baska bir ogrenciye ait, Ana menü icin 1'e basınız : ",KRED);
		scanf("%d",&tempa);
		printf("%s\n", KNRM);
		return;
	}

	node *yeni = yer_belirle(ogr_n);

	yeni->ogr_no = ogr_n;

	printf("\n%s   Ogrenci Adi : ",KCYN);
	scanf("%s",&yeni->ad);

	printf("\n%s   Ogrenci Soyadi : ",KGRN);
	scanf("%s",&yeni->soy_ad);

	printf("\n%s   Ogrenci T.C No : ",KCYN);
	scanf("%s",&yeni->tc);

	printf("\n%s   Ogrenci Yasi : ",KGRN);
	scanf("%d",&yeni->yas);

	printf("\n%s   Ogrenci Kacinci Sinif : ",KCYN);
	scanf("%d",&yeni->sinif);

	printf("\n%s   Ogrencinin Aldigi Ders Sayisi : ",KGRN);
	scanf("%d",&yeni->ders_sayi);
	
	printf("\n\n%s    Ogrenci basari ile eklendi Ana menü icin 1'e basınız : %s",KYEL);
	scanf("%d",&tempa);
	printf("%s\n", KNRM);


}

// istenilen ogrenci numarası ile ogrencinin biligileri yazdirilir.
void araa(){

	if (root == NULL){
        return; 
    }

	int ogr_n, tempa;
	int knaa=2;

	iterator = root;

	clear();
	printf("\n\n%s  --- NEU Ogrenci Sistemi (Ogrenci Ara) ---",KBLU);
	printf("\n\n%s   Ogrenci No : ",KYEL);
	scanf("%d",&ogr_n);

	if(iterator->ogr_no==ogr_n){

		knaa=5;

		clear();
		printf("\n\n%s  --- NEU Ogrenci Sistemi ---\n%s",KBLU, KNRM);

		printf("\n%s    Ogrenci No : %d\n",KGRN, iterator->ogr_no);
		printf("\n%s    Ogrenci Ad : %s \n",KCYN, iterator->ad);
		printf("\n%s    Ogrenci Soyad : %s \n",KGRN, iterator->soy_ad);
		printf("\n%s    Ogrenci T.C. No : %s \n",KCYN, iterator->tc);
		printf("\n%s    Ogrenci Yas: %d \n",KGRN, iterator->yas);
		printf("\n%s    Ogrenci Sinif : %d \n",KCYN, iterator->sinif);
		printf("\n%s    Ogrenci Ders sayisi : %d \n",KGRN, iterator->ders_sayi);

		printf("\n\n%s      Ana menü icin 1'e basınız : ",KYEL);
		scanf("%d",&tempa);
		printf("%s\n", KNRM);
		
	}

	else{

		while(iterator->next!=NULL){

			if(iterator->next->ogr_no==ogr_n){
				knaa=1;
				break;
			}

			iterator=iterator->next;

		}

	}

	if(knaa==1){

		clear();
		printf("\n\n%s  --- NEU Ogrenci Sistemi ---\n%s",KBLU, KNRM);

		printf("\n%s    Ogrenci No : %d\n",KGRN, iterator->next->ogr_no);
		printf("\n%s    Ogrenci Ad : %s \n",KCYN, iterator->next->ad);
		printf("\n%s    Ogrenci Soyad : %s \n",KGRN, iterator->next->soy_ad);
		printf("\n%s    Ogrenci T.C. No : %s \n",KCYN, iterator->next->tc);
		printf("\n%s    Ogrenci Yas: %d \n",KGRN, iterator->next->yas);
		printf("\n%s    Ogrenci Sinif : %d \n",KCYN, iterator->next->sinif);
		printf("\n%s    Ogrenci Ders sayisi : %d \n",KGRN, iterator->next->ders_sayi);

		printf("\n\n%s      Ana menü icin 1'e basınız : %s",KYEL);
		scanf("%d",&tempa);
		printf("%s\n", KNRM);


		
	}
	else if(knaa==2){
		
		printf("\n\n%s    Ogrenci NO bulunamadi, Ana menü icin 1'e basınız : ",KRED);
		scanf("%d",&tempa);
		printf("%s\n", KNRM);

	}

}

// main.
int main(){

	while(1){

		int secim;
		int temp;
		int knaaa = 0;

		clear();

		printf("\n\n%s  --- NEU Ogrenci Sistemi ---",KBLU);
		printf("\n\n%s   1-) Ogrenci Ekle", KGRN);
		printf("\n%s   2-) Sirali Ogrenci Ekle", KCYN);
		printf("\n%s   3-) Ogrenci Sil",KGRN);
		printf("\n%s   4-) Listele",KCYN);
		printf("\n%s   5-) Sirali Listele",KGRN);
		printf("\n%s   6-) Ogrenci Ara",KCYN);
		printf("\n%s   7-) Quit",KGRN);

		printf("\n\n%s     Secim : ",KYEL);
		scanf("%d",&secim);
		printf("%s",KNRM);

		switch(secim){


			case 1:
				ekle();
				break;

			case 2:

				if(kn==0){

					ekle();
				}

				else{

					sirali_ekle();
				}

				break;

			case 3:
				sil();
				break;

			case 4:
				listele();
				break;

			case 5:
				knaaa = 0;
				sirala(knaaa = 0);
				break;

			case 6:
				araa();
				break;

			case 7:
				system("clear");
				return 1;
				break;

			default:
				printf("\n\n%s    Hatali islem, Ana menüye donmek icin 1'e basınız, Çıkmak için 2'ye basınız : ",KNRM);
				scanf("%d",&temp);
				printf("%s\n", KNRM);

				if(temp==2){
					
					system("clear");
					return 0;
				}
		}

	}

	printf("\n\n");
	return 0;
}

