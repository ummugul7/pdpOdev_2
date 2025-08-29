/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
#include "kisi.h"
#include "uzayAraci.h"
#include "gezegen.h"
#include "zaman.h"
#ifndef DOSYAOKUMA_H
#define DOSYAOKUMA_H

Kisi* DosyadanKisileriOku(const char* dosyaAdi, int* kisiSayisi);
uzayAraci * DosyadanUzayaraciOku(const char* doaysaAdi,int* uzayAraciSayisi);
gezegen* gezegenleriOku(const char* dosyaAdi, int* gezegenSayisiOut);
#endif

