#ifndef PANELLER_H
#define PANELLER_H
#include <iostream>
#include <string>
#include "Yonetici.h"
#include "Sube.h"
using namespace std;
class Panel
{
	private:
		Yonetici Admin;
		Sube Subeler[6];
	public:
		static void KarsialamaMesaji();
		void GirisEkrani();
	
		void YoneticiEkran();
		
		void SubeIslemleri();
		void SubeEkleme();
		void SubeDuzenleme();
		void SubeDuzenleme(int SubeID);
		void SubeSilme();
		void SubeListesi();
		void SubeBilgileri();
		void SubeMusteriIslemleri();
		
		void Randevular();
		void EkipMudahale(int SubeID);
		
		string SubeArama(string Konum);
		int SubeIndexBulma(string Konum);
		
		void SubeEkran(int SubeID);
		
		int SubeSecimi();
		void SubeMusteriListesi(int SubeNumarasi);
	
		void CalisanIslemleri(int SubeNumarasi);
		void CalisanEkleme(int SubeNumarasi);
		void CalisanDuzenleme(int SubeNumarasi);
		void CalisanSilme(int SubeNumarasi);
		void CalisanBilgileri(int SubeNumarasi);
		void CalisanlaraZam(int SubeNumarasi);
		
		void Musteri_Islemleri();
		void Musteri_Ekleme();
		void MusteriDuzenleme(int SubeNumarasi);
		void Musteri_Duzenleme(int SubeNumarasi);
		void Musteri_Silme();
		void Musteri_Bilgileri();
		void MusteriListesi(int SubeNumarasi);
		
		void Musteri_Menu(int MusteriID,string Konum);
		
		void Ariza_Bildir(Musteri& musteri,Sube& sube);
		bool Musteri_Arama(string Firma_Ismi,string konum);
		int Musteri_Index(string Firma_Ismi,string konum);
		void Teknik_Ariza(Musteri& musteri,Sube& sube);
		void Yazilim_Ariza(Musteri& musteri,Sube& sube);
		
		void Ariza_Iptal(Musteri& musteri,Sube& sube);
		void Teknik_Ariza_Iptal(Musteri& musteri,Sube& sube);
		void Yazilim_Ariza_Iptal(Musteri& musteri,Sube& sube);
		
		void Ariza_Bilgileri(Musteri& musteri,Sube& sube);
		
		void SifreDegistir(int SubeID);
		void YoneticiDuzenleme(int SubeID);
		
		void DosyaSenkronizasyon();
		
		void SubeVerileriniYaz();
		void SubeVerileriniAl();
		void SubeNumarasiTutucu(int Id);
		int SubeNumarasiEsleme();
		
		void CalisanVerileriniAl();
		void CalisanVerileriniYaz(int SubeId=0);
		void CalisanIdTutucu(int Id);
		int CalisanIdEsitleme();
		
		void MusteriVerileriniAl();
		void MusteriVerileriniYaz(int SubeId=0);
		void MusteriIdTutucu(int Id);
		int MusteriIdEsitleme();
		
		void TeknikArizaVerileriniAl();
		void TeknikArizaVerileriniYaz(int SubeId=0);
		void TeknikArizaIdTutucu(int Id);
		int TeknikArizaIdEsitleme();
		
		void YazilimArizaVerileriniAl();
		void YazilimArizaVerileriniYaz(int SubeId=0);
		void YazilimArizaIdTutucu(int Id);
		int YazilimArizaIdEsitleme();
		
};
#endif
