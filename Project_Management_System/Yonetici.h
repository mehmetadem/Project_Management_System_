#ifndef YONETICI_H
#define YONETICI_H
#include <iostream>
#include <string>
#include "Calisan.h"
using namespace std;
class Yonetici : public Calisan 
{
	private:
		//sube , sifre , gorev=Yönetici
		
		string Yonetici_Sube;
		string Yonetici_Sifre;
		
		
		void Set_Yonetici_Sifre(string _Yonetici_Sifre);
		
	public:
		void Set_Yonetici_Sube(string _Yonetici_Sube);
		
		int Get_Yonetici_ID()const;
		string Get_Yonetici_Sube()const;
		string Get_Yonetici_Sifre()const;
				
		explicit Yonetici(int _Yonetici_ID=0,string Sube=" ",string Sifre=" ",string _Calisan_Isim=" ",string _Calisan_Soyisim=" ",string _Calisan_Gorev=" ",double _Calisan_Maas=0);
		~Yonetici();
		
		void Yonetici_Duzenleme(int _Yonetici_ID=0,string Sube=" ",string Sifre=" ",string _Calisan_Isim=" ",string _Calisan_Soyisim=" ",string _Calisan_Gorev="Yonetici",double _Calisan_Maas=0 );
		void Yonetici_Duzenleme(string Yonetici_Sube,string Yonetici_Sifre);
		void Yonetici_Bilgi()const;
		
};
#endif


