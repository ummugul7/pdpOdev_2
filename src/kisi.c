/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
#include "kisi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uzayAraci.h"

// kişi oluşturma fonksiyonu
Kisi KisiOlustur(const char* ad, int yas, double kalanOmur, const char* uzayAraciAdi) {

    Kisi yeniKisi = (Kisi)malloc(sizeof(struct kisi));
    strcpy(yeniKisi->ad, ad);
    strcpy(yeniKisi->uzayAraciAdi, uzayAraciAdi);
    yeniKisi->yas = yas;
    yeniKisi->kalanOmur = kalanOmur;
    if (kalanOmur>0)
    { // olduMu degişkeninin kullanılma sebebi 1 kez öldükten sonra ömrü 0 olsa bile if bloglarına tekrar girmesini engellemek
        yeniKisi->olduMu = 0;
    }
    
    // yazdıgım fonskiyonları class benzetmesi yapmak için adres ataması yaptık 
    yeniKisi->KisiYokEt = &KisiYokEt; 
    yeniKisi->kisiYasGuncelle = &kisiYasGuncelle; 
    yeniKisi->uzayAraciNufusuHesapla = &uzayAraciNufusuHesapla; // uzay aracının nüfusunu hesapla fonksiyonunu atadım
    return yeniKisi;
}

void kisiYasGuncelle(Kisi k,uzayAraci *u,int uzayAraciSayisi,gezegen *gezegenListesi,int gezegenSayisi) { 
    
    if (k->kalanOmur >0 )
    { 
        for (int i = 0; i < uzayAraciSayisi; i++)
        {    // uzay aracı yoldaysa standart yaş alma işlemi 
            if (strcmp(k->uzayAraciAdi, u[i]->ad) == 0) {
                if (strcmp(u[i]->uzayAraciDurumu, "yolda") == 0) {
                    k->kalanOmur --; // kişinin yolda standart 1 zaman birimi kadar yaş alır
                    break;
                }
                 // uzay aracı bekliyorsa bulundugu gezegene göre yaşlanma işlemi 
                else if (strcmp(u[i]->uzayAraciDurumu, "bekliyor") == 0) {
                    for (int g = 0; g < gezegenSayisi; g++)
                    {
                        if (strcmp(u[i]->cikisGezegeni, gezegenListesi[g]->ad) == 0) {
                            int tur = gezegenListesi[g]->gezegenTuru; // gezegen türünü buldum
                            switch (tur)
                            {  // uzay aracı türüne göre verilen yaşlanma oranlarına bakılarak kişinin ömründen düşülür
                                case 0: k->kalanOmur -= gezegenListesi[g]->yaslanmaOrani; break;
                                case 1: k->kalanOmur -= gezegenListesi[g]->yaslanmaOrani; break;
                                case 2: k->kalanOmur -= gezegenListesi[g]->yaslanmaOrani; break;
                                case 3: k->kalanOmur -= gezegenListesi[g]->yaslanmaOrani; break;
                            default: break;
                            }
                            break;
                        }
                    }
                    
                }
                // uzay aracı vardi ise bulundugu gezegene göre yaşlanma işlemi 
                else if (strcmp(u[i]->uzayAraciDurumu, "vardi") == 0) {
                    for (int g = 0; g < gezegenSayisi; g++)
                    {
                        if (strcmp(u[i]->varisGezegeni, gezegenListesi[g]->ad) == 0) {
                            int tur = gezegenListesi[g]->gezegenTuru; // gezegen türünü buldum
                            switch (tur)
                            {  // uzay aracı türüne göre verilen yaşlanma oranlarına bakılarak kişinin ömründen düşülür
                                case 0: k->kalanOmur -= gezegenListesi[g]->yaslanmaOrani; break;
                                case 1: k->kalanOmur -= gezegenListesi[g]->yaslanmaOrani; break;
                                case 2: k->kalanOmur -= gezegenListesi[g]->yaslanmaOrani; break;
                                case 3: k->kalanOmur -= gezegenListesi[g]->yaslanmaOrani; break;
                            default:   break;
                            }
                            break;
                        }
                    }
                }
            }  
        }    
    }
   
    if (k->kalanOmur < 0) {
    k->kalanOmur = 0.0f; // bir sonraki konrol işlemi için - deger gelmesin diye 0a eşitledik 
}   
}
// uzay arcalari için nufus hesaplama fonksiyonu program başlamadan once çalışıp atama işlemi yapılmış olur.
void uzayAraciNufusuHesapla(Kisi k,uzayAraci * u ,int uzayAraciSayisi){
    for (int i = 0; i < uzayAraciSayisi; i++)
    {
        if (strcmp(k->uzayAraciAdi, u[i]->ad) == 0) {
            u[i]->uzayAraciNufusu++;
            break;
        }
    }
}



void kisiGuncelle(Kisi k,uzayAraci *u,int uzayAraciSayisi,gezegen *gezegenListesi,int gezegenSayisi){
     // olduMu degişkeninin kullanılma sebebi 1 kez öldükten sonra ömrü 0 olsa bile if bloglarına tekrar girmesini engellemek
     if (k->kalanOmur == 0.0f && k->olduMu == 0) { // KİŞİNİN ZAMANI BİTTİYSE BU BLOGA GİRECEK
		    	  for(int i=0 ; i<uzayAraciSayisi ; i++) {
		    		  if( strcmp(k->uzayAraciAdi, u[i]->ad) == 0 && strcmp(u[i]->uzayAraciDurumu, "yolda") == 0) {
		    			u[i]->uzayAraciNufusu--; 
                         k->olduMu = 1; // burda tekrar nufus azaltıp bu ife girmesin diye yaptım
			    		     break;
		    		  }	 
		    		  else if ( strcmp(k->uzayAraciAdi, u[i]->ad) == 0 && strcmp(u[i]->uzayAraciDurumu, "vardi") == 0) {
		    			   for(int j=0; j<gezegenSayisi; j++) {
		    				   if(strcmp(u[i]->varisGezegeni,gezegenListesi[j]->ad ) == 0) {
		    					   gezegenListesi[j]->gezegenNufusu--; // KİŞİ VARDIYSA BULUDNUGU GEZEGENEDEN NUFUS EKSİLTİLİR 
                                   u[i]->uzayAraciNufusu--; // kişi öldüyse uzay aracından da nufus düşülür
                                   k->olduMu = 1; 
		    					   break; 
		    				   }
		    			   }   
		    		  }	
		    		  else if( strcmp(k->uzayAraciAdi, u[i]->ad) == 0 && strcmp(u[i]->uzayAraciDurumu, "bekliyor")==0) {
		    			  for(int m =0; m<gezegenSayisi; m++) {
		    				   if(strcmp(u[i]->cikisGezegeni,gezegenListesi[m]->ad ) ==0 ) {
		    					 u[i]->uzayAraciNufusu--; // KİŞİ BEKLİYORSA BULUDNUGU GEZEGENEDEN NUFUS EKSİLTİLİR 
                                 gezegenListesi[m]->gezegenNufusu--;
                                  k->olduMu = 1;
			    					   break;
		    				   }
		    			   }  
		    		  }	 
		    	  }
		           
		      }

}

void KisiYokEt(Kisi k) {
    free(k);
}


