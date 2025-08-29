/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
#include "cuceGezegen.h"
#include "gezegen.h"    
#include <stdlib.h>
#include <stdio.h>
#include "zaman.h"
cuceGezegen cuceGezegenOlustur(char* ad, int gezegenTuru, int gezegendeGunKacSaat, Zaman gezegenZamani){
    cuceGezegen cucegezegen= (cuceGezegen)malloc(sizeof(struct CuceGezegen));

    cucegezegen->super = gezegenOlustur(ad, gezegenTuru, gezegendeGunKacSaat, gezegenZamani); // üst sınıfı oluşturuyoruz
   
    cucegezegen->super->yaslanmaOrani = 0.01f; // Kalan ömre göre Kişi bu gezegende 100 kat daha fazla yaşar
    cucegezegen->cuceGezegenDelete = cuceGezegenDelete; // fonksiyon göstericisini ayarlıyoruz
    return cucegezegen;
}

void cuceGezegenDelete(cuceGezegen g){
    g->super->gezegendelete(g->super); // üst sınıfı yok et
    free(g);
}

