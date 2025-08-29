/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
#ifndef KISI_H
#define KISI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gezegen.h"
#include "uzayAraci.h"

struct kisi
{  
    char ad[30];
    int yas;
    float kalanOmur;
    char uzayAraciAdi[30];
    char durumu[20];
    int olduMu; // kisinin ölüp ölmediğine bakar 
   // yapının içerisinde fonksiyon yazamam ama fonksiyon göstericisi yazabilirim 
   void (*KisiYokEt)(struct kisi*);
   void (*kisiYasGuncelle)(struct kisi*,uzayAraci *u,int uzayAraciSayisi,gezegen *gezegenListesi,int gezegenSayisi);
   void(*uzayAraciNufusuHesapla)(struct kisi*,uzayAraci * u ,int uzayAraciSayisi);
};
typedef struct kisi* Kisi;

Kisi KisiOlustur(const char* ad, int yas, double kalanOmur, const char* uzayAraciAdi);
void KisiYokEt(Kisi k);
void kisiYasGuncelle(Kisi k,uzayAraci *u,int uzayAraciSayisi,gezegen *gezegenListesi,int gezegenSayisi);
void uzayAraciNufusuHesapla(Kisi k,uzayAraci * u ,int uzayAraciSayisi); // uzay aracının nüfusunu hesapla
void kisiGuncelle(Kisi k,uzayAraci *u,int uzayAraciSayisi,gezegen *gezegenListesi,int gezegenSayisi); // kişilerin 

#endif