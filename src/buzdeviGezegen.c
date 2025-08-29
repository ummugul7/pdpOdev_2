/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
#include "buzdeviGezegen.h" 
#include <stdio.h>
#include "zaman.h"
#include "gezegen.h"
#include <stdlib.h>

buzdeviGezegen buzdeviGezegenOlustur(char* ad, int gezegenTuru, int gezegendeGunKacSaat, Zaman gezegenZamani){
    buzdeviGezegen b = (buzdeviGezegen)malloc(sizeof(struct BuzdeviGezegen));
    b->super = gezegenOlustur(ad, gezegenTuru, gezegendeGunKacSaat, gezegenZamani); // üst sınıfı oluşturuyoruz
    b->super->yaslanmaOrani = 0.5f; // Kalan ömre göre Kişi bu gezegende 2 kat daha fazla yaşar
    b->buzdeviGezegenDelete = &buzdeviGezegenDelete; // fonksiyon göstericisini ayarlıyoruz
    
    return b;
}

void buzdeviGezegenDelete(buzdeviGezegen b){
    b->super->gezegendelete(b->super); // üst sınıfı yok et
    free(b);
}