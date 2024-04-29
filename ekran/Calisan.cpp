#include <iostream>
#include <string>
#include "Calisan.h"
using namespace std;
	Calisan::Calisan(int ID,string isim, string soyisim,string gorev,int ekipno,float maas)
	{
		Calisan_ID=ID;
		Calisan_Isim=isim;
		Calisan_Soyisim=soyisim;
		Calisan_Gorev=gorev;
		EkipNo=ekipno;
		Calisan_Maas=maas;
	}
	Calisan::~Calisan()
	{
		cout<<"Calisan Silme Islemi Basarili !!"<<endl;
	}
	//----------------Set Islemleri
	void Calisan::Set_Calisan_ID(int _Calisan_ID)
	{
		if(_Calisan_ID==0 || _Calisan_ID<0)
		{
			cout<<"Calisan ID si 0 Veya 0 dan kucuk OLAMAZ!!"<<endl;
		}
		else
		{
			Calisan_ID=_Calisan_ID;
		}
	}
	void Calisan::Set_Calisan_Isim(string _Calisan_Isim)
	{
		if(_Calisan_Isim.length()<=2)
		{
			cout<<"Calisan Ismi 2 karakterden az OLAMAZ!!"<<endl;
		}
		else
		{
			Calisan_Isim=_Calisan_Isim;
		}
	}
	void Calisan::Set_Calisan_Soyisim(string _Calisan_Soyisim)
	{
		if(_Calisan_Soyisim.length()<=2)
		{
			cout<<"Calisan Soyismi 2 karakterden az OLAMAZ!!"<<endl;
		}
		else
		{
			Calisan_Soyisim=_Calisan_Soyisim;
		}
	}
	void Calisan::Set_Calisan_Gorev(string _Calisan_Gorev)
	{
		if(	_Calisan_Gorev=="Y" || _Calisan_Gorev=="y" ||
			_Calisan_Gorev=="T" || _Calisan_Gorev=="t" ||
			_Calisan_Gorev=="Yazilimci"  || _Calisan_Gorev=="Teknisyen"|| _Calisan_Gorev=="Yonetici")
		{
			if(_Calisan_Gorev=="Y"|| _Calisan_Gorev=="y")
			{
				Calisan_Gorev="Yazilimci";
			}
			else if(_Calisan_Gorev=="T"||_Calisan_Gorev=="t")
			{
				Calisan_Gorev="Teknisyen";
			}
			else
			{
				Calisan_Gorev=_Calisan_Gorev;
			}
		}
		else
		{
			cout<<"GECERSÝZ GOREVLENDÝRME !!"<<endl;
		}
	}
	void Calisan::Set_EkipNo(int _EkipNo)
	{
		if( _EkipNo<0)
		{
			cout<<"Ekip Numarasi 0 dan kucuk OLAMAZ!!"<<endl;
		}
		else
		{
			EkipNo=_EkipNo;
		}
	}
	void Calisan::Set_Calisan_Maas(float _Calisan_Maas)
	{
			if(_Calisan_Maas==0 || _Calisan_Maas<0)
		{
			cout<<"Calisan Maasi 0 Veya 0 dan kucuk OLAMAZ!!"<<endl;
		}
		else
		{
			Calisan_Maas=_Calisan_Maas;
		}
	}

//------------------------Get ISlemleri
	int Calisan::Get_Calisan_ID()const
	{
		return Calisan_ID;
	}
	string Calisan::Get_Calisan_Isim()const
	{
		return Calisan_Isim;
	}
	string Calisan::Get_Calisan_Soyisim()const
	{
		return Calisan_Soyisim;
	}
	string Calisan::Get_Calisan_Gorev()const
	{
		return Calisan_Gorev;
	}
	int Calisan::Get_EkipNo()const
	{
		return EkipNo;
	}
	float Calisan::Get_Calisan_Maas()const
	{
		return Calisan_Maas;
	}
	

	
	//----------------Calisan Islemleri
	void Calisan::CalisanlarBilgi()const
	{
		if(Calisan_ID!=0)
		{
			cout<<endl;
			cout<<"ID: "<<Get_Calisan_ID()<<endl;
			cout<<"Isim: "<<Get_Calisan_Isim()<<endl;
			cout<<"Soy isim: "<<Get_Calisan_Soyisim()<<endl;
			cout<<"Gorev: "<<Get_Calisan_Gorev()<<endl;
			if(EkipNo==0)
			{
				cout<<"Bir Ekibe Dahil Edilmemis!"<<endl;
			}
			else
			{
				cout<<"Ekip: "<<Get_EkipNo()<<endl;
			}
				cout<<"Maas: "<<Get_Calisan_Maas()<<endl<<endl;
		}
	}
	
	void Calisan::CalisanDuzenleme(int _Calisan_ID,string _Calisan_Isim,string _Calisan_Soyisim,string _Calisan_Gorev,float _Calisan_Maas)
	{
		if(_Calisan_ID!=0)
		{
			Set_Calisan_ID(_Calisan_ID);
			Set_Calisan_Isim(_Calisan_Isim);
			Set_Calisan_Soyisim(_Calisan_Soyisim);
			Set_Calisan_Gorev(_Calisan_Gorev);
			Set_Calisan_Maas(_Calisan_Maas);
		}
		else
		{
			Calisan_ID=_Calisan_ID;
			Calisan_Isim=_Calisan_Isim;
			Calisan_Soyisim=_Calisan_Soyisim;
			Calisan_Gorev=_Calisan_Gorev;
			EkipNo=0;
			Calisan_Maas=_Calisan_Maas;
			
		}
		
	}
	void Calisan::CalisanDuzenleme(int Calisan_ID,string Calisan_Isim,string Calisan_Soyisim,string Calisan_Gorev,int EkipNo,float Calisan_Maas)
	{
		Set_Calisan_ID(Calisan_ID);
		Set_Calisan_Isim(Calisan_Isim);
		Set_Calisan_Soyisim(Calisan_Soyisim);
		Set_Calisan_Gorev(Calisan_Gorev);
		Set_EkipNo(EkipNo);
		Set_Calisan_Maas(Calisan_Maas);
	}
	bool Calisan::Calisan_Dogrulama()const 
	{
 	  return !Calisan_Isim.empty() && !Calisan_Soyisim.empty() && Calisan_ID!=0;
	}
	void Calisan::Maas_Degistir(float Yeni_Maas)
	{
		Set_Calisan_Maas(Yeni_Maas);
	}
