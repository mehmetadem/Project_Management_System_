#include <iostream>
#include <string>
#include "Ariza.h"
#include "Musteri.h"
using namespace std;

	Ariza::Ariza(int _Ariza_No, string _Ariza_Turu,string _Konum)
	{
		Ariza_No=_Ariza_No;
		Ariza_Turu=_Ariza_Turu;
		Konum=_Konum;
		musteri=defaultMusteri;
	}

	Ariza::~Ariza()
	{
		cout<<"Ariza Silme Islemi Basarili";
	}

//***********************************************************************************************************************************************************************
//----------------Set Islemleri
//***********************************************************************************************************************************************************************
	
	void Ariza::Set_Ariza_No(int _Ariza_No)
	{
		if(_Ariza_No==0 || _Ariza_No<0)
		{
			cout<<"Ariza No 0 Veya 0 dan kucuk OLAMAZ!!"<<endl;
		}
		else
		{
			Ariza_No=_Ariza_No;
		}
	}
	
	void Ariza::Set_Ariza_Turu(string _Ariza_Turu)
	{
			if(	_Ariza_Turu=="Y" || _Ariza_Turu=="y" ||
			_Ariza_Turu=="T" || _Ariza_Turu=="t" ||
			_Ariza_Turu=="Yazilim"  || _Ariza_Turu=="Teknik")
		{
			if(_Ariza_Turu=="Y"|| _Ariza_Turu=="y" ||	_Ariza_Turu=="Yazilim")
			{
				Ariza_Turu="Yazilim";
			}
			else if(_Ariza_Turu=="T"||_Ariza_Turu=="t" ||	_Ariza_Turu=="Teknik")
			{
				Ariza_Turu="Teknik";
			}
		}
		else
		{
			cout<<"GECERSÝZ Ariza !!"<<endl;
		}	
	}
	
//***********************************************************************************************************************************************************************
//----------------Get Islemleri
//***********************************************************************************************************************************************************************
	
	int Ariza::Get_Ariza_No()const
	{
		return Ariza_No;
	}
	string Ariza::Get_Ariza_Turu()const
	{
		return Ariza_Turu;
	}
	string Ariza::Get_Ariza_Konum()const
	{
		return Konum;
	}

//***********************************************************************************************************************************************************************
//----------------Fonks
//***********************************************************************************************************************************************************************
	void Ariza::Ariza_Duzenle(int _Ariza_No, string _Ariza_Turu, Musteri &_musteri)
	{
        Set_Ariza_No(_Ariza_No);
        Set_Ariza_Turu(_Ariza_Turu);
        musteri = _musteri;
        Konum = musteri.Get_Musteri_Konum();
    }

	void Ariza::Ariza_Bilgileri()const
	{
		if(Get_Ariza_Turu()!=" ")
		{
		cout<<"Ariza No: "<<Get_Ariza_No()<<endl;
		cout<<"Musteri: "<<musteri.Get_Musteri_Firma()<<endl;
		cout<<"Ariza Turu:"<<Get_Ariza_Turu()<<endl<<endl;
		}
	
	}
	void Ariza::Ariza_Sifirla(Musteri &_musteri, int _Ariza_No,string _Ariza_Turu )
	{
		Ariza_No=_Ariza_No;
		Ariza_Turu=_Ariza_Turu;
		musteri=defaultMusteri;
	}
	
	
