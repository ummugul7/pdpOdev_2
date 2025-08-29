/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
#include "gezegen.h"
#ifndef BUZDEVIGEZEGEN_H
#define BUZDEVIGEZEGEN_H

typedef struct BuzdeviGezegen* buzdeviGezegen;

struct BuzdeviGezegen
{
    gezegen super; // üst sınıf gezegen
    void(*buzdeviGezegenDelete)(buzdeviGezegen); 
};

buzdeviGezegen buzdeviGezegenOlustur(char* ad, int gezegenTuru, int gezegendeGunKacSaat, Zaman gezegenZamani);
void buzdeviGezegenDelete(buzdeviGezegen);

#endif 