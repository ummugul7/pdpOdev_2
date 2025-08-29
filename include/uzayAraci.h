/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
#include "zaman.h"
#include "gezegen.h"
#include <stdbool.h>
#ifndef UZAYARACI_H
#define UZAYARACI_H

typedef struct UzayAraci* uzayAraci;
struct UzayAraci
{
    char ad[30];
    char cikisGezegeni[30];
    char varisGezegeni[30]; 
    char uzayAraciDurumu[10]; // uzay aracının durumu yolda, bekliyor, vardi,imha
    int kalanYolculukSuresi; // yolculuk süresi
    int uzayAraciNufusu ; // uzay aracının nüfusu
    Zaman cikisTarihi; // yolculuk tarihi
    bool yolda ,vardi,bekliyor; // uzay aracının durumu yolda, bekliyor, vardi,imha
    Zaman varisTarihi;
     
    
    void (*uzayAraciYokEt)( uzayAraci);
    void (*tarihKontrolEt)(uzayAraci u,gezegen* gezegenler, int gezegenSayisi);
    void (*uzayAraciMesafeKontrolu)(uzayAraci uzayaraci,gezegen* gezegenler,int gezegensayisi);
    void (*imhaMi)(uzayAraci u );
    bool (*donguKontrol)( uzayAraci *uzayAraci, int uzayaracisayisi);
    void (*varisTarihiHesapla)(uzayAraci u, gezegen * gezegenler,int gezegenSayisi);
};
// uzay aracı için kurucu fonksiyon
uzayAraci uzayaraciOlustur(char * ad , char * cikisGezegeni, char * varisGezegeni, int kalanYolculukSuresi, Zaman cikisTarihi);

// uzay aracının yıkıcı fonksiyonu 
void uzayAraciYokEt( uzayAraci);

// uzay aracının çıkış tarihinin gezegenin tarihine eşit olup olmadıgına bakar
void tarihKontrolEt(uzayAraci u,gezegen* gezegenler, int gezegenSayisi); 

// uzay aracının zaman olarak ne kadar mesafesi kaldıgını hesaplar
void uzayAraciMesafeKontrolu(uzayAraci uzayaraci,gezegen* gezegenler,int gezegensayisi);

// uzay aracını imha olup olmadıgının atama işlemini yapar
void imhaMi(uzayAraci u ); 
// tum araçlar vari veya imha değilse dongunun tekrar etmesini sağlar 
bool donguKontrol( uzayAraci *uzayAraci, int uzayaracisayisi);

// uzay aracının varis tarihini hesaplar
void varisTarihiHesapla(uzayAraci u, gezegen * gezegenler,int gezegenSayisi); // varış tarihini hesapla
#endif