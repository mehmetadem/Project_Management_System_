#ifndef MUSTERI_H
#define MUSTERI_H
#include <iostream>
#include <string>
//#include "Ariza.h"
using namespace std;
class Musteri
{
	friend void Ariza_Duzenle(int _Randavu_No,string _Ariza_Turu, Musteri &_musteri );
	friend ostream &operator<<(ostream &output,Musteri &Musteri);
	private:
		int Musteri_ID;
		string Musteri_Firma;
		string Musteri_Yonetici_Isim;
		string Musteri_Yonetici_Soyisim;
		string Musteri_Iletisim_Numarasi;
		
		string Musteri_Konum;
		float Musteri_Uzaklik;
 		
 		void Set_Musteri_ID(int _Musteri_ID);
 		void Set_Musteri_Firma(string _Musteri_Firma);
		void Set_Musteri_Yonetici_Isim(string _Musteri_Yonetici_Isim);
		void Set_Musteri_Yonetici_Soyisim(string _Musteri_Yonetici_Soyisim);
		void Set_Musteri_Iletisim_Numarasi(string _Musteri_Iletisim_Numarasi);
		void Set_Musteri_Konum(string _Musteri_Konum);
		void Set_Musteri_Uzaklik(float _Musteri_Uzaklik);
		
	public:
		friend void Ariza_Sifirla(int _Ariza_No,string _Ariza_Turu, Musteri );
		static Musteri defaultMusteri;
 		explicit Musteri(int _Musteri_ID=0,string _Musteri_Firma=" ",string _Musteri_Yonetici_Isim=" ",string _Musteri_Yonetici_Soyisim=" ",string _Musteri_Iletisim_Numarasi=" ",string _Musteri_Konum=" ",float _Musteri_Uzaklik=0);
 		~Musteri();
 		
 		int Get_Musteri_ID()const;
		string Get_Musteri_Firma()const;
		string Get_Musteri_Yonetici_Isim()const;
		string Get_Musteri_Yonetici_Soyisim()const;
		string Get_Musteri_Iletisim_Numarasi()const;
		
		string Get_Musteri_Konum() const;
		float Get_Musteri_Uzaklik()const;
		
		void Musteri_Duzenleme(int Musteri_ID,string Musteri_Firma,string Musteri_Yonetici_Isim,string Musteri_Yonetici_Soyisim,string Musteri_Iletisim_Numarasi,string Musteri_Konum,float Musteri_Uzaklik);
		void Musteri_Duzenleme(int _Musteri_ID=0,string _Musteri_Firma=" ",string _Musteri_Yonetici_Isim=" ",string _Musteri_Yonetici_Soyisim=" ",string _Musteri_Iletisim_Numarasi=" ");
		void Musteri_Bilgi()const;
};
#endif

/*	
	Talep sýnýfý  içerisinde 
	ariza ve Musteri olacak
	Ariza da ariza türü 
*/
