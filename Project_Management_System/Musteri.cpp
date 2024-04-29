#include "Musteri.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
//**********************************************************************************************************************************************************************
	Musteri::Musteri(int _Musteri_ID,string _Musteri_Firma,string _Musteri_Yonetici_Isim,string _Musteri_Yonetici_Soyisim,string _Musteri_Iletisim_Numarasi,string _Musteri_Konum,float _Musteri_Uzaklik)
	{
		Musteri_ID=_Musteri_ID;
		Musteri_Firma=_Musteri_Firma;
		Musteri_Yonetici_Isim=_Musteri_Yonetici_Isim;
		Musteri_Yonetici_Soyisim=_Musteri_Yonetici_Soyisim;
		Musteri_Iletisim_Numarasi=_Musteri_Iletisim_Numarasi;
		Musteri_Konum=_Musteri_Konum;
		Musteri_Uzaklik=_Musteri_Uzaklik;
	}
	
	Musteri::~Musteri()
	{
		cout<<"Musteri Silme Islemi Basarili";
	}
	
	ostream &operator<<(ostream &output,Musteri &Musteri)
	{
		output<<"Musteri ID: "<<Musteri.Get_Musteri_ID()<<endl
		<<"Firma: "<<Musteri.Get_Musteri_Firma()<<endl
		<<"Yonetici Isim: "<<Musteri.Get_Musteri_Yonetici_Isim()<<endl
		<<"Yonetici Soyisim: "<<Musteri.Get_Musteri_Yonetici_Soyisim()<<endl
		<<"Iletisim Numarasi: "<<Musteri.Get_Musteri_Iletisim_Numarasi()<<endl
		<<"Konum: "<<Musteri.Get_Musteri_Konum()<<endl
		<<"Uzaklik: "<<Musteri.Get_Musteri_Uzaklik()<<endl;
		return output;
	}
//***********************************************************************************************************************************************************************
//----------------Set Islemleri
//***********************************************************************************************************************************************************************
	void Musteri::Set_Musteri_ID(int _Musteri_ID)
	{
		if(_Musteri_ID==0 || _Musteri_ID<0)
		{
			cout<<"Musteri ID si 0 Veya 0 dan kucuk OLAMAZ!!"<<endl;
		}
		else
		{
			Musteri_ID=_Musteri_ID;
		}
	}
	void Musteri::Set_Musteri_Firma(string _Musteri_Firma)
	{
		if(_Musteri_Firma.length()<=2)
		{
			cout<<"Firma Isimi 2 karakterden az OLAMAZ!!"<<endl;
		}
		else
		{
			Musteri_Firma=_Musteri_Firma;
		}
	}
		
	void Musteri::Set_Musteri_Yonetici_Isim(string _Musteri_Yonetici_Isim)
	{ 
			if(_Musteri_Yonetici_Isim.length()<=2)
		{
			cout<<"Musteri Ismi karakterden az OLAMAZ!!"<<endl;
		}
		else
		{
			Musteri_Yonetici_Isim=_Musteri_Yonetici_Isim;
		}	
	}
	
	void Musteri::Set_Musteri_Yonetici_Soyisim(string _Musteri_Yonetici_Soyisim)
	{
		if(_Musteri_Yonetici_Soyisim.length()<=2)
		{
			cout<<"Musteri Soyismi 2 karakterden az OLAMAZ!!"<<endl;
		}
		else
		{
			Musteri_Yonetici_Soyisim=_Musteri_Yonetici_Soyisim;
		}
	}
 	void Musteri::Set_Musteri_Iletisim_Numarasi(string _Musteri_Iletisim_Numarasi)
 	{
 		if(_Musteri_Iletisim_Numarasi.length()<10)
		{
			cout<<"Lutfen Numarayi Kontrol EDINIZ!!"<<endl;
		}
		else
		{
			Musteri_Iletisim_Numarasi=_Musteri_Iletisim_Numarasi;
		}
	}
	void Musteri::Set_Musteri_Konum(string _Musteri_Konum)
	{
		Musteri_Konum=_Musteri_Konum;
	}
	void Musteri::Set_Musteri_Uzaklik(float _Musteri_Uzaklik)
	{
		if(_Musteri_Uzaklik>0)
		{
			Musteri_Uzaklik=_Musteri_Uzaklik;
		}
		else
		{
			cout<<"Gecersiz Uzaklik"<<endl;
		}
	}

//************************************************************************************************************************************************
//-------------------------------------------------------- Get Fonks
//************************************************************************************************************************************************
 	int Musteri::Get_Musteri_ID()const
 	{
 		return Musteri_ID;
	}
	string Musteri::Get_Musteri_Firma()const
	{
		return Musteri_Firma;
	}
	string Musteri::Get_Musteri_Yonetici_Isim()const
	{
		return Musteri_Yonetici_Isim;
	}
	string Musteri::Get_Musteri_Yonetici_Soyisim()const
	{
		return Musteri_Yonetici_Soyisim;
	}
	string Musteri::Get_Musteri_Iletisim_Numarasi()const
	{
		return Musteri_Iletisim_Numarasi;
	}
	string Musteri::Get_Musteri_Konum() const
	{
		return Musteri_Konum;
	}
	float Musteri::Get_Musteri_Uzaklik()const
	{
		return Musteri_Uzaklik;
	}
//*************************************************************************************************************************************************
//---------------------------------------------------- Sistem Fonks
//*************************************************************************************************************************************************
void Musteri::Musteri_Duzenleme(int Musteri_ID,string Musteri_Firma,string Musteri_Yonetici_Isim,string Musteri_Yonetici_Soyisim,string Musteri_Iletisim_Numarasi,string Musteri_Konum,float Musteri_Uzaklik)
{
	Set_Musteri_ID(Musteri_ID);
	Set_Musteri_Firma(Musteri_Firma);
	Set_Musteri_Yonetici_Isim(Musteri_Yonetici_Isim);
	Set_Musteri_Yonetici_Soyisim(Musteri_Yonetici_Soyisim);
	Set_Musteri_Iletisim_Numarasi(Musteri_Iletisim_Numarasi);
	Set_Musteri_Konum(Musteri_Konum);
	Set_Musteri_Uzaklik(Musteri_Uzaklik);
}
void Musteri::Musteri_Duzenleme(int _Musteri_ID,string _Musteri_Firma,string _Musteri_Yonetici_Isim,string _Musteri_Yonetici_Soyisim,string _Musteri_Iletisim_Numarasi)
{
	if(_Musteri_ID!=0)
	{
		Set_Musteri_ID(_Musteri_ID);
 		Set_Musteri_Firma(_Musteri_Firma);
		Set_Musteri_Yonetici_Isim(_Musteri_Yonetici_Isim);
		Set_Musteri_Yonetici_Soyisim(_Musteri_Yonetici_Soyisim);
		Set_Musteri_Iletisim_Numarasi(_Musteri_Iletisim_Numarasi);
	}
	else 
	{
		Musteri_ID=_Musteri_ID;
		Musteri_Firma=_Musteri_Firma;
		Musteri_Yonetici_Isim=_Musteri_Yonetici_Isim;
		Musteri_Yonetici_Soyisim=_Musteri_Yonetici_Soyisim;
		Musteri_Iletisim_Numarasi=_Musteri_Iletisim_Numarasi;
		Musteri_Konum=" ";
		Musteri_Uzaklik=0;
	}

}
		
void Musteri::Musteri_Bilgi()const
{
	if(Get_Musteri_ID() !=0)
	{
		cout<<"Musteri ID: "<<Get_Musteri_ID()<<endl;
		cout<<"Firma: "<<Get_Musteri_Firma()<<endl;
		cout<<"Yonetici Isim: "<<Get_Musteri_Yonetici_Isim()<<endl;
		cout<<"Yonetici Soyisim: "<<Get_Musteri_Yonetici_Soyisim()<<endl;
		cout<<"Iletisim Numarasi: "<<Get_Musteri_Iletisim_Numarasi()<<endl;
		cout<<"Konum: "<<Get_Musteri_Konum()<<endl;
		cout<<"Uzaklik: "<<Get_Musteri_Uzaklik()<<endl<<endl;
	}
}

