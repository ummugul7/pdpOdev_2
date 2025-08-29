/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
// cucegezegeninde 0.01 (Kalan ömre göre Kişi bu gezegende 100 kat daha fazla yaşar)
// yani her 100 saat gectiğinde kişinin ömründen 1 saat gidecek 
#include "gezegen.h"
#ifndef CUCEGEZEGEN_H
#define CUCEGEZEGEN_H

typedef struct CuceGezegen* cuceGezegen;
struct CuceGezegen
{
    gezegen super; // üst sınıf gezegen
    void(*cuceGezegenDelete)(cuceGezegen); 
};

cuceGezegen cuceGezegenOlustur(char* ad, int gezegenTuru, int gezegendeGunKacSaat, Zaman gezegenZamani);
void cuceGezegenDelete(cuceGezegen);

#endif