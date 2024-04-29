#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Sube.h"
#include "Paneller.h"
#include "Musteri.h"
using namespace std;

void Panel::KarsialamaMesaji()
{
	cout<<"					- Sisteme Hos Geldiniz -"<<endl;
	cout<<"	  Yetkili Giris Icin Konum ve Sifre Bilgilerinizi Giriniz! "<<endl;
	cout<<"	  Musteri Giris Icin Firma Isminizi ve Bagli Oldugunuz Konum Bilgilerini Giriniz"<<endl;
}
//*************************************************************************************************************************************************
//---------------------------------------------------- Giris Fonks
//*************************************************************************************************************************************************

void Panel::GirisEkrani()
{
	DosyaSenkronizasyon();
	KarsialamaMesaji();

	Admin.Yonetici_Duzenleme(0,"Admin","123456"," "," ","Yonetici",0);
	string girisAd,Sifre;
	cout<<"AD: ";
	cin>>girisAd;
	cout<<endl;
	cout<<"Parola: ";
	cin>>Sifre;
	
	if(girisAd==Admin.Get_Yonetici_Sube() && Sifre==Admin.Get_Yonetici_Sifre())
	{	
		system("cls");
		YoneticiEkran();
	}	
	if(SubeArama(girisAd)==Sifre)
	{
		system("cls");
		SubeEkran(SubeIndexBulma(girisAd));
	}
	else if(SubeArama(girisAd)!=" " && SubeArama(girisAd)!=Sifre)
	{
		system("cls");
		cout<<"Sifre Bilgilerinizi Kontrol Ediniz! "<<endl;
		GirisEkrani();
	}
	else if(Musteri_Arama(girisAd,Sifre)==true)
	{
		system("cls");
		Musteri_Menu(Musteri_Index(girisAd,Sifre),Sifre);
	}
	else
	{
		system("cls");
		cout<<"Kullanici Bulunamadi !"<<endl;
		GirisEkrani();
	}
}

//*************************************************************************************************************************************************
//---------------------------------------------------- Yonetici Fonks
//*************************************************************************************************************************************************

void Panel::YoneticiEkran()
{
	int SubeID;	
	cout<<"Yonetici Islemleri "<<endl;
	cout<<"[1].Sube Islemleri."<<endl;
	cout<<"[2]. Calisan Islemleri."<<endl;
	cout<<"[3]. Musteri Islemleri. "<<endl;
	cout<<"[4]. Aktif Arizalar."<<endl;
	cout<<"[5]. CIKIS"<<endl;
	
	int secim;
	cout<<"Secim: ";
	cin>>secim;
	switch(secim)
	{
		case 1:
			system("cls");
			SubeIslemleri();
			YoneticiEkran();
			break;
		case 2:
			system("cls");
			CalisanIslemleri(SubeSecimi());
			YoneticiEkran();
			break;
		case 3:
			system("cls");
			Musteri_Islemleri();
			YoneticiEkran();
		break;
		case 4:
			system("cls");
			Randevular();
			YoneticiEkran();
			break;
		default:
			system("cls");
			GirisEkrani();
			break;
	}
}

//*************************************************************************************************************************************************
//---------------------------------------------------- Yonetici Sube Fonks
//*************************************************************************************************************************************************
void Panel::SubeIslemleri()
{
	//subeleri goruntule , sube ekle sil, sube bilgileri guncelle 
	cout<<"	Sube Islemleri "<<endl;
	cout<<"[1].Sube Ekle"<<endl;
	cout<<"[2].Sube Sil."<<endl;
	cout<<"[3].Sube Duzenle."<<endl;
	cout<<"[4].Sube Bilgileri."<<endl;
	cout<<"[5].Yonetici Bilgilerini Guncelle."<<endl;
	cout<<"[6].CIKIS ."<<endl;
	int secim;
	cout<<"Secim: ";
	cin>>secim;
	switch(secim)
	{
		case 1:
			system("cls");
			SubeEkleme();
			break;
		case 2:
			system("cls");
			SubeListesi();
			SubeSilme();
			break;
		case 3:
			system("cls");
			SubeListesi();
			SubeDuzenleme();
			break;
		case 4:
			system("cls");
			SubeBilgileri();
			YoneticiEkran();
			break;
		case 5:
			system("cls");
			YoneticiDuzenleme(SubeSecimi());
			YoneticiEkran();
			break;
		default:
			YoneticiEkran();
			break;
	}
}
void Panel::SubeEkleme()
{
	static int ID=1;
	ID=SubeNumarasiEsleme();
	string Sube_Konum;
	float Maas;
	string Ad,Soyad,Sifre;
	cout<<"Konum: ";
	cin>>Sube_Konum;

	system("cls");
	cout<<"Sube Eklendi!"<<endl;
	cout<<"Yonetici Bilgileri"<<endl;
	cout<<"Yonetici Ad: ";
	cin>>Ad;
	cout<<"Yonetici Soyad:";
	cin>>Soyad;
	cout<<"Yonetici Sifre:";
	cin>>Sifre;
	cout<<"Maas: ";
	cin>>Maas;
	Subeler[ID].Sube_Duzenleme(ID,Sube_Konum,Sifre,Ad,Soyad,Maas);//ekip no sistemden
	SubeVerileriniYaz();
	ID++;
	SubeNumarasiTutucu(ID);
}
void Panel::SubeSilme()
{
	int ID;
	cout<<"Sube ID:";
	cin>>ID;
	if(Subeler[ID].Get_Sube_ID()!=0)
	{
		Subeler[ID].SubeSil();
		SubeVerileriniYaz();
	}
	else
	{
		cout<<"Sube Bulunamadi!"<<endl;
	}
}
/*	
*/
void Panel::SubeDuzenleme()
{
	int ID;
	float Maas;
	string Ad,Soyad,Sifre;
	string Sube_Konum;
	cout<<"Sube ID:";
	cin>>ID;
	if(Subeler[ID].Get_Sube_ID()==0)
	{
		cout<<"Sube Bulunamadi!"<<endl;
	}
	else
	{
		string Sube_Konum;

		cout<<"Konum: ";
		cin>>Sube_Konum;

		system("cls");
		cout<<"Sube Eklendi!"<<endl;
		cout<<"Yonetici Bilgileri"<<endl;
		cout<<"Yonetici Ad: ";
		cin>>Ad;
		cout<<"Yonetici Soyad:";
		cin>>Soyad;
		cout<<"Yonetici Sifre:";
		cin>>Sifre;
		cout<<"Maas: ";
		cin>>Maas;
		Subeler[ID].Sube_Duzenleme(ID,Sube_Konum,Sifre,Ad,Soyad,Maas);
		SubeVerileriniYaz();
		system("cls");
		cout<<"Sube Bilgileri Guncellendi!"<<endl;
	}
	
}
void Panel::SubeListesi()
{
	system("cls");
	for(int i =1; i<3;i++)
	{
		Subeler[i].Sube_Bilgi();
	}
}
void Panel::SubeBilgileri()
{
	system("cls");
	for(int i =1; i<3;i++)
	{
		Subeler[i].Sube_Detay();
	}
}
int Panel::SubeSecimi()
{
	int b;
	cout<<"Sube Islemleri"<<endl;
	for (int a=0;a<3;a++)
	{
		Subeler[a].Sube_Bilgi();
	}
	cout<<"Sube ID:";
	cin>>b;

	if(Subeler[b].Get_Sube_ID()==0)
	{
		system("cls");
		cout<<"Gecersiz Sube ID'si' !!"<<endl;
		b=0;
	}
	return b;
	
}
void Panel::SubeMusteriListesi(int SubeNumarasi)
{
	Subeler[SubeNumarasi].MusteriBilgileri();
}

string  Panel::SubeArama(string Konum)
{
	for(int i=0;i<3;i++)
	{
		if(Konum==Subeler[i].Get_Sube_Konum())
		{
			return Subeler[i].Get_Sube_Sifre();
		}
	}
	return " ";
}
int Panel::SubeIndexBulma(string Konum)
{
	for(int i=0;i<3;i++)
	{
		if(Konum==Subeler[i].Get_Sube_Konum())
		{
			return Subeler[i].Get_Sube_ID();
		}
	}
	return 0;		
}

void Panel::Randevular()
{
	
	for(int i=0;i<6;i++)
	{
		if(Subeler[i].Get_Sube_ID()!=0)
		{
			cout<<"	"<<Subeler[i].Get_Sube_Konum()<<endl;
			cout<<"	Yazilim Arizalari"<<endl<<endl;
			for(int a=0;a<25;a++)
			{
				Subeler[i].Yazilim_Talep[a].Bilgiler();
			}
		}
		
	}
	for(int i=0;i<6;i++)
	{
		if(Subeler[i].Get_Sube_ID()!=0)
		{
			cout<<"	"<<Subeler[i].Get_Sube_Konum()<<endl;
			cout<<"	 Teknik Arizalar"<<endl<<endl;
			for(int a=0;a<25;a++)
			{
				Subeler[i].Teknik_Talep[a].Bilgiler();
			}	
		}
		
	}
}
void Panel::EkipMudahale(int SubeID)
{
	for(int i=1;i<20;i++)
	{
		Subeler[SubeID].Teknik_Ekip_EnKisa_Yol(i);
	}
	for(int i=1;i<20;i++)
	{
		Subeler[SubeID].Yazilimci_Ekip_Kontrol_Sirasi(i);
	}
}
//*************************************************************************************************************************************************
//---------------------------------------------------- Calisan  Fonks
//*************************************************************************************************************************************************

void Panel::CalisanIslemleri(int SubeNumarasi)
{
	if(SubeNumarasi !=0 )
	{
	cout<<"Calisan Islemleri "<<endl;
	cout<<"[1].Calisan Ekleme."<<endl;
	cout<<"[2].Calisan Silme."<<endl;
	cout<<"[3].Calisan Bilgileri."<<endl;
	cout<<"[4].Calisan Duzenleme."<<endl;
	cout<<"[5].Calisanlara Zam Yap."<<endl;
	cout<<"[6].Geri. "<<endl;
	int secim;
	cout<<"Secim: ";
	cin>>secim;
	switch(secim)
	{
		case 1:
			system("cls");
			CalisanEkleme(SubeNumarasi);
			Subeler[SubeNumarasi].EkipOlusturmaIslemi();
			CalisanIslemleri(SubeNumarasi);
			break;
		case 2:
			system("cls");
			CalisanBilgileri(SubeNumarasi);
			CalisanSilme(SubeNumarasi);
			Subeler[SubeNumarasi].EkipOlusturmaIslemi();
			CalisanIslemleri(SubeNumarasi);
			break;
		case 3:
			system("cls");
			CalisanBilgileri(SubeNumarasi);
			CalisanIslemleri(SubeNumarasi);
			break;
		case 4:
			system("cls");
			CalisanBilgileri(SubeNumarasi);
			CalisanDuzenleme(SubeNumarasi);
			Subeler[SubeNumarasi].EkipOlusturmaIslemi();
			CalisanIslemleri(SubeNumarasi);
			break;
		case 5:
			system("cls");
			if(Subeler[SubeNumarasi].Calisan_Sayisi()!=0)
			{
				CalisanlaraZam(SubeNumarasi);
				CalisanIslemleri(SubeNumarasi);
			}
			else
			{
				system("cls");
				cout<<"Calisan Bulunamadi! "<<endl;
				CalisanIslemleri(SubeNumarasi);
			}
		case 6:
			if(SubeNumarasi==0)
			{
				YoneticiEkran();
			}
			else 
			{
				SubeEkran(SubeNumarasi);
			}
		default:
			system("cls");
			CalisanIslemleri(SubeNumarasi);
			break;	
	}
	}
}

void Panel::CalisanEkleme(int SubeNumarasi)
{
	static int ID=1;
	if(CalisanIdEsitleme()<0)
	{
		CalisanIdTutucu(1);
	}
	ID=CalisanIdEsitleme();
	
	string Calisan_Isim;
	string Calisan_Soyisim;
	string Calisan_Gorev;
	int EkipNo;
	double Calisan_Maas;
	
	cout<<"Isim: ";
	cin>>Calisan_Isim;
	cout<<"Soy Isim: ";
	cin>>Calisan_Soyisim;
	cout<<"Yazlimci-Teknisyen"<<endl;
	cout<<"Gorev: ";
	cin>>Calisan_Gorev;
	cout<<"Maas: ";
	cin>>Calisan_Maas;
	Subeler[SubeNumarasi].Calisanlar[ID].CalisanDuzenleme(ID,Calisan_Isim,Calisan_Soyisim,Calisan_Gorev,Calisan_Maas);
	CalisanVerileriniYaz(SubeNumarasi);
	ID++;
	CalisanIdTutucu(ID);
	system("cls");
	cout<<"Calisan Eklendi!"<<endl;
}
void Panel::CalisanSilme(int SubeNumarasi)
{
	int ID;
	cout<<"Calisan ID:";
	cin>>ID;
	if(Subeler[SubeNumarasi].Calisanlar[ID].Get_Calisan_ID()==0)
	{
		cout<<"Calisan Bulunamadi!"<<endl;
	}
	else
	{
		Subeler[SubeNumarasi].CalisanSil(ID);
		CalisanVerileriniYaz(SubeNumarasi);
		cout<<"Calisan Bilgileri Silindi!"<<endl;
	}
}
void Panel::CalisanDuzenleme( int SubeNumarasi )
{
	int ID;
	string Calisan_Isim;
	string Calisan_Soyisim;
	string Calisan_Gorev;
	int EkipNo;
	double Calisan_Maas;
	cout<<"Calisan ID:";
	cin>>ID;
	if(Subeler[SubeNumarasi].Calisanlar[ID].Get_Calisan_ID()==0)
	{
		cout<<"Calisan Bulunamadi!"<<endl;
	}
	else
	{
		cout<<"Isim: ";
		cin>>Calisan_Isim;
		cout<<"Soy Isim: ";
		cin>>Calisan_Soyisim;
		cout<<"Yazilimci-Teknisyen"<<endl;
		cout<<"Gorev: ";
		cin>>Calisan_Gorev;
		cout<<"Maas: ";
		cin>>Calisan_Maas;
		Subeler[SubeNumarasi].Calisanlar[ID].CalisanDuzenleme(ID,Calisan_Isim,Calisan_Soyisim,Calisan_Gorev,Calisan_Maas);
		CalisanVerileriniYaz(SubeNumarasi);
		system("cls");
		cout<<"Calisan Bilgileri Guncellendi!"<<endl;
	}
	
}
void Panel::CalisanlaraZam(int SubeNumarasi)
{
	float ZamOrani;
	cout<<"Yapilacak Olan Zam Orani:";
	cin>>ZamOrani;
	Subeler[SubeNumarasi].Zam_Yap(ZamOrani);
	CalisanVerileriniYaz(SubeNumarasi);
}
void Panel::CalisanBilgileri(int SubeNumarasi)
{
	for(int i=0;i<30;i++)
	{
		Subeler[SubeNumarasi].Calisanlar[i].CalisanlarBilgi();
	}
}

//*************************************************************************************************************************************************
//---------------------------------------------------- Sube Yoneticileri Fonks
//*************************************************************************************************************************************************
void Panel::SubeEkran(int SubeID)
{
	int Islem;
	
	cout<<"Hosgeldin "<<Subeler[SubeID].Sube_Yoneticisi.Get_Calisan_Isim()<<endl;
	cout<<"[1].Sube Bilgileri."<<endl;
	cout<<"[2].Sube Duzenle."<<endl;
	cout<<"[3].Calisan Islemleri."<<endl;
	cout<<"[4].Sifre Degistir."<<endl;
	cout<<"[5].Musteri Islemleri."<<endl;
	cout<<"[6].Musteri Duzenle."<<endl;
	cout<<"[7].Mudahale Listesi."<<endl;
	cout<<"[8].Cikis."<<endl;
	cout<<"Islem: ";
	cin>>Islem;
	
	switch (Islem)
	{
		case 1:
			system("cls");
			Subeler[SubeID].Sube_Detay();
			SubeEkran(SubeID);
			break;
		case 2:
			system("cls");
			Subeler[SubeID].Sube_Bilgi();
			SubeDuzenleme(SubeID);
			SubeEkran(SubeID);
			break;
		case 3:
			system("cls");
			CalisanIslemleri(SubeID);
			SubeEkran(SubeID);
			break;
		case 4:
			system("cls");
			SifreDegistir(SubeID);
			SubeEkran(SubeID);
	
		case 5:
			system("cls");
			SubeMusteriListesi(SubeID);
			Musteri_Islemleri();
		case 6:
			system("cls");
			MusteriListesi(SubeSecimi());
			MusteriDuzenleme(SubeSecimi());
			SubeEkran(SubeID);
		case 7:
			system("cls");
			EkipMudahale(SubeID);
			SubeEkran(SubeID);
		case 8:
			system("cls");
			GirisEkrani();
		default:
			system("cls");
			SubeEkran(SubeID);
			break;
			//musteri görunytule 
			//musteri duzenle
			
	}
}
void Panel::SubeDuzenleme(int SubeID)
{
	string Sube_Konum;
	cout<<"Konum: ";
	cin>>Sube_Konum;
	Subeler[SubeID].Sube_Duzenleme(SubeID,Sube_Konum);
	SubeVerileriniYaz();
	system("cls");
	cout<<"Sube Bilgileri Guncellendi!"<<endl;
}

void Panel::YoneticiDuzenleme(int SubeID)
{
	if(SubeID!=0)
	{
	string Ad,Soyad,Sifre;
	float Maas;
	cout<<"Yonetici Bilgileri"<<endl;
	cout<<"Ad: ";
	cin>>Ad;
	cout<<"Soyad:";
	cin>>Soyad;
	cout<<"Sifre:";
	cin>>Sifre;
	cout<<"Maas: ";
	cin>>Maas;
	Subeler[SubeID].Sube_Yoneticisi.Yonetici_Duzenleme(SubeID,Subeler[SubeID].Get_Sube_Konum(),Sifre,Ad,Soyad,"Yonetici",Maas);
	SubeVerileriniYaz();
	system("cls");
	cout<<"Guncelleme Basarili! "<<endl;
	}
	
}
void Panel::SifreDegistir(int SubeID)
{
	string	Sifre;
	cout<<"Yonetici Bilgileri"<<endl;
	cin>>Sifre;

	Subeler[SubeID].Sube_Yoneticisi.Yonetici_Duzenleme(Subeler[SubeID].Get_Sube_Konum(),Sifre);
	SubeVerileriniYaz();
	system("cls");
	cout<<"Sifre Guncellendi !"<<endl;
}
void Panel::MusteriListesi(int SubeNumarasi) //sube musteri listesi mi koyulmalý?
{
	for(int ID=0;ID<6;ID++)
	{
		if(Subeler[ID].Get_Sube_ID()!=0)
		{
			cout<<"		"<<Subeler[ID].Get_Sube_Konum()<<endl<<endl;
			for(int i=0;i<30;i++)
			{
				Subeler[SubeNumarasi].Musteriler[i].Musteri_Bilgi();
			}
			
		}
	}
}
void Panel::Musteri_Duzenleme(int SubeNumarasi)
{
	
	system("cls");
	int Musteri_ID;
	string Musteri_Firma,Musteri_Yonetici_Isim,Musteri_Yonetici_Soyisim,Musteri_Iletisim_Numarasi,Musteri_Konum;
	int Musteri_Uzaklik;
	if(SubeNumarasi!=0)
	{
		SubeMusteriListesi(SubeNumarasi);
		cout<<"Musteri ID: ";
		cin>>Musteri_ID;
		if(Subeler[SubeNumarasi].Musteriler[Musteri_ID].Get_Musteri_Firma()!=" ")
		{
			cout<<"Firma: ";
			cin>>Musteri_Firma;
			cout<<"	Iletisim Bilgileri"<<endl<<endl;
			cout<<"Isim: ";
			cin>>Musteri_Yonetici_Isim;
			cout<<"Soyad: ";
			cin>>Musteri_Yonetici_Soyisim;
			cout<<"Lutfen (5**) *** ** ** Formatinda Yaziniz!"<<endl;
			cout<<"Numara: ";
				Numara:
			cin>>Musteri_Iletisim_Numarasi;
			if(Musteri_Iletisim_Numarasi.length()!=10)
			{
				system("cls");
				cout<<"Gecersiz Numara Tusaldiniz!"<<endl;
				goto Numara;
			}
			cout<<"Konum: ";
			cin>>Musteri_Konum;
			if(SubeIndexBulma(Musteri_Konum)!= 0)
			{
				cout<<"Uzaklik: ";
				cin>>Musteri_Uzaklik;
				Subeler[SubeIndexBulma(Musteri_Konum)].Musteriler[Musteri_ID].Musteri_Duzenleme(Musteri_ID,Musteri_Firma,Musteri_Yonetici_Isim,Musteri_Yonetici_Soyisim,Musteri_Iletisim_Numarasi,Musteri_Konum,Musteri_Uzaklik);
				MusteriVerileriniYaz(SubeNumarasi);
				system("cls");
				cout<<"Musteri Bilgileri Guncellendi!"<<endl<<endl;
			}			
		}
	}
}
void Panel::SubeMusteriIslemleri()
{
	cout<<"	Musteri Islemleri "<<endl;
	cout<<"[1].Musteri Ekle"<<endl;
	cout<<"[2].Musteri Sil."<<endl;
	cout<<"[3].Musteri Duzenle."<<endl;
	cout<<"[4].Musteri Bilgileri."<<endl;
	cout<<"[6].CIKIS ."<<endl;
	int secim;
	cout<<"Secim: ";
	cin>>secim;
	switch(secim)
	{
		case 1:
			system("cls");
			Musteri_Ekleme();
			SubeMusteriIslemleri();
			break;
		case 2:
			system("cls");
			Musteri_Silme();
			SubeMusteriIslemleri();		
			break;
		case 3:
			system("cls");
			MusteriListesi(SubeSecimi());
			MusteriDuzenleme(SubeSecimi());
			SubeMusteriIslemleri();
			break;
		case 4:
			system("cls");
			Musteri_Bilgileri();
			SubeMusteriIslemleri();
			break;
		case 5:
			system("cls");
			Musteri_Bilgileri();
			MusteriDuzenleme(SubeSecimi());
			SubeMusteriIslemleri();
			break;
		case 6:
			system("cls");
			GirisEkrani();
		default:
			break;
	}
}

//*************************************************************************************************************************************************
//---------------------------------------------------- Yonetici Fonks
//*************************************************************************************************************************************************

void Panel::Musteri_Islemleri()
{
	cout<<"	Musteri Islemleri "<<endl;
	cout<<"[1].Musteri Ekle"<<endl;
	cout<<"[2].Musteri Sil."<<endl;
	cout<<"[3].Musteri Duzenle."<<endl;
	cout<<"[4].Musteri Bilgileri."<<endl;
	cout<<"[5].Musteri Tum Bilgileri Guncelle."<<endl;
	cout<<"[6].CIKIS ."<<endl;
	int secim;
	cout<<"Secim: ";
	cin>>secim;
	switch(secim)
	{
		case 1:
			system("cls");
			Musteri_Ekleme();
			Musteri_Islemleri();
			break;
		case 2:
			system("cls");
			Musteri_Silme();
			Musteri_Islemleri();		
			break;
		case 3:
			system("cls");
			MusteriListesi(SubeSecimi());
			MusteriDuzenleme(SubeSecimi());
			Musteri_Islemleri();
			break;
		case 4:
			system("cls");
			Musteri_Bilgileri();
			Musteri_Islemleri();
			break;
		case 5:
			system("cls");
			Musteri_Bilgileri();
			MusteriDuzenleme(SubeSecimi());
			Musteri_Islemleri();
			break;
		case 6:
			system("cls");
			GirisEkrani();
		default:
			break;
	}
}

void Panel::Musteri_Ekleme()
{
	static int ID=1;
	if(MusteriIdEsitleme()<0)
	{
		MusteriIdTutucu(1);
	}
	ID=MusteriIdEsitleme();
	string Musteri_Firma,Musteri_Yonetici_Isim,Musteri_Yonetici_Soyisim,Musteri_Iletisim_Numarasi,Musteri_Konum;
	float Musteri_Uzaklik;
	
	cout<<"Musteri Ekleme"<<endl<<endl;
	cout<<"Firma: ";
	cin>>Musteri_Firma;
	cout<<"	Iletisim Bilgileri"<<endl<<endl;
	cout<<"Isim: ";
	cin>>Musteri_Yonetici_Isim;
	cout<<"Soyad: ";
	cin>>Musteri_Yonetici_Soyisim;
	cout<<"Lutfen (5**) *** ** ** Formatinda Yaziniz!"<<endl;
	cout<<"Iletisim Numarasi : ";
	Numara:
	cin>>Musteri_Iletisim_Numarasi;
	if(Musteri_Iletisim_Numarasi.length()!=10)
	{
		system("cls");
		cout<<"Gecersiz Numara Tusaldiniz!"<<endl;
		goto Numara;
	}
	cout<<"Konum: ";
	cin>>Musteri_Konum;
	if(SubeIndexBulma(Musteri_Konum)!= 0)
	{
		cout<<"Uzaklik: ";
		cin>>Musteri_Uzaklik;
		Subeler[SubeIndexBulma(Musteri_Konum)].Musteriler[ID].Musteri_Duzenleme(ID,Musteri_Firma,Musteri_Yonetici_Isim,Musteri_Yonetici_Soyisim,Musteri_Iletisim_Numarasi,Musteri_Konum,Musteri_Uzaklik);
		MusteriVerileriniYaz(SubeIndexBulma(Musteri_Konum));
		system("cls");
		ID++;
		MusteriIdTutucu(ID);
		cout<<"Musteri Eklendi!!"<<endl;
	}
	else
	{
		system("cls");
		cout<<"Yakin Konumda Sube Bulunamadi."<<endl;
	}
	
}
void Panel::Musteri_Silme()
{
	int SubeNumarasi=SubeSecimi();
	system("cls");
	MusteriListesi(SubeNumarasi);
	int ID;
	cout<<"Musteri ID:";
	cin>>ID;
	if(Subeler[SubeNumarasi].Musteriler[ID].Get_Musteri_ID()==0)
	{
		cout<<"Musteri Bulunamadi!"<<endl;
	}
	else
	{
		Subeler[SubeNumarasi].MusteriSil(ID);
		MusteriVerileriniYaz(SubeNumarasi);
		cout<<"Musteri Bilgileri Silindi!"<<endl;
	}
		
	}
	
void Panel::MusteriDuzenleme(int SubeNumarasi)
{
	system("cls");
	int Musteri_ID;
	string Musteri_Firma,Musteri_Yonetici_Isim,Musteri_Yonetici_Soyisim,Musteri_Iletisim_Numarasi;
	if(SubeNumarasi!=0)
	{
		SubeMusteriListesi(SubeNumarasi);
		cout<<"Musteri ID: ";
		cin>>Musteri_ID;
		if(Subeler[SubeNumarasi].Musteriler[Musteri_ID].Get_Musteri_Firma()!=" ")
		{
			cout<<"Firma: ";
			cin>>Musteri_Firma;
			cout<<"	Iletisim Bilgileri"<<endl<<endl;
			cout<<"Isim: ";
			cin>>Musteri_Yonetici_Isim;
			cout<<"Soyad: ";
			cin>>Musteri_Yonetici_Soyisim;
			cout<<"Lutfen (5**) *** ** ** Formatinda Yaziniz!"<<endl;
			cout<<"Numara: ";
			cin>>Musteri_Iletisim_Numarasi;
			Subeler[SubeNumarasi].Musteriler[Musteri_ID].Musteri_Duzenleme(Musteri_ID,Musteri_Firma,Musteri_Yonetici_Isim,Musteri_Yonetici_Soyisim,Musteri_Iletisim_Numarasi);
			MusteriVerileriniYaz(SubeNumarasi);
			system("cls");
			cout<<"Musteri Bilgileri Guncellendi!"<<endl<<endl;
		}	
	}
	
}
void Panel::Musteri_Bilgileri()
{
	for(int ID=0;ID<6;ID++)
	{
		if(Subeler[ID].Get_Sube_ID()!=0)
		{
			for(int i=0;i<30;i++)
			{
				if(Subeler[ID].Musteriler[i].Get_Musteri_ID()!=0)
				{
					Subeler[ID].Musteriler[i].Musteri_Bilgi();
				}
				else
				{
					continue;
				}
			}
		}
		
	}
	
}

//*************************************************************************************************************************************************
//---------------------------------------------------- Musteri Fonks
//*************************************************************************************************************************************************
bool Panel::Musteri_Arama(string Firma_Ismi, string konum)
{
	for(int sube=1;sube<3;sube++)
	{
		for(int musteri=1;musteri<30;musteri++)
		{
			if(Subeler[sube].Musteriler[musteri].Get_Musteri_Firma()==Firma_Ismi && Subeler[sube].Get_Sube_Konum()==konum)
			{
				return true;
			}
		}
	}
	return false;
}
int Panel::Musteri_Index(string Firma_Ismi, string konum)
{
	for(int sube=1;sube<3;sube++)
	{
		for(int musteri=1;musteri<30;musteri++)
		{
			if(Subeler[sube].Musteriler[musteri].Get_Musteri_Firma()==Firma_Ismi && Subeler[sube].Get_Sube_Konum()==konum)
			{
				return musteri;
			}
		}
	}
	return 0;
}
void Panel::Musteri_Menu(int MusteriID,string Konum)
{
	int choice,SubeId=SubeIndexBulma(Konum);
	cout<<"		"<<Subeler[SubeId].Musteriler[MusteriID].Get_Musteri_Firma()<<endl;
	cout<<"[1].Ariza Bildir"<<endl;
	cout<<"[2].Ariza Iptal"<<endl;
	cout<<"[3].Ariza Bilgileri"<<endl;
	cout<<"[4].Cikis."<<endl;
	cout<<"Secim:";
	cin>>choice;
	switch(choice)
	{
		case 1:
			system("cls");
			Ariza_Bildir(Subeler[SubeId].Musteriler[MusteriID],Subeler[SubeId]);
			Subeler[SubeId].Yazilim_Talepleri_Atanmasi();
			Musteri_Menu(MusteriID,Konum);
			break;
		case 2:
			Ariza_Iptal(Subeler[SubeId].Musteriler[MusteriID],Subeler[SubeId]);
			Subeler[SubeId].Yazilim_Talepleri_Atanmasi();
			Musteri_Menu(MusteriID,Konum);
			break;
		case 3:
			Ariza_Bilgileri(Subeler[SubeId].Musteriler[MusteriID],Subeler[SubeId]);
			Musteri_Menu(MusteriID,Konum);
			break;
		case 4:
			GirisEkrani();
			break;
		default:
			break;
	}
}

//*************************************************************************************************************************************************
//---------------------------------------------------- Musteri  Ariza  Oluþturma Fonks
//*************************************************************************************************************************************************
void Panel::Ariza_Bildir(Musteri& musteri,Sube& sube)
{
	
	int choice;
	static int Id=1;
	cout<<"		Ariza Turu "
	<<endl<<"[1].Teknik Ariza"<<endl
	<<"[2].Yazilimsal Ariza"<<endl
	<<"[3].Cikis."<<endl;
	cout<<"Secim: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			Teknik_Ariza(musteri,sube);
			sube.Teknik_Ariza[Id].Ariza_Bilgileri();
			Ariza_Bildir(musteri,sube);
			break;
		case 2:
			Yazilim_Ariza(musteri,sube);
			Ariza_Bildir(musteri,sube);
			break;
		case 3:
			Musteri_Menu(musteri.Get_Musteri_ID(),sube.Get_Sube_Konum());
			break;
		default:
			Ariza_Bildir(musteri,sube);
			break;
	}
	
}
void Panel::Teknik_Ariza(Musteri& musteri,Sube& sube)
{	
	system("cls");
	static int Id=1;
	if(TeknikArizaIdEsitleme()<0)
	{
		TeknikArizaIdTutucu(1);
	}
	Id=TeknikArizaIdEsitleme();
	int kontrol=0;
	for(int i=1;i<=Id;i++)
	{
		if(sube.Teknik_Ariza[i].musteri.Get_Musteri_Firma()==musteri.Get_Musteri_Firma())
		{
			if(sube.Teknik_Ariza[i].Get_Ariza_Turu()=="Teknik" )
			{
				cout<<"Aktif bir Ariza Talebiniz Zaten Mevcut "<<endl;
				kontrol++;
			}
		}
	}
	if(kontrol==0)
	{

		sube.Teknik_Ariza[Id].Ariza_Duzenle(Id,"T",musteri);
		cout<<"Ekiplerimiz en kisa surede Mudahele edecektir."<<endl;
		sube.Teknik_Talepleri_Atanmasi();
		TeknikArizaVerileriniYaz(sube.Get_Sube_ID());
		Id++;
		TeknikArizaIdTutucu(Id);
	}
}
void Panel::Yazilim_Ariza(Musteri& _musteri,Sube& sube)
{
	system("cls");
	static int Id=1;
	if(YazilimArizaIdEsitleme()<0)
	{
		YazilimArizaIdTutucu(1);
	}
	Id=YazilimArizaIdEsitleme();
	int kontrol=0;
	for(int i=1;i<=Id;i++)
	{
		if(sube.Yazilim_Ariza[i].musteri.Get_Musteri_Firma()==_musteri.Get_Musteri_Firma())
		{
			if(sube.Yazilim_Ariza[i].Get_Ariza_Turu()=="Yazilim" )
			{
				system("cls");
				cout<<"Aktif bir Ariza Talebiniz Zaten Mevcut "<<endl;
				kontrol++;
			}
		}
	}
	if(kontrol==0)
	{
		sube.Yazilim_Ariza[Id].Ariza_Duzenle(Id,"Y",_musteri);
		sube.Yazilim_Ariza[Id].Ariza_Bilgileri();
		cout<<"Ekiplerimiz en kisa surede Mudahele edecektir."<<endl;
		sube.Yazilim_Talepleri_Atanmasi();
		YazilimArizaVerileriniYaz(sube.Get_Sube_ID());
		Id++;
		YazilimArizaIdTutucu(Id);
	}
}

//*************************************************************************************************************************************************
//---------------------------------------------------- Musteri  Ariza  Iptal Fonks
//*************************************************************************************************************************************************
void Panel::Ariza_Iptal(Musteri& musteri,Sube& sube)
{
	system("cls");
	int choice;
	static int Id=1;
	cout<<"		Ariza Turu "
	<<endl<<"[1].Teknik Ariza Iptal"<<endl
	<<"[2].Yazilimsal Ariza Iptal "<<endl
	<<"[3].Cikis."<<endl;
	cout<<"Secim: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			Teknik_Ariza_Iptal(musteri,sube);
			break;
		case 2:
			Yazilim_Ariza_Iptal(musteri,sube);
			break;
		case 3:
			Musteri_Menu(musteri.Get_Musteri_ID(),sube.Get_Sube_Konum());
			break;
		default:
			Ariza_Bildir(musteri,sube);
			break;
	}
}
void Panel::Teknik_Ariza_Iptal(Musteri& musteri,Sube& sube)
{
	system("cls");
	int kontrol=0;
	for(int i=1;i<25;i++)
	{
		if(sube.Teknik_Ariza[i].musteri.Get_Musteri_Firma()==musteri.Get_Musteri_Firma())
		{
			if(sube.Teknik_Ariza[i].Get_Ariza_Turu()=="Teknik" )
			{
				sube.Teknik_Ariza[i].Ariza_Sifirla(sube.Teknik_Ariza[i].defaultMusteri);
				cout<<"Teknik Ariza Talebiniz Iptal edildi!  "<<endl;
				sube.Teknik_Talepleri_Atanmasi();
				TeknikArizaVerileriniYaz(sube.Get_Sube_ID());

				kontrol++;
			}
		}
	}
	if(kontrol==0)
	{
		cout<<"Aktif Teknik Ariza Talebiniz Bulunmadi! "<<endl;
	}
}
void Panel::Yazilim_Ariza_Iptal(Musteri& musteri,Sube& sube)
{
	system("cls");
	int kontrol=0;
	for(int i=1;i<25;i++)
	{
		if(sube.Yazilim_Ariza[i].musteri.Get_Musteri_Firma()==musteri.Get_Musteri_Firma())
		{
			if(sube.Yazilim_Ariza[i].Get_Ariza_Turu()=="Yazilim" )
			{
				sube.Yazilim_Ariza[i].Ariza_Sifirla(sube.Yazilim_Ariza[i].defaultMusteri);
				cout<<"Yazilim Ariza Talebiniz Iptal edildi!  "<<endl;
				YazilimArizaVerileriniYaz(sube.Get_Sube_ID());
				kontrol++;
			}
		}
	}
	if(kontrol==0)
	{
		cout<<"Aktif Yazilim Ariza Talebiniz Bulunmadi! "<<endl;
	}
}
		

void Panel::Ariza_Bilgileri(Musteri& _musteri,Sube& sube)
{
	
	system("cls");
	//Subeler[1].Yazilim_Ariza[1].Ariza_Bilgileri();
	for(int i=1;i<20;i++)
	{
		
		if(sube.Yazilim_Ariza[i].musteri.Get_Musteri_Firma()==_musteri.Get_Musteri_Firma())
		{
			sube.Yazilim_Ariza[i].Ariza_Bilgileri();
		}
	}
	for(int i=1;i<20;i++)
	{
		
		if(sube.Teknik_Ariza[i].musteri.Get_Musteri_Firma()==_musteri.Get_Musteri_Firma())
		{
			sube.Teknik_Ariza[i].Ariza_Bilgileri();
		}
	}
}

//*************************************************************************************************************************************************
//---------------------------------------------------- Dosya Fonks
//*************************************************************************************************************************************************

void Panel::DosyaSenkronizasyon()
{
	string DosyaIsmi;
	ofstream SubeId;// text ba?lamak i?in kullan?l?r
	SubeId.open("SubeId.txt",ios::app);
	SubeId.close();
	
	ofstream CalisanId;
	CalisanId.open("CalisanId.txt",ios::app);
	CalisanId.close();
	
	ofstream MusteriId;
	MusteriId.open("MusteriId.txt",ios::app);
	MusteriId.close();
	
	ofstream TeknikArizaId;
	TeknikArizaId.open("TeknikArizaId.txt",ios::app);
	TeknikArizaId.close();
	
	ofstream YazilimArizaId;
	YazilimArizaId.open("YazilimArizaId.txt",ios::app);
	YazilimArizaId.close();
	
	ofstream SubeYaz;
	SubeYaz.open("SubeListesi.txt",ios::app);
	SubeYaz.close();
	SubeVerileriniAl();
	for(int i=1;i<6;i++)
	{
		if(Subeler[i].Get_Sube_ID()!=0)
		{
			DosyaIsmi=Subeler[i].Get_Sube_Konum()+"_CalisanListesi.txt";
			ofstream CalisanYaz;
			CalisanYaz.open((DosyaIsmi.c_str()),ios::app);
			CalisanYaz.close();
		}
	}
	CalisanVerileriniAl();
	for(int i=1;i<6;i++)
	{
		if(Subeler[i].Get_Sube_ID()!=0)
		{
			DosyaIsmi=Subeler[i].Get_Sube_Konum()+"_MusteriListesi.txt";
			ofstream MusteriYaz;
			MusteriYaz.open((DosyaIsmi.c_str()),ios::app);
			MusteriYaz.close();
		}
	}
	MusteriVerileriniAl();
	
	for(int i=1;i<6;i++)
	{
		if(Subeler[i].Get_Sube_ID()!=0)
		{
			DosyaIsmi=Subeler[i].Get_Sube_Konum()+"_TeknikArizaListesi.txt";
			ofstream TeknikAriza;
			TeknikAriza.open((DosyaIsmi.c_str()),ios::app);
			TeknikAriza.close();
		}	
	}
	TeknikArizaVerileriniAl();
	
		for(int i=1;i<6;i++)
	{
		if(Subeler[i].Get_Sube_ID()!=0)
		{
			DosyaIsmi=Subeler[i].Get_Sube_Konum()+"_YazilimArizaListesi.txt";
			ofstream YazilimAriza;
			YazilimAriza.open((DosyaIsmi.c_str()),ios::app);
			YazilimAriza.close();
		}	
	}
	YazilimArizaVerileriniAl();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------- Sube Dosya Fonks
//-------------------------------------------------------------------------------------------------------------------------------------------------
void Panel::SubeVerileriniYaz()
{
	int i;
	remove("SubeListesi.txt");
	ofstream Sube;
	Sube.open("SubeListesi.txt",ios::app);
	for(i=1;i<4;i++)
	{
		if(Subeler[i].Get_Sube_ID()!=0)
		{
			Sube<<Subeler[i].Get_Sube_ID()<<setw(20)<<Subeler[i].Get_Sube_Konum()<<setw(20)<<Subeler[i].Sube_Yoneticisi.Get_Yonetici_Sifre()<<setw(20)<<Subeler[i].Sube_Yoneticisi.Get_Calisan_Isim()<<setw(20)<<Subeler[i].Sube_Yoneticisi.Get_Calisan_Soyisim()<<setw(20)<<Subeler[i].Sube_Yoneticisi.Get_Calisan_Maas()<<setw(20)<<Subeler[i].Sube_Yoneticisi.Get_Calisan_Gorev()<<endl;
		}
	}
}

void Panel::SubeVerileriniAl()
{
	int Sube_ID;
	string Sube_Konum,Sifre,_Calisan_Isim,_Calisan_Soyisim,_Calisan_Gorev;
	double _Calisan_Maas;
	ifstream VerileriAl("SubeListesi.txt");
	while(!(VerileriAl.eof()))
	{
		VerileriAl>>Sube_ID>>Sube_Konum>>Sifre>>_Calisan_Isim>>_Calisan_Soyisim>>_Calisan_Maas>>_Calisan_Gorev;
		if(Subeler[Sube_ID].Get_Sube_Konum()!=" ")
		{
			Subeler[Sube_ID].Sube_Duzenleme(Sube_ID,Sube_Konum,Sifre,_Calisan_Isim,_Calisan_Soyisim,_Calisan_Maas,_Calisan_Gorev);
		}
	}
	
	VerileriAl.close();
}
void Panel::SubeNumarasiTutucu(int Id)
{
	remove("SubeId.txt");
	ofstream SubeId;
	SubeId.open("SubeId.txt",ios::app);
	SubeId<<Id;
}
int Panel::SubeNumarasiEsleme() //dosyadan dwe?er okuma
{
	int Id;
	ifstream SubeId("SubeId.txt");
	SubeId>>Id;
	
	return Id;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------- Calisan Dosya Fonks
//-------------------------------------------------------------------------------------------------------------------------------------------------
void Panel::CalisanVerileriniYaz(int SubeID)
{
	
	string DosyaIsmi;
	if(SubeID!=0)
	{
		DosyaIsmi=Subeler[SubeID].Get_Sube_Konum()+"_CalisanListesi.txt";
		remove((DosyaIsmi.c_str()));
		ofstream CalisanYaz;
		CalisanYaz.open((DosyaIsmi.c_str()),ios::app);
			for(int i=1;i<30;i++)
			{
				if(Subeler[SubeID].Calisanlar[i].Get_Calisan_ID()!=0)
				{
					CalisanYaz<<Subeler[SubeID].Calisanlar[i].Get_Calisan_ID()<<setw(20)<<Subeler[SubeID].Calisanlar[i].Get_Calisan_Isim()<<setw(20)<<Subeler[SubeID].Calisanlar[i].Get_Calisan_Soyisim()<<setw(20)<<Subeler[SubeID].Calisanlar[i].Get_Calisan_Gorev()<<setw(20)<<Subeler[SubeID].Calisanlar[i].Get_Calisan_Maas()<<endl;
				}
				else
				{
					continue;
				}
			}
			CalisanYaz.close();
		
	}
	else
	{
		for(int i=1;i<6;i++)
		{
		if(Subeler[i].Get_Sube_ID()!=0)
		{
			DosyaIsmi=Subeler[i].Get_Sube_Konum()+"_CalisanListesi.txt";
			remove((DosyaIsmi.c_str()));
			ofstream CalisanYaz;
			CalisanYaz.open((DosyaIsmi.c_str()),ios::app);
			for(int a=1;a<30;a++)
			{
				if(Subeler[i].Calisanlar[a].Get_Calisan_ID()!=0)
				{
					CalisanYaz<<Subeler[i].Calisanlar[a].Get_Calisan_ID()<<setw(20)<<Subeler[i].Calisanlar[a].Get_Calisan_Isim()<<setw(20)<<Subeler[i].Calisanlar[a].Get_Calisan_Soyisim()<<setw(20)<<Subeler[i].Calisanlar[a].Get_Calisan_Gorev()<<setw(20)<<Subeler[i].Calisanlar[a].Get_Calisan_Maas()<<endl;
				}
			}
			CalisanYaz.close();
		}
		}
		
	}
	
}
void Panel::CalisanVerileriniAl()
{
	int Calisan_ID,EkipNo;
	string Calisan_Isim,Calisan_Soyisim,Calisan_Gorev;
	float Calisan_Maas;
	string DosyaIsmi;
	
	for(int i=1;i<6;i++)
	{
		if(Subeler[i].Get_Sube_ID()!=0)
		{
			DosyaIsmi=Subeler[i].Get_Sube_Konum()+"_CalisanListesi.txt";
			
			ifstream CalisanVerileriniAl(DosyaIsmi.c_str());
			while(!(CalisanVerileriniAl.eof()))
 			{
				CalisanVerileriniAl>>Calisan_ID>>Calisan_Isim>>Calisan_Soyisim>>Calisan_Gorev>>Calisan_Maas;
				Subeler[i].Calisanlar[Calisan_ID].CalisanDuzenleme(Calisan_ID,Calisan_Isim,Calisan_Soyisim,Calisan_Gorev,Calisan_Maas);
			}
			Subeler[i].EkipOlusturmaIslemi();
			CalisanVerileriniAl.close();
		}
		
	}
	
	
}
void Panel::CalisanIdTutucu(int Id)
{
	remove("CalisanId.txt");
	ofstream CalisanId;
	CalisanId.open("CalisanId.txt",ios::app);
	CalisanId<<Id;
}
	
int Panel::CalisanIdEsitleme() //dosyadan dwe?er okuma
{
	int Id;
	ifstream CalisanId("CalisanId.txt");
	CalisanId>>Id;
	return Id;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------- Musteri Dosya Fonks
//-------------------------------------------------------------------------------------------------------------------------------------------------
void Panel::MusteriVerileriniYaz(int SubeID)
{
	
	string DosyaIsmi;
	if(SubeID!=0)
	{
		DosyaIsmi=Subeler[SubeID].Get_Sube_Konum()+"_MusteriListesi.txt";
		remove((DosyaIsmi.c_str()));
		ofstream MusteriYaz;
		MusteriYaz.open((DosyaIsmi.c_str()),ios::app);
			for(int i=1;i<30;i++)
			{
				if(Subeler[SubeID].Musteriler[i].Get_Musteri_ID()!=0)
				{																																																																																	
					MusteriYaz<<Subeler[SubeID].Musteriler[i].Get_Musteri_ID()<<setw(20)<<Subeler[SubeID].Musteriler[i].Get_Musteri_Firma()<<setw(20)<<Subeler[SubeID].Musteriler[i].Get_Musteri_Yonetici_Isim()<<setw(20)<<Subeler[SubeID].Musteriler[i].Get_Musteri_Yonetici_Soyisim()<<setw(20)<<Subeler[SubeID].Musteriler[i].Get_Musteri_Iletisim_Numarasi()<<setw(20)<<Subeler[SubeID].Musteriler[i].Get_Musteri_Konum()<<setw(20)<<Subeler[SubeID].Musteriler[i].Get_Musteri_Uzaklik()<<endl;
				}
				else
				{
					continue;
				}
			}
			MusteriYaz.close();
		
	}
	else
	{
		for(int i=1;i<6;i++)
		{
		if(Subeler[i].Get_Sube_ID()!=0)
		{
			DosyaIsmi=Subeler[i].Get_Sube_Konum()+"_MusteriListesi.txt";
			remove((DosyaIsmi.c_str()));
			ofstream MusteriYaz;
			MusteriYaz.open((DosyaIsmi.c_str()),ios::app);
			for(int a=1;a<30;a++)
			{
				if(Subeler[i].Musteriler[a].Get_Musteri_ID()!=0)
				{
					MusteriYaz<<Subeler[i].Musteriler[i].Get_Musteri_ID()<<setw(20)<<Subeler[i].Musteriler[i].Get_Musteri_Firma()<<setw(20)<<Subeler[i].Musteriler[i].Get_Musteri_Yonetici_Isim()<<setw(20)<<Subeler[i].Musteriler[i].Get_Musteri_Yonetici_Soyisim()<<setw(20)<<Subeler[i].Musteriler[i].Get_Musteri_Iletisim_Numarasi()<<setw(20)<<Subeler[i].Musteriler[i].Get_Musteri_Konum()<<setw(20)<<Subeler[i].Musteriler[i].Get_Musteri_Uzaklik()<<endl;
				}
			}
			MusteriYaz.close();
		}
		}
		
	}	
}
void Panel::MusteriVerileriniAl()
{
	int Musteri_ID;
	string Musteri_Firma,Musteri_Yonetici_Isim,Musteri_Yonetici_Soyisim,Musteri_Iletisim_Numarasi,Musteri_Konum;
	float Musteri_Uzaklik;

	string DosyaIsmi;
	
	for(int i=1;i<6;i++)
	{
		if(Subeler[i].Get_Sube_ID()!=0)
		{
			DosyaIsmi=Subeler[i].Get_Sube_Konum()+"_MusteriListesi.txt";
			
			ifstream MusteriVerileriniAl(DosyaIsmi.c_str());
			while(!(MusteriVerileriniAl.eof()))
 			{
				MusteriVerileriniAl>>Musteri_ID>>Musteri_Firma>>Musteri_Yonetici_Isim>>Musteri_Yonetici_Soyisim>>Musteri_Iletisim_Numarasi>>Musteri_Konum>>Musteri_Uzaklik;
				Subeler[i].Musteriler[Musteri_ID].Musteri_Duzenleme(Musteri_ID,Musteri_Firma,Musteri_Yonetici_Isim,Musteri_Yonetici_Soyisim,Musteri_Iletisim_Numarasi,Musteri_Konum,Musteri_Uzaklik);
			}
			Subeler[i].EkipOlusturmaIslemi();
			MusteriVerileriniAl.close();
		}
		
	}
	
	
}
void Panel::MusteriIdTutucu(int Id)
{
	remove("MusteriId.txt");
	ofstream MusteriId;
	MusteriId.open("MusteriId.txt",ios::app);
	MusteriId<<Id;
}
	
int Panel::MusteriIdEsitleme() //dosyadan dwe?er okuma
{
	int Id;
	ifstream MusteriId("MusteriId.txt");
	MusteriId>>Id;
	return Id;
}

void Panel::TeknikArizaVerileriniYaz(int SubeID)
{
	
	string DosyaIsmi;
	if(SubeID!=0)
	{
		DosyaIsmi=Subeler[SubeID].Get_Sube_Konum()+"_TeknikArizaListesi.txt";
		remove((DosyaIsmi.c_str()));
		ofstream TeknikAriza;
		TeknikAriza.open((DosyaIsmi.c_str()),ios::app);
			for(int i=1;i<25;i++)
			{
				if(Subeler[SubeID].Teknik_Ariza[i].Get_Ariza_No()!=0)
				{																																																																																	
					TeknikAriza<<Subeler[SubeID].Teknik_Ariza[i].Get_Ariza_No()<<setw(20)<<Subeler[SubeID].Teknik_Ariza[i].Get_Ariza_Turu()<<setw(20)<<Subeler[SubeID].Teknik_Ariza[i].musteri.Get_Musteri_ID()<<endl;				
				}
				
			}
			TeknikAriza.close();
	}
	else
	{
		for(int i=1;i<6;i++)
		{
		if(Subeler[i].Get_Sube_ID()!=0)
		{
			DosyaIsmi=Subeler[i].Get_Sube_Konum()+"_TeknikArizaListesi.txt";
			remove((DosyaIsmi.c_str()));
			ofstream TeknikAriza;
			TeknikAriza.open((DosyaIsmi.c_str()),ios::app);
			for(int i=1;i<25;i++)
			{
				if(Subeler[i].Teknik_Ariza[i].Get_Ariza_No()!=0)
				{																																																																																	
					TeknikAriza<<Subeler[SubeID].Teknik_Ariza[i].Get_Ariza_No()<<setw(20)<<Subeler[SubeID].Teknik_Ariza[i].Get_Ariza_Turu()<<setw(20)<<Subeler[SubeID].Teknik_Ariza[i].musteri.Get_Musteri_ID()<<endl;
				}
			}
			TeknikAriza.close();
		}
		}
		
	}	
}
void Panel::TeknikArizaVerileriniAl()
{
	int ArizaNo;
	string ArizaTuru;
	int Musteri_ID;

	string DosyaIsmi;
	
	for(int i=1;i<6;i++)
	{
		if(Subeler[i].Get_Sube_ID()!=0)
		{
			DosyaIsmi=Subeler[i].Get_Sube_Konum()+"_TeknikArizaListesi.txt";
			
			ifstream TeknikArizaVerileriniAl(DosyaIsmi.c_str());
			while(!(TeknikArizaVerileriniAl.eof()))
 			{
				TeknikArizaVerileriniAl>>ArizaNo>>ArizaTuru>>Musteri_ID;
				
				Subeler[i].Teknik_Ariza[ArizaNo].Ariza_Duzenle(ArizaNo,ArizaTuru,Subeler[i].Musteriler[Musteri_ID]);
			}
			
			TeknikArizaVerileriniAl.close();
		}
	}
	for(int i=1;i<6;i++)
	{
		if(Subeler[i].Get_Sube_ID()!=0)
		{	
			Subeler[i].Teknik_Talepleri_Atanmasi();
		}
	}
}
void Panel::TeknikArizaIdTutucu(int Id)
{
	remove("TeknikArizaId.txt");
	ofstream TeknikAriza;
	TeknikAriza.open("TeknikArizaId.txt",ios::app);
	TeknikAriza<<Id;
}
int Panel::TeknikArizaIdEsitleme()
{
	int Id;
	ifstream TeknikArizaId("TeknikArizaId.txt");
	TeknikArizaId>>Id;
	return Id;
}
//-----------------------------------------------------------------------------------------------
void Panel::YazilimArizaVerileriniYaz(int SubeID)
{
	
	string DosyaIsmi;
	if(SubeID!=0)
	{
		DosyaIsmi=Subeler[SubeID].Get_Sube_Konum()+"_YazilimArizaListesi.txt";
		remove((DosyaIsmi.c_str()));
		ofstream YazilimAriza;
		YazilimAriza.open((DosyaIsmi.c_str()),ios::app);
			for(int i=1;i<25;i++)
			{
				if(Subeler[SubeID].Yazilim_Ariza[i].Get_Ariza_No()!=0)
				{																																																																																	
					YazilimAriza<<Subeler[SubeID].Yazilim_Ariza[i].Get_Ariza_No()<<setw(20)<<Subeler[SubeID].Yazilim_Ariza[i].Get_Ariza_Turu()<<setw(20)<<Subeler[SubeID].Yazilim_Ariza[i].musteri.Get_Musteri_ID()<<endl;				
				}
				
			}
			YazilimAriza.close();
	}
	else
	{
		for(int i=1;i<6;i++)
		{
		if(Subeler[i].Get_Sube_ID()!=0)
		{
			DosyaIsmi=Subeler[i].Get_Sube_Konum()+"_YazilimArizaListesi.txt";
			remove((DosyaIsmi.c_str()));
			ofstream YazilimAriza;
			YazilimAriza.open((DosyaIsmi.c_str()),ios::app);
			for(int i=1;i<25;i++)
			{
				if(Subeler[i].Yazilim_Ariza[i].Get_Ariza_No()== 0)
				{																																																																																	
				}
				else
				{
					YazilimAriza<<Subeler[SubeID].Yazilim_Ariza[i].Get_Ariza_No()<<setw(20)<<Subeler[SubeID].Yazilim_Ariza[i].Get_Ariza_Turu()<<setw(20)<<Subeler[SubeID].Yazilim_Ariza[i].musteri.Get_Musteri_ID()<<endl;
				}
			}
			YazilimAriza.close();
		}
		}
		
	}	
}
void Panel::YazilimArizaVerileriniAl()
{
	int ArizaNo;
	string ArizaTuru;
	int Musteri_ID;

	string DosyaIsmi;
	
	for(int i=1;i<6;i++)
	{
		if(Subeler[i].Get_Sube_ID()!=0)
		{
			DosyaIsmi=Subeler[i].Get_Sube_Konum()+"_YazilimArizaListesi.txt";
			
			ifstream YazilimArizaVerileriniAl(DosyaIsmi.c_str());
			while(!(YazilimArizaVerileriniAl.eof()))
 			{
				YazilimArizaVerileriniAl>>ArizaNo>>ArizaTuru>>Musteri_ID;
				//if(Musteri)
				Subeler[i].Yazilim_Ariza[ArizaNo].Ariza_Duzenle(ArizaNo,ArizaTuru,Subeler[i].Musteriler[Musteri_ID]);
			}
			
			YazilimArizaVerileriniAl.close();
		}
	}
	for(int i=1;i<6;i++)
	{
		if(Subeler[i].Get_Sube_ID()!=0)
		{	
			Subeler[i].Yazilim_Talepleri_Atanmasi();
		}
	}
}
void Panel::YazilimArizaIdTutucu(int Id)
{
	remove("YazilimArizaId.txt");
	ofstream YazilimAriza;
	YazilimAriza.open("YazilimArizaId.txt",ios::app);
	YazilimAriza<<Id;
}
int Panel::YazilimArizaIdEsitleme()
{
	int Id;
	ifstream YazilimArizaId("YazilimArizaId.txt");
	YazilimArizaId>>Id;
	return Id;
}
