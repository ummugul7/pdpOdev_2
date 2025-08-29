/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
#include "gezegen.h"
#ifndef KAYACGEZEGEN_H
#define KAYACGEZEGEN_H

typedef struct KayacGezegen* kayacGezegen;
struct KayacGezegen
{
    gezegen super; // üst sınıf gezegen
    void(*kayacGezegenDelete)(kayacGezegen); 
};

void kayacGezegenDelete(kayacGezegen);
kayacGezegen kayacGezegenOlustur(char* ad, int gezegenTuru, int gezegendeGunKacSaat, Zaman gezegenZamani);

#endif