/**
* ÜMMÜGÜL ÇAĞLAR  ummugul.caglar@ogr.sakarya.edu.tr
* 18.05.2025
* 1-A GRUBU 
*/
#include <stdio.h>
#include "kisi.h"
#include "dosyaOkuma.h"
#include "zaman.h"
#include "uzayAraci.h"
#include <stdlib.h> 
#include <string.h>
#include <stdlib.h>

int main() {
    
    int kisiSayisi = 0; 
    Kisi* kisiler = DosyadanKisileriOku("kisiler.txt", &kisiSayisi);

    int gezegenSayisi = 0;
    gezegen* gezegenListesi = gezegenleriOku("gezegenler.txt", &gezegenSayisi);

    int dizidebulunanUzayAraciSayisi = 0;
    uzayAraci* uzayaraclari = DosyadanUzayaraciOku("araclar.txt", &dizidebulunanUzayAraciSayisi);
  
     // gezegenlerin nüfusunu sıfırlama işlemi 
    for (int j = 0; j <  gezegenSayisi; j++)
    {  gezegenListesi[j]->gezegenNufusu=0;  }

    // uzay aracı nufusu heaplama işlemi program başlamdan önce çalıştırılır
    for (int i = 0; i < kisiSayisi; i++) 
    {  kisiler[i]->uzayAraciNufusuHesapla(kisiler[i], uzayaraclari, dizidebulunanUzayAraciSayisi);  }

    //uzay araclari için varış tarihi hesaplama işlemi 
    for (int i = 0; i < dizidebulunanUzayAraciSayisi; i++)
    {   uzayaraclari[i]->varisTarihiHesapla(uzayaraclari[i], gezegenListesi,  gezegenSayisi);  }

      int saat=0;
   //! WHİLE BAŞLANGICI  
   // tum uzay araçlarının durumu vardı veya imha olana kadar döngü tekrarlanır
    while (donguKontrol(uzayaraclari, dizidebulunanUzayAraciSayisi)) {

     for (int i = 0; i < kisiSayisi; i++)
    {
        kisiGuncelle(kisiler[i], uzayaraclari, dizidebulunanUzayAraciSayisi, gezegenListesi,  gezegenSayisi); // kişilerin konumunun guncellenmesi 
        kisiler[i]->kisiYasGuncelle(kisiler[i],uzayaraclari,dizidebulunanUzayAraciSayisi,gezegenListesi, gezegenSayisi); // kişilerin yaşının güncellenmesi
    }

    // gezegen zamanını ilerletme işlemi
    for (int j = 0; j <  gezegenSayisi; j++)
    {   gezegenListesi[j]->gezegenZamani->ilerisaat(gezegenListesi[j]->gezegenZamani);  }
    
      for (int i = 0; i < dizidebulunanUzayAraciSayisi; i++)
    {
        uzayaraclari[i]->tarihKontrolEt(uzayaraclari[i], gezegenListesi,  gezegenSayisi); // tarih kontrolü yapıldı 
        
        uzayaraclari[i]->imhaMi(uzayaraclari[i]); // uzay aracını imha etme fonksiyonu
        uzayaraclari[i]->uzayAraciMesafeKontrolu(uzayaraclari[i], gezegenListesi,  gezegenSayisi); // uzay aracının mesafe kontrolü yapıldı
    } 

     system("cls");

     // ekrana çıktı oluşturma işlemleri
    printf("\nGEZEGENLER\n\n");

    printf("%-20s", ""); 
    for (int i = 0; i <  gezegenSayisi; i++) {
    printf("%-20s", gezegenListesi[i]->ad);
    }   
    printf("\n");
    printf("%-20s", "Tarih:");
       for (int i = 0; i <  gezegenSayisi; i++) {
    printf("%02d.%02d.%04d        ", 
           gezegenListesi[i]->gezegenZamani->gun, 
           gezegenListesi[i]->gezegenZamani->ay, 
           gezegenListesi[i]->gezegenZamani->yil);
      }
     printf("\n");

      printf("%-20s", "Nufus:");
    for (int i = 0; i <  gezegenSayisi; i++) {
        printf("%-20d", gezegenListesi[i]->gezegenNufusu);
    }
    printf("\n\n");

    printf("UZAY ARAÇLARI\n\n");
    printf("%-12s %-12s %-12s %-12s %-20s %-15s\n",
           "Arac Adi", "Durumu", "Cikis", "Varis", "Hedefe Kalan Saat", "Hedef Tarihi", "kisi sayisi");

     for (int i = 0; i < dizidebulunanUzayAraciSayisi; i++) {
        if (strcmp(uzayaraclari[i]->uzayAraciDurumu, "IMHA") == 0) {
    printf("%-12s %-12s %-12s %-12s %-20s %-10s  \n", 
        uzayaraclari[i]->ad,
        uzayaraclari[i]->uzayAraciDurumu,
        uzayaraclari[i]->cikisGezegeni,
        uzayaraclari[i]->varisGezegeni,
        "---",        
        "--------"
    );
} else {  
    printf("%-12s %-12s %-12s %-12s %-20d %02d.%02d.%04d \n", 
        uzayaraclari[i]->ad,
        uzayaraclari[i]->uzayAraciDurumu,
        uzayaraclari[i]->cikisGezegeni,
        uzayaraclari[i]->varisGezegeni,
        uzayaraclari[i]->kalanYolculukSuresi,
        uzayaraclari[i]->varisTarihi->gun,
        uzayaraclari[i]->varisTarihi->ay,
        uzayaraclari[i]->varisTarihi->yil
    );
}
   } 

 saat++;
}   // ! while döngüsü bitişi 

printf("saat %d \n",saat);
    // ! programın yıkıcı fonksiyonlari çağrılır 
    for (int i = 0; i < kisiSayisi; i++) { KisiYokEt(kisiler[i]);  }
    free(kisiler);

    for (int i = 0; i < dizidebulunanUzayAraciSayisi; i++) { uzayaraclari[i]->uzayAraciYokEt(uzayaraclari[i]);}
    free(uzayaraclari);

    for (int i = 0; i <  gezegenSayisi; i++) { gezegenListesi[i]->gezegendelete(gezegenListesi[i]); }
    free(gezegenListesi);

    return 0;

}
