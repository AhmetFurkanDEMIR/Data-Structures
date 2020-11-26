#include <stdio.h>
#include <stdlib.h>

// yapımız
typedef struct binary{

	char b;
	struct binary *next;

}bin;

bin * root, * iterator, *temp;

// tam kısmı ikilik tabana dönüştürme
// burada yığın veri yapısı yani baştan ekleme yapacağız. Ilk giren son çıkar.
void binary_tam(int tam){

    //tam kısım sıfır degilse girer. 
	if(tam!=0){

		// yığın bağlı listemiz.
	    root = (bin *)malloc(sizeof(bin));
	    root->next = NULL;

	    // tam sayı kısmının ikilik tabana çevrilmesi
	    while (tam){

	        if(tam % 2==0){

	            root->b = '0';

	        }

	        else{

	            root->b = '1';

	        }

	        iterator = (bin *)malloc(sizeof(bin));
	        iterator->next = root;
	        root = iterator;

	        tam /= 2; 
	    }

	    root = iterator->next;

	}

    // tam kısım sıfır ise girer.
    // yani 0.983 için bu şart bloguna girilir.
	else{

		root = (bin *)malloc(sizeof(bin));
		root->b = '0';
	    root->next = NULL;

	}

}

// sayinin ondalik kısmı icin
void binary_ondalik(double ondalik, int hassas){

    iterator=root;

    // son düğüme ulasmka icin.
    while(iterator->next!=NULL){

    	iterator=iterator->next;
    }

    // artik bastan ekleme yani yıgın veri yapısı yerine sondan ekleme yapacagiz.
    iterator->next = (bin *)malloc(sizeof(bin));
    iterator=iterator->next;
    // küsüratlı kısım oldugu icin '.' koyduk.
    iterator->b = '.';

    // kullanıcının girdiği hassasiyet kadar küsürat gösterilecek.
    while(hassas--){

        // sondan ekleme
    	iterator->next = (bin *)malloc(sizeof(bin));
    	iterator=iterator->next;

        // 2 yle çarp
        ondalik *= 2;

        // tam kısmını al 
        int fract_bit = ondalik; 
  
        if (fract_bit == 1) 
        {      
            // 1 ise virgülün sağındaki sayılar ile devam et.
            ondalik -= fract_bit; 
            iterator->b = '1';

        } 
        else{
            iterator->b = '0'; 
        }
    }

    iterator->next = NULL;

}

char *run(double n, int k){

	int tam = n,i=0, c=2;

    double ondalik = n - tam;
	
	binary_tam(tam);

    binary_ondalik(ondalik,k);

    char *a = (char *)malloc(c*sizeof(char));

    iterator = root;

    // verimiz deki 2 lik tabandaki sayıyı alıyoruz
    while(iterator!=NULL){

        *(a+i) = iterator->b;

        iterator=iterator->next;

        i+=1;

        if(c==i-1){
        	c = c * 2;
        	a = (char *)realloc(a, c*sizeof(char));
        }

    }

    free(root);
    free(iterator);
    free(temp);

    *(a+i) = '\0';
    
    // return a pointer
    return a;

}
