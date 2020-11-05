#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// bir kisinin birden fazla telefonu bu yapıda saklanacak.
typedef struct telefon{

    char tel_turu[20];
    char tel[11];

    struct telefon * next_no;
    struct telefon * back_no;

}tel;

// kartvizitteki kisiler

typedef struct Kartvizit{

    char ad_soyad[30];

    tel * next_no;
    tel * back_no;

    struct Kartvizit * next;
    struct Kartvizit * back;

}node;

// root ilk veri. iterator, ilk veriyi kaybetmeden verileri dolasacağımız degisken
//node *root, *iterator;

//iterator_tel, ilk tel veri. tela, ilk teli veriyi kaybetmeden telleri dolasacağımız degisken
tel * iterator_tel, * tela;

