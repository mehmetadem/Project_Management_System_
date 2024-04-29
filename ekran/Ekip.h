#ifndef EKIP_H
#define EKIP_H
#include <iostream>
#include <string>
#include "Calisan.h"
#include "Ariza.h"

using namespace std;
class Ekip
{
	friend class Calisan;
    private:
    	Ariza Arizalar[10];
    	int Ekip_No;
    	string Ekip_Gorev;
    	float Ekip_Maaliyet;
    	
    	
    	Calisan defaultCalisan;
    	
    	string Sube;
    	
    	void Set_Ekip_No(int _Ekip_No);
    	void Set_Ekip_Sube(string _Sube);
    	void Set_Ekip_Gorev(string _Ekip_Gorev);
    	void Set_Ekip_Maaliyet();
    	
   		
   	public:
   		Calisan Calisanlar[4];
   		explicit Ekip(int _Ekip_No=0,string _Ekip_Gorev=" ",float _Ekip_Maaliyet=0,string _Sube=" ");
   		~Ekip();
		int Calisan_Sayisi;
		int Get_Ekip_No()const;
		string Get_Sube()const;
    	string Get_Ekip_Gorev()const;
		float Get_Ekip_Maaliyet()const;
		int Get_Calisan_Sayisi()const;
	 	
	 	void Set_Calisan_Sayisi(int sayi);
	 	
		void Ekip_Duzenleme(int _Ekip_No,string _Sube,string _Ekip_Gorev,Calisan &Calisana,Calisan &Calisanb,Calisan &Calisanc);
		void Ekip_Duzenleme(int _Ekip_No,string _Sube,string _Ekip_Gorev,Calisan &Calisana,Calisan &Calisanb);
		void Ekip_Duzenleme(int _Ekip_No,string _Sube,string _Ekip_Gorev,Calisan& Calisana);
		void Ekip_Sifirlama(Calisan &Calisana,Calisan &Calisanb,Calisan &Calisanc,int _Ekip_No=0,string _Sube=" ",string _Ekip_Gorev=" ");
   	    const void Ekip_Bilgi();
    		
};
#endif
