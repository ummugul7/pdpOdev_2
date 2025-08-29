/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
#include "zaman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ayGunSayisi(int ay) {
    switch (ay) {
        case 1: return 31; // Ocak
        case 2: return 28; // Şubat
        case 3: return 31; // Mart
        case 4: return 30; // Nisan
        case 5: return 31; // Mayıs
        case 6: return 30; // Haziran
        case 7: return 31; // Temmuz
        case 8: return 31; // Ağustos
        case 9: return 30; // Eylül
        case 10: return 31; // Ekim
        case 11: return 30; // Kasım
        case 12: return 31; // Aralık
        default: return 30; // Hata varsa varsayılan
    }
}

// her bir zaman nesnesi için tarih ilerletir
 void ilerisaat(Zaman z) {
     z->saat++;  
    if (z->saat >= z->gezegen_gun_saat) {
        z->saat = 0;
        z->gun++;

        int gun_sayisi = ayGunSayisi(z->ay); // Doğru gün sayısını al
        
        if (z->gun > gun_sayisi) {
            z->gun = 1;
            z->ay++;
            if (z->ay > 12) {
                z->ay = 1;
                z->yil++;
            }
        }
    }
}


 // fonksiyon dosyadan okunan string şekilndeki zamanı zaman nesnesine çevirir
    Zaman zaman_olustur(const char *tarih_str, int gezegen_gunun_saat) {
    Zaman z = (Zaman)malloc(sizeof(struct Zaman));
    if (!z) return NULL;

    sscanf(tarih_str, "%d.%d.%d", &z->gun, &z->ay, &z->yil);
    z->saat = 0;
    z->gezegen_gun_saat = gezegen_gunun_saat;

    snprintf(z->tarih_str, sizeof(z->tarih_str), "%02d.%02d.%04d", z->gun, z->ay, z->yil);
    
    z->ilerisaat = &ilerisaat;
    z->gunileri = &gunileri;
    z->zamandelete = &zamandelete;
    
    return z;
}


 // variş tarihi hesaplamak için kullanılan fonksiyon girilen tarihten ne kadar ileriye gidileceğini hesaplayıp yeni adres döndürür
Zaman gunileri(const Zaman z, int dongu) {
    Zaman yeni = zaman_olustur("1.1.2000", z->gezegen_gun_saat); 
    if (!yeni) return NULL;

    *yeni = *z; // tarih bilgisini kopyala
    yeni->gunileri = &gunileri; 

    for (int i = 0; i < dongu; i++) {
        yeni->gun++;
        int gunsayisi = ayGunSayisi(yeni->ay); // Doğru gün sayısını al
        if (yeni->gun > gunsayisi) {
            yeni->gun = 1;
            yeni->ay++;
            if (yeni->ay > 12) {
                yeni->ay = 1;
                yeni->yil++;
            }
        } 
    }
    return yeni;
}


// zaman karşılaştırma fonksiyonu iki zamanın birbirne eşit olup oladıgına bakar
bool zamanKarsilastir(Zaman zaman1, Zaman zaman2){
    if (zaman1->yil == zaman2->yil && zaman1->ay == zaman2->ay && zaman1->gun == zaman2->gun) {
        return 1; // zamanlar aynı
    }
    else return 0; // zamanlar farklı
}

void zamandelete(Zaman z) {
    free(z);
}


void zamanyazdir(const Zaman z) {
    printf("%02d.%02d.%04d  \n", z->gun, z->ay, z->yil);
}

 // uzay aracının beklem suresini hesaplamak için uzay aracının kalkma tarihi ve gezegnin tarihi arasındaki mesafeyi hesapladık
int zamanFarki(Zaman uzayaraci, Zaman gezegen) {
    int farkGunOlarak = 0;
    int fark = 0; // saaat olarak 
    int yil=uzayaraci->yil-gezegen->yil;
    int ay=uzayaraci->ay-gezegen->ay;
    int gun=uzayaraci->gun-gezegen->gun;

    farkGunOlarak = yil*365 + ay*30 + gun;
    fark = farkGunOlarak*gezegen->gezegen_gun_saat; // gezegenin gün uzunluğuna göre çarpıyorum
    
    return fark;
}
