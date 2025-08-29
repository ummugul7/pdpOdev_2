/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
#include "GazDeviGezegen.h"
#include "gezegen.h"
#include <stdio.h>
#include <stdlib.h>
#include "zaman.h"

gazdevigezegen gazdevigezegenOlustur(char* ad, int gezegenTuru, int gezegendeGunKacSaat, Zaman gezegenZamani){
    gazdevigezegen g = (gazdevigezegen)malloc(sizeof(struct GazDevigezegen));
    g->super = gezegenOlustur(ad, gezegenTuru, gezegendeGunKacSaat, gezegenZamani); // üst sınıfı oluşturuyoruz
    g->super->yaslanmaOrani = 0.1f; // Kalan ömre göre Kişi bu gezegende 10 kat daha fazla yaşar
    g->gazdevigezegenDelete = &gazdevigezegenDelete; // fonksiyon göstericisini ayarlıyoruz
    return g;
}

void gazdevigezegenDelete(gazdevigezegen g){
    g->super->gezegendelete(g->super); // üst sınıfı yok et
    free(g);
}

