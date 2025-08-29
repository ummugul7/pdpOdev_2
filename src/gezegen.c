/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
#include "gezegen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

gezegen gezegenOlustur(char* ad, int gezegenTuru, int gezegendeGunKacSaat, Zaman gezegenZamani){
       gezegen g = (gezegen)malloc(sizeof(struct Gezegen));
         strcpy(g->ad, ad);
            g->gezegenTuru = gezegenTuru;
            g->gezegendeGunKacSaat = gezegendeGunKacSaat;
            g->gezegenZamani = gezegenZamani;
            g->gezegendelete = &gezegendelete; // fonksiyon göstericisini ayarlıyoruz
        return g;    
}

void gezegendelete(gezegen g){
    free(g->gezegenZamani); // zaman nesnesini yok et
    free(g);
}