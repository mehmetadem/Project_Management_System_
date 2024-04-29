#include <iostream>
#include <string>
#include "Calisan.h"
#include "Ekip.h"
using namespace std;

    Ekip::Ekip(int _Ekip_No,string _Ekip_Gorev,float _Ekip_Maaliyet,string _Sube)
	{
    	Ekip_No=_Ekip_No;
    	Ekip_Gorev=_Ekip_Gorev;
    	Ekip_Maaliyet=_Ekip_Maaliyet;
    	Sube=_Sube;
	}
	
   	Ekip::~Ekip()
	{
		cout<<"Ekip Silindi !"<<endl;
   	}

  	//SET ISLEMLERI
   void Ekip::Set_Ekip_No(int _Ekip_No)
   {
   		if( _Ekip_No<=0)
	   	{
   			cout<<"Ekip No 0 veya O'dan kucuk OLAMAZ!!"<<endl;
   			cout<<"Ekip No:::"<<_Ekip_No<<endl<<endl;
  		}
   		else
   		{
   	 	Ekip_No=_Ekip_No;
   		}
	}
    
    void Ekip::Set_Ekip_Sube(string _Sube)
    {
    	Sube=_Sube;
	}
		 
		 
    void Ekip::Set_Ekip_Gorev(string _Ekip_Gorev)
	{
    	if(_Ekip_Gorev=="Yazilimci"  || _Ekip_Gorev=="Teknisyen")
			
		{
			Ekip_Gorev=_Ekip_Gorev;
		}
		else
		{
			cout<<"GECERSÝZ GOREVLENDÝRME !!"<<endl;
		}
	}
	
	
	void Ekip::Set_Ekip_Maaliyet()
	{
		/*if(_Ekip_Maaliyet==0 || _Ekip_Maaliyet<0)
		{
			cout<<"Ekip Maaliyeti 0 veya 0'dan kucuk OLAMAZ!!"<<endl;
		}
		else
		{
	 		 float _Ekip_Maaliyet = (Calisanlar[i].Get_Calisan_Maas()/ 30) * 1.15;
        	cout << "Ekip Maaliyet " << _Ekip_Maaliyet<< endl;
			}*/
		
			//calisanlarýn maaslarý /30	%15 üstüne ekle
		  
       
	}
		
		
	void Ekip::Set_Calisan_Sayisi(int sayi)
	{
		
		Calisan_Sayisi=sayi;
	}
		
			   //GET ISLEMLERÝ
    int Ekip::Get_Ekip_No()const
    {
    	return Ekip_No;
	}
	string Ekip::Get_Sube()const
	{
		return Sube;
	}
    string Ekip::Get_Ekip_Gorev()const
	{
		return Ekip_Gorev;
	}
	float Ekip::Get_Ekip_Maaliyet()const
	{
		return Ekip_Maaliyet;
	}
	int Ekip::Get_Calisan_Sayisi()const
	{
		return Calisan_Sayisi;
	}
    //    EKÝP ÝSLEMLERÝ
    
    void Ekip::Ekip_Duzenleme(int _Ekip_No,string _Sube,string _Ekip_Gorev,Calisan &Calisana,Calisan &Calisanb,Calisan &Calisanc)
	{
	   	Set_Ekip_No(_Ekip_No);
   		Set_Ekip_Sube(_Sube);
	   	Set_Ekip_Gorev(_Ekip_Gorev);
		Calisanlar[1]=Calisana;
		Calisanlar[2]=Calisanb;
		Calisanlar[3]=Calisanc;
		Set_Calisan_Sayisi(3);
		Set_Ekip_Maaliyet();
	}
	    void Ekip::Ekip_Duzenleme(int _Ekip_No,string _Sube,string _Ekip_Gorev,Calisan &Calisana,Calisan &Calisanb)
	{
	   	Set_Ekip_No(_Ekip_No);
   		Set_Ekip_Sube(_Sube);
	   	Set_Ekip_Gorev(_Ekip_Gorev);
		Calisanlar[1]=Calisana;
		Calisanlar[2]=Calisanb;
		Set_Calisan_Sayisi(2);
		Set_Ekip_Maaliyet();
	}
	    void Ekip::Ekip_Duzenleme(int _Ekip_No,string _Sube,string _Ekip_Gorev,Calisan& Calisana)
	{
	   	Set_Ekip_No(_Ekip_No);
   		Set_Ekip_Sube(_Sube);
	   	Set_Ekip_Gorev(_Ekip_Gorev);
		Calisanlar[1]=Calisana;
		Set_Calisan_Sayisi(1);
		Set_Ekip_Maaliyet();
	}
		   
	//ekip bilgi
    	const void Ekip::Ekip_Bilgi()
	{
		if(Ekip_No!=0)
		{
			cout<<endl;
			cout<<"Ekip NO: "<<Get_Ekip_No()<<endl;
			int a=1;
			for(int i =0; i++ ; i<Get_Calisan_Sayisi())
			{
				cout<<a<<".Calisan : "<<Calisanlar[i].Get_Calisan_Isim()<<"	"<<Calisanlar[i].Get_Calisan_Soyisim()<<endl;
				a++;
			}
			
			cout<<"Ekip Gorev: "<<Get_Ekip_Gorev()<<endl;
			cout<<"Sube: "<<Get_Sube()<<endl;
		}
	}
    
    void Ekip::Ekip_Sifirlama(Calisan &Calisana,Calisan &Calisanb,Calisan &Calisanc,int _Ekip_No,string _Sube,string _Ekip_Gorev)
    {
    	Calisana=defaultCalisan;
    	Calisanb=defaultCalisan;
    	Calisanc=defaultCalisan;
    	Ekip_No=_Ekip_No;
    	Sube=_Sube;
    	Ekip_Gorev=_Ekip_Gorev;
    	Set_Calisan_Sayisi(0);
	}
    
    
    
 
    	
    
    
    
    
    
    
    
    
    
    
