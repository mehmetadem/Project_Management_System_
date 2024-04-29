// y?netici taraf?ndan atanan ?ubler g?r?nt?lenebilecek, Subeler ?Simlendirildikten sonra Numaraland?ralacak
#ifndef SUBE_H
#define SUBE_H
#include <iostream>
#include <string>
#include "Calisan.h"
#include "Yonetici.h"
#include "Ekip.h"
#include "Musteri.h"
#include "Ariza.h"
#include "Talep.h"

class Sube
{
	private:
		
		int YazilimciIndex[30];
		int TeknisyenIndex[30];// algoritmada her seferinde 0 la
		int YazilmciEkipleri[20];
		int TeknisyenEkipleri[20];
		
		
		int Sube_ID;
		string Sube_Konum;
		
		void Set_Sube_ID(int ID);
		void Set_Sube_Konum(string _Sube_Konum);
	
	public:
		int Teknik_Ariza_Sayisi()const;
		Ariza Teknik_Ariza[25];
		Ariza Yazilim_Ariza[25];
		
		Talep Yazilim_Talep[25];
		Talep Teknik_Talep[25];
		
		Calisan Calisanlar[30];
		Musteri Musteriler[30];
		Yonetici Sube_Yoneticisi;
		Ekip Ekipler[20];

		explicit Sube(int Sube_ID=0, string Sube_Konum=" ");
		~Sube();
		
		int Get_Sube_ID()const;
		string Get_Sube_Konum()const;
		string Get_Sube_Sifre()const;
		
		void Sube_Duzenleme(int _Sube_ID=0, string Sube_Konum=" ");
		void Sube_Duzenleme(int Sube_ID, string Sube_Konum,string Sifre,string _Calisan_Isim,string _Calisan_Soyisim,double _Calisan_Maas,string _Calisan_Gorev="Yonetici" );
		void EkipOlusturmaIslemi();
		void Sube_Bilgi()const;
		void Sube_Detay()const;
		void SubeSil();
		
		void MusteriBilgileri()const;
	
	    int Calisan_Sayisi()const;
	    void Zam_Yap(float Zam_Orani);
	    
	    void CalisanSil(int CalisanID);
	    void MusteriSil(int ID);
	    void YoneticiSil();
	    
		int Aktif_Yazilim_Ariza_Sayisi()const;
	    int Aktif_Teknik_Ariza_Sayisi()const;
	    
	    int Yazilimci_Sayisi()const;
	    int Teknisyen_Sayisi()const;
	    
	    void Yazilim_Talepleri_Atanmasi();// siralamadan once çaðýr
	    void Teknik_Talepleri_Atanmasi();//ksai yoldan önce
	    
	    void Teknik_Ekip_EnKisa_Yol(int EkipId);
	    void Yazilimci_Ekip_Kontrol_Sirasi(int EkipId);
};

#endif
