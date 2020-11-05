#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "iostream"

#ifndef REHBER_H
#define REHBER_H

// bir kisinin birden fazla telefonu bu yapıda saklanacak.
typedef struct telefon{

    char tel_turu[20];
    char tel[11];

    telefon * next_no;
    telefon * back_no;

}tel;

// kartvizitteki kisiler

typedef struct Rehber{

    char ad_soyad[30];

    tel * next_no;

    Rehber * next;
    Rehber * back;

}node;

extern tel * iterator_tel, * tela;
extern node * root, * iterator;
extern int knt;
extern std::string dire;

#endif // REHBER_H
