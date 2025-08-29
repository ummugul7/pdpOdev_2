/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
#include "kayacGezegen.h"
#include "gezegen.h"
#include <stdio.h>
#include <stdlib.h>
#include  "zaman.h"

kayacGezegen kayacGezegenOlustur(char* ad, int gezegenTuru, int gezegendeGunKacSaat, Zaman gezegenZamani){
    kayacGezegen kayacgezegen= (kayacGezegen)malloc(sizeof(struct KayacGezegen));
    kayacgezegen->super = gezegenOlustur(ad, gezegenTuru, gezegendeGunKacSaat, gezegenZamani); // üst sınıfı oluşturuyoruz
    
    kayacgezegen->super->yaslanmaOrani = 1.0f; // Kalan ömre göre Kişi bu gezegende normal bir ömür 
    
    kayacgezegen->kayacGezegenDelete = &kayacGezegenDelete; // fonksiyon göstericisini ayarlıyoruz
    return kayacgezegen;
}

void kayacGezegenDelete(kayacGezegen g){
    g->super->gezegendelete(g->super); // üst sınıfı yok et
    free(g);
}