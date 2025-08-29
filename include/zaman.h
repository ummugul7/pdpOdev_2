/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
#include <stdbool.h>
#ifndef ZAMAN_H
#define ZAMAN_H

typedef struct Zaman* Zaman;

struct Zaman {
    int gun;
    int ay;
    int yil;
    int saat;
    int gezegen_gun_saat;
    char tarih_str[20];

    void (*ilerisaat)(Zaman);
  
    char* (*zaman_to_string)(Zaman, char*, int);
    void (*zamandelete)(Zaman);
    Zaman (*gunileri)(Zaman, int);
 
};

// Fonksiyon prototipleri
Zaman zaman_olustur(const char *tarih_str, int gezegen_gun_saat);
void ilerisaat(Zaman zaman);
void zamandelete(Zaman zaman);
Zaman gunileri(Zaman zaman, int gun_sayisi);
bool zamanKarsilastir(Zaman zaman1, Zaman zaman2); // iki zamanı karşılaştırır
int ayGunSayisi(int ay);
void zamanyazdir(const Zaman z);
int zamanFarki(Zaman z1, Zaman z2);


#endif
