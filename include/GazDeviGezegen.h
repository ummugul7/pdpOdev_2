/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
#include "gezegen.h"
#ifndef GAZDEVIGEZEGEN_H
#define GAZDEVIGEZEGEN_H

typedef struct GazDevigezegen* gazdevigezegen;
struct GazDevigezegen
{
    gezegen super; // üst sınıf gezegen
    void(*gazdevigezegenDelete)(gazdevigezegen); 
};

gazdevigezegen gazdevigezegenOlustur(char* ad, int gezegenTuru, int gezegendeGunKacSaat, Zaman gezegenZamani);
void gazdevigezegenDelete(gazdevigezegen g);

#endif 