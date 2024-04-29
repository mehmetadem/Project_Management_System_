#include <iostream>
#include <string>
#include "Calisan.h"
#include "Yonetici.h"
using namespace std;
// Yapýcý , Yýkýcý Fonks.
	Yonetici::Yonetici(int _Yonetici_ID,string Sube,string Sifre,string _Calisan_Isim,string _Calisan_Soyisim,string _Calisan_Gorev,double _Calisan_Maas):Calisan(_Yonetici_ID,_Calisan_Isim,_Calisan_Soyisim,_Calisan_Gorev,0,_Calisan_Maas)
	{
		Yonetici_Sube=Sube;
		Yonetici_Sifre=Sifre;
	}
	
	Yonetici::~Yonetici() 
	{
		cout<<"Yonetici Silindi !"<<endl;
	}
	
// Set-Get Fonks.
	void Yonetici::Set_Yonetici_Sube(string _Yonetici_Sube)
	{
		if(_Yonetici_Sube!=" ")
		{
			Yonetici_Sube=_Yonetici_Sube;
		}
		else 
		{
			cout<<"Geceresiz Sube!"<<endl<<endl;
		}
	}
	void Yonetici::Set_Yonetici_Sifre(string _Yonetici_Sifre)
	{
		if(_Yonetici_Sifre.length()<=5)
		{
			cout<<"Yonetici Sifresi 6 karakterden az OLAMAZ!!"<<endl;
		}
		else
		{
			Yonetici_Sifre=_Yonetici_Sifre;
		}
	}
	
	int Yonetici::Get_Yonetici_ID()const 
	{
		return Calisan_ID;
	}
	string Yonetici::Get_Yonetici_Sube()const
	{
		return Yonetici_Sube;
	}
	string Yonetici::Get_Yonetici_Sifre()const
	{
		return Yonetici_Sifre;
	}
	
	// Diðer Fonks.
	void Yonetici::Yonetici_Duzenleme(int _Yonetici_ID,string Sube,string Sifre,string _Calisan_Isim,string _Calisan_Soyisim,string _Calisan_Gorev,double _Calisan_Maas )
	{
		if(Sube=="Admin")
		{
			Calisan_ID=_Yonetici_ID;
			Yonetici_Sube=Sube;
			Yonetici_Sifre=Sifre;
			Calisan_Isim=_Calisan_Isim;
			Calisan_Soyisim=_Calisan_Soyisim;
			Calisan_Gorev=_Calisan_Gorev;
			Calisan_Maas=_Calisan_Maas;
		}
		else
		{
			if(_Yonetici_ID!=0)
			{
				CalisanDuzenleme( _Yonetici_ID,_Calisan_Isim,_Calisan_Soyisim,_Calisan_Gorev, _Calisan_Maas);
				Yonetici_Duzenleme(Sube,Sifre);
			}
			else
			{
				Yonetici_Sube=Sube;
				Yonetici_Sifre=Sifre;
				CalisanDuzenleme();
			}
		}
	}
	void Yonetici::Yonetici_Duzenleme(string Sube,string Sifre)
	{
		Set_Yonetici_Sube(Sube);
		Set_Yonetici_Sifre(Sifre);
	}
	void Yonetici::Yonetici_Bilgi()const
	{
		if(Calisan_ID!=0)
		{
			cout<<endl;
			cout<<"		"<<Get_Yonetici_Sube()<<endl<<endl;
			cout<<"Isim: "<<Get_Calisan_Isim()<<endl;
			cout<<"Soy isim: "<<Get_Calisan_Soyisim()<<endl;
			cout<<"Sifre: "<<Get_Yonetici_Sifre()<<endl;
			cout<<"Gorev: "<<Get_Calisan_Gorev()<<endl;
			cout<<"Maas: "<<Get_Calisan_Maas()<<endl<<endl;
		}
	}
