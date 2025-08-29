/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/

#include "uzayAraci.h"
#include "gezegen.h"
#include "zaman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

uzayAraci uzayaraciOlustur(char * ad , char * cikisGezegeni, char * varisGezegeni, int kalanYolculukSuresi, Zaman cikisTarihi) {
   
    uzayAraci yeniUzayAraci = (uzayAraci)malloc(sizeof(struct UzayAraci));
    
    strcpy(yeniUzayAraci->ad, ad);
    strcpy(yeniUzayAraci->cikisGezegeni, cikisGezegeni);
    strcpy(yeniUzayAraci->varisGezegeni, varisGezegeni);
    yeniUzayAraci->kalanYolculukSuresi = kalanYolculukSuresi;
    yeniUzayAraci->cikisTarihi = cikisTarihi; 
    yeniUzayAraci->uzayAraciNufusu = 0; // başlangıçta uzay aracının nüfusu sıfırdır 
    yeniUzayAraci->yolda = true; 
    yeniUzayAraci->vardi = true; 
    yeniUzayAraci->bekliyor = true; 

    // tanımlanan fonksiyonları sınıf gibi kullanmak için adres ataması yapılır
    yeniUzayAraci->uzayAraciYokEt = &uzayAraciYokEt; 
    yeniUzayAraci->tarihKontrolEt = &tarihKontrolEt; 
    yeniUzayAraci->uzayAraciMesafeKontrolu=&uzayAraciMesafeKontrolu;
    yeniUzayAraci->varisTarihiHesapla=&varisTarihiHesapla;
    yeniUzayAraci->imhaMi=&imhaMi;
    
    return yeniUzayAraci;
}

void uzayAraciYokEt( uzayAraci u) {
    u->cikisTarihi->zamandelete(u->cikisTarihi); // çıkış tarihini yok et
    u->varisTarihi->zamandelete(u->varisTarihi); // varış tarihini yok et
    free(u);
}

//uzay aracının kalkış tarihi ve gezegenin tarihini kontrol eden fonksiyon 
void tarihKontrolEt( uzayAraci u ,gezegen* gezegenler, int gezegenSayisi) {
    for (int i = 0; i < gezegenSayisi; i++)
    {
        if (strcmp(u->cikisGezegeni, gezegenler[i]->ad) == 0) // cıkış gezegenini bulup tarih karşılaştırma işlemi yapılır 
        {
            
            if (zamanKarsilastir(gezegenler[i]->gezegenZamani, u->cikisTarihi) ) // zaman karşılaştırması yapıldı 
            { if(u->yolda) { // BİR KEZ YOLDA OLDUKTAN SONRA BİR DAHA YOLDA OLMAYACAK BU YUZDEN BOOL BİR İFADE KULLANDIM
                strcpy(u->uzayAraciDurumu,"yolda" ); 
                if(!u->bekliyor) { // DAHA ONCE BEKLİYOR DURUMUNDA OLDUYSA UZAY ARACINDAKİ NUFUS GEZEGENE GEÇMİŞ BU YUZDEN EKSİLTİLMESİ GEREKİR 
                                 // BEKLEMEDEN DİREKET YOLA ÇIKARSA ZATEN NUFUS GEZEGENDE HİÇ OLMADI BU YUZDEN GEZEGENDEN NUFUSU EKSİLTMEYE GEREK YOK 
                    gezegenler[i]->gezegenNufusu -= u->uzayAraciNufusu; // uzay aracının nüfusunu gezegenin nüfusundan düşüyorum    
                }
                u->yolda=false;
                u->bekliyor = false;
               
            }    
            }
            else 
            { 
                if(u->bekliyor) { // HER DONGUDE NUFUSU EKLEYİP DURMASIN DİYE BEN BİR DEFADAN SONRA BEKLİYORU FALSE YAPTIM 
                    strcpy(u->uzayAraciDurumu,"bekliyor" );
                    gezegenler[i]->gezegenNufusu += u->uzayAraciNufusu; // uzay aracının nüfusunu gezegenin nüfusuna ekliyorum}
                   u->bekliyor = false;
                }
            }
    }
}

}

void uzayAraciMesafeKontrolu(uzayAraci uzayaraci,gezegen* gezegenler,int gezegensayisi){
   if (strcmp(uzayaraci->uzayAraciDurumu,"yolda")==0) // eger yolda ise mesafe eksiltme işlemi yapılır
   { 
    if (uzayaraci->kalanYolculukSuresi > 0) {
        uzayaraci->kalanYolculukSuresi--;
        if (uzayaraci->kalanYolculukSuresi == 0) {
        strcpy(uzayaraci->uzayAraciDurumu,"vardi" ); // varış gezegeni geldiğinde durumu vardi yap
    }
    } 
    
   }

   if (strcmp(uzayaraci->uzayAraciDurumu,"vardi")==0) {
    if(uzayaraci->vardi) {
        for (int i = 0; i < gezegensayisi; i++) {
            if (strcmp(uzayaraci->varisGezegeni, gezegenler[i]->ad) == 0) {
                gezegenler[i]->gezegenNufusu += uzayaraci->uzayAraciNufusu; // uzay aracının nüfusunu gezegenin nüfusuna ekliyorum
                uzayaraci->vardi=false; // BİR KEZ VARDIKTAN SORNRA TEKRAR VARAMYACAĞI İÇİN VARDİ BOOL İFADESİ FALSE YAPILIR 
                break;
            }
        } // BOOL İFADE KULLANAM SEBEBİMİZ HER DEFASINDA NUFUS AKTARIMINI ENGELLEME 
          // ÇÜNKÜ HER DÖNGÜDE BU METOD ÇAĞIRILACAK SADECE DURUM KONTORULU DURUMU VARDI OLDUĞU SURECE EKLEME YAPACAK 
         
        
    }
}
}
// uzay aracımın içindeki kişilerin hepsi öldüğünde imha olacak
void imhaMi(uzayAraci u ){
    if(u->uzayAraciNufusu ==0 ) {
				strcpy(u->uzayAraciDurumu,"IMHA" );	
			}
}

// WHİLE DONGUSU İÇİN YAZILMIŞ FONKSİYON EN AZ 1 ARAC İMHA VEYA VARDİ DEĞİLSE İŞLEM DEVAM EDER 
bool donguKontrol( uzayAraci *uzayAraci, int uzayaracisayisi){
    for (int i = 0; i < uzayaracisayisi; i++)
    {
        if (!strcmp(uzayAraci[i]->uzayAraciDurumu,"IMHA")==0 && !strcmp(uzayAraci[i]->uzayAraciDurumu,"vardi")==0) {
	            return true;
	        }
    }
    return false;
}

void varisTarihiHesapla(uzayAraci u, gezegen * gezegenler,int gezegenSayisi){

    int bekle = 0; // bekleme süresi
    
    for(int i=0; i<gezegenSayisi ; i++) {  
            if(strcmp(u->cikisGezegeni, gezegenler[i]->ad)==0) {
                // bulundugu gezegen ile çıkış zamanı arasındaki farkı hesaplayıp bekelme saati olarak atıyoruz 
                bekle=zamanFarki(u->cikisTarihi,gezegenler[i]->gezegenZamani); 
                break;
			} 
		}
   
    int toplamZaman = u->kalanYolculukSuresi + bekle; 
    
		for(int i=0; i<gezegenSayisi ; i++) {  
            if(strcmp(u->varisGezegeni, gezegenler[i]->ad)==0) {
                int gunUzunlugu= gezegenler[i]->gezegendeGunKacSaat; // varacaği gezegenin gün uzunlugunu alıyoruz
                 // yolculuk suresi ve beklem süresi toplanıp veris gezegeninin saat dilimine bolunup gezegenin zamanına eklenir 
                int dongu = toplamZaman/gunUzunlugu;
                // gunileri fonksiyonu varis gezegeninin tarihine dongu kadar gün ekleyip variş tarihi hesaplamayı sağlar
                Zaman zaman =gezegenler[i]->gezegenZamani->gunileri(gezegenler[i]->gezegenZamani,dongu);
				u->varisTarihi=zaman;
				break;
			}
			 
		}
}



