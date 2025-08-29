/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
#include "zaman.h"
#ifndef GEZEGEN_H
#define GEZEGEN_H
// soyut sınıf benzetimi icin içi boş bir fonksiyon göstericisi tanımlamak yeterli 

typedef struct Gezegen* gezegen;

struct Gezegen
{
    char ad[20];  
    int gezegenTuru; // 0,1,2,3 
    int gezegendeGunKacSaat;
    Zaman gezegenZamani; 
    double yaslanmaOrani;
    int gezegenNufusu; // gezegenin nüfusu
    void(*gezegendelete)(gezegen);
};

gezegen gezegenOlustur(char* ad, int gezegenTuru, int gezegendeGunKacSaat, Zaman gezegenZamani);
void gezegendelete(gezegen);



#endif 