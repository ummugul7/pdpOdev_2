/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kisi.h"
#include "dosyaOkuma.h"
#include "kayacGezegen.h"
#include "gazdeviGezegen.h"
#include "buzdeviGezegen.h"
#include "cuceGezegen.h"
#include "zaman.h"


#define SATIR_UZUNLUGU 50
#define BASLANGIC_KAPASITE 10
//kişileri dosyadan okuyup dizi oluşturan bununda adresini göderen fonskiyon
Kisi* DosyadanKisileriOku(const char* dosyaAdi, int* kisiSayisi) {
    FILE* dosya = fopen(dosyaAdi, "r"); 
    int kapasite = BASLANGIC_KAPASITE;
    *kisiSayisi = 0;
    Kisi* kisiler = malloc(kapasite * sizeof(Kisi));

    char satir[SATIR_UZUNLUGU];
    while (fgets(satir, SATIR_UZUNLUGU, dosya)) {
        satir[strcspn(satir, "\n")] = '\0';  
        // dosyadan okuma işlemini # sembolune göre ayırıp atama işlemi yapıyor
        char* ad = strtok(satir, "#");
        char* yasStr = strtok(NULL, "#");
        char* omurStr = strtok(NULL, "#");
        char* uzayAraci = strtok(NULL, "#");

        if (ad && yasStr && omurStr && uzayAraci) {
            int yas = atoi(yasStr);
            int omur = atoi(omurStr);
            // kapasite dolarsa yeni bir dizi oluşturma işlemi yapılıyor 
            if (*kisiSayisi == kapasite) {
                kapasite *= 2;
                kisiler = realloc(kisiler, kapasite * sizeof(Kisi));
            }

            kisiler[(*kisiSayisi)++] = KisiOlustur(ad, yas, omur, uzayAraci);
        }
    }
   
    fclose(dosya);
    return kisiler;
}

uzayAraci * DosyadanUzayaraciOku(const char* dosyaAdi,int* uzayAraciSayisi){

    // uzay aracının variş ve çikiş gezegenlerini karşılaştırmak için gezegen listesi oluşturuyoruz 
    int gezegenSayisi = 0; 
    gezegen* gezegenler =  gezegenleriOku("gezegenler.txt", &gezegenSayisi); // gezegenleri okudum

    
    FILE* dosya = fopen(dosyaAdi, "r"); 
    int kapasite = BASLANGIC_KAPASITE;
    *uzayAraciSayisi = 0;
    uzayAraci* uzayaraclari = malloc(kapasite * sizeof(uzayAraci));

    char satir[SATIR_UZUNLUGU];
    while (fgets(satir, SATIR_UZUNLUGU, dosya)) {
        satir[strcspn(satir, "\n")] = '\0';  
        // okunan satır # işaretine gör parçalara ayrılıp atama işlemi yapılıyor 
        char* ad = strtok(satir, "#");
        char* ciksiGezegeni = strtok(NULL, "#");
        char* varisGezegeni  = strtok(NULL, "#");
        char* ciksiTarihi = strtok(NULL, "#");
        char* mesafeSaatOlarak = strtok(NULL, "#"); 
        int gezegenGununSaati;
        for (int i = 0; i < gezegenSayisi; i++)
        {
            
           if (strcmp(gezegenler[i]->ad,ciksiGezegeni)==0  ) 
           {
            ciksiGezegeni= gezegenler[i]->ad; 
           }
           if (strcmp(gezegenler[i]->ad,varisGezegeni)==0) 
           {
             varisGezegeni = gezegenler[i]->ad; 
            gezegenGununSaati=gezegenler[i]->gezegendeGunKacSaat;
           }
           
        }
        

        if (ad && ciksiGezegeni && varisGezegeni && ciksiTarihi && mesafeSaatOlarak) {
            int mesafe = atoi(mesafeSaatOlarak); // mesafeyi int'e çevir
             Zaman zaman = zaman_olustur(ciksiTarihi, gezegenGununSaati); 
            // dizinin kapasitesi yetmezse genişletme işlemi yapılıyor 
            if (*uzayAraciSayisi == kapasite) {
                kapasite *= 2;
                uzayaraclari = realloc(uzayaraclari, kapasite * sizeof(uzayAraci));
            }

            uzayaraclari[(*uzayAraciSayisi)++] = uzayaraciOlustur(ad, ciksiGezegeni, varisGezegeni, mesafe,zaman);
        }
    }
    
    fclose(dosya);
    return uzayaraclari;
}


gezegen* gezegenleriOku(const char* dosyaAdi, int* gezegenSayisiOut) {
    FILE* dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya açilamadi: %s\n", dosyaAdi);
        *gezegenSayisiOut = 0;
        return NULL;
    }

    int kapasite = 2;
    gezegen* liste = malloc(kapasite * sizeof(gezegen));
    int sayac = 0;

    char satir[256];

    while (fgets(satir, sizeof(satir), dosya)) {
        if (sayac >= kapasite) {
            kapasite *= 2;
            liste = realloc(liste, kapasite * sizeof(gezegen));
        }

        char* ad = strtok(satir, "#");
        char* turStr = strtok(NULL, "#");
        char* gunSaatStr = strtok(NULL, "#");
        char* tarihStr = strtok(NULL, "#\n");

        if (!ad || !turStr || !gunSaatStr || !tarihStr) continue;

        int tur = atoi(turStr);
        int gunSaat = atoi(gunSaatStr);

        Zaman zaman = zaman_olustur(tarihStr, gunSaat);
        // gezegenlerimin farklı türleri var ama ben ana sınıfdan dizi oluşturup hepsini onda tutuyorum 
        // türüne göre kurucu fonksiyonu çağırıyorum 
        switch (tur) {
            case 0:   
                liste[sayac++] = kayacGezegenOlustur(ad, tur, gunSaat, zaman)->super;
                break;
            case 1:
                liste[sayac++] = gazdevigezegenOlustur(ad, tur, gunSaat, zaman)->super;
                break;
            case 2:
                liste[sayac++] = buzdeviGezegenOlustur(ad, tur, gunSaat, zaman)->super;
                break;
            case 3:
                liste[sayac++] = cuceGezegenOlustur(ad, tur, gunSaat, zaman)->super;
                break;
            default:
                printf("Bilinmeyen gezegen türü: %d\n", tur);
                break;
        }
    }

    fclose(dosya);
    *gezegenSayisiOut = sayac;
    return liste;
}