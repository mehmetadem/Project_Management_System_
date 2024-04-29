#include <iostream>
#include <string>
#include <limits.h>
#include "Sube.h"
#include "Calisan.h"
#include "Talep.h"
using namespace std;
	Sube::Sube(int Sube_ID, string Sube_Konum)
	{
		Sube_ID=Sube_ID;
		Sube_Konum=Sube_Konum;
	}
	Sube::~Sube()
	{
		cout<<"Sube Silme Islemi Basarili!"<<endl<<endl;
	}
// Sets GEts komutlarý	

		void Sube::Set_Sube_ID(int ID)
	{
		if(ID>0)
		{
			Sube_ID=ID;
		}
		else 
		{
			cout<<"Geceresiz ID!"<<endl<<endl;
		}
	}
	void Sube::Set_Sube_Konum(string _Sube_Konum)
	{
		if(_Sube_Konum.length()<=2)
		{
			cout<<"Geceresiz Konum!"<<endl<<endl;
		}
		else
		{
			Sube_Konum=_Sube_Konum;
		}
	}
	
	// GEts***********************
	
	int Sube::Get_Sube_ID()const
	{
		return Sube_ID;
	}
	string Sube::Get_Sube_Konum()const
	{
		return Sube_Konum;
	}
	string Sube::Get_Sube_Sifre()const
	{
		return Sube_Yoneticisi.Get_Yonetici_Sifre();	
	}

	//Fonks 
	void Sube::Sube_Duzenleme(int _Sube_ID, string Sube_Konum)
	{
		if(Sube_ID!=0)
		{
			Set_Sube_ID(Sube_ID);
			Set_Sube_Konum(Sube_Konum);
			Sube_Yoneticisi.Set_Yonetici_Sube(Sube_Konum);	
		}
		else
		{
			Sube_ID=_Sube_ID;
			Sube_Konum=Sube_Konum;
		}
	}
	void Sube::Sube_Duzenleme(int Sube_ID, string Sube_Konum, string Sifre,string _Calisan_Isim,string _Calisan_Soyisim,double _Calisan_Maas,string _Calisan_Gorev)
	{
		Set_Sube_ID(Sube_ID);
		Set_Sube_Konum(Sube_Konum);
		Sube_Yoneticisi.Yonetici_Duzenleme(Sube_ID,Sube_Konum,Sifre, _Calisan_Isim,_Calisan_Soyisim,_Calisan_Gorev,_Calisan_Maas);
	}
	void Sube::Sube_Detay()const
	{
		if(Sube_ID!=0)
		{
			cout<<"		Sube ID: "<<Sube_ID<<endl;
			Sube_Yoneticisi.Yonetici_Bilgi();
			if(Calisan_Sayisi()!=0)
			{
				cout<<"	Calisanlar Listesi "<<endl<<endl;
				for(int i=0;i<30;i++)
				{
					Calisanlar[i].CalisanlarBilgi();
				}
			}
		}
	}
	void Sube::Sube_Bilgi()const
	{
		if(Sube_ID!=0)
		{
			cout<<endl;
			cout<<"Sube ID: "<<Sube_ID<<endl;
			cout<<"Konum: "<<Sube_Konum<<endl<<endl;
			Sube_Yoneticisi.Yonetici_Bilgi();
		}
	}
	void Sube::SubeSil()
	{
		Sube_Duzenleme();
		for(int i=0;i<30;i++)
		{
			CalisanSil(i);
			MusteriSil(i);
		}
			YoneticiSil();
			EkipOlusturmaIslemi();
			cout<<"Sube Silindi"<<endl<<endl;
	}
	void Sube::EkipOlusturmaIslemi()
	{
	
		for(int a=0;a<30;a++)
		{
			YazilimciIndex[a]=0;
			TeknisyenIndex[a]=0;
		}
		int CalisanSayisi=0;
		CalisanSayisi=Calisan_Sayisi();
		int j=0;
		int k=0;
		
		for(int i=0;i<=CalisanSayisi;i++)
		{
			if(Calisanlar[i].Get_Calisan_Gorev()=="Yazilimci")
			{
				
				YazilimciIndex[j]=i;
				j++;		
			}
			else if(Calisanlar[i].Get_Calisan_Gorev()=="Teknisyen")
			{
				TeknisyenIndex[k]=i;
				k++;
			}
		}
		
		int b=1;
		int Sayac[3];
		for(int yaz=0;yaz<=CalisanSayisi;yaz+=3)
		{	Sayac[0]=yaz;
			Sayac[1]=yaz+1;
			Sayac[2]=yaz+2;
			if(		Calisanlar[YazilimciIndex[Sayac[0]]].Get_Calisan_ID()!=0 &&
					Calisanlar[YazilimciIndex[Sayac[1]]].Get_Calisan_ID()!=0 &&
					Calisanlar[YazilimciIndex[Sayac[2]]].Get_Calisan_ID()!=0)
			{	
				Ekipler[b].Ekip_Duzenleme(b,Sube_Konum,"Yazilimci",Calisanlar[YazilimciIndex[Sayac[0]]],Calisanlar[YazilimciIndex[Sayac[1]]],Calisanlar[YazilimciIndex[Sayac[2]]]);
				Calisanlar[YazilimciIndex[Sayac[0]]].Set_EkipNo(b);
				Calisanlar[YazilimciIndex[Sayac[1]]].Set_EkipNo(b);
				Calisanlar[YazilimciIndex[Sayac[2]]].Set_EkipNo(b);
				b++;
			}
			else if(Calisanlar[YazilimciIndex[Sayac[0]]].Get_Calisan_ID()!=0 &&
					Calisanlar[YazilimciIndex[Sayac[1]]].Get_Calisan_ID()!=0 &&
					Calisanlar[YazilimciIndex[Sayac[2]]].Get_Calisan_ID()==0)
			{
				Ekipler[b].Ekip_Duzenleme(b,Sube_Konum,"Yazilimci",Calisanlar[YazilimciIndex[Sayac[0]]],Calisanlar[YazilimciIndex[Sayac[1]]]);
				Calisanlar[YazilimciIndex[Sayac[0]]].Set_EkipNo(b);
				Calisanlar[YazilimciIndex[Sayac[1]]].Set_EkipNo(b);
				b++;
			}
			else if(Calisanlar[YazilimciIndex[Sayac[0]]].Get_Calisan_ID()!=0 &&
					Calisanlar[YazilimciIndex[Sayac[1]]].Get_Calisan_ID()==0 &&
					Calisanlar[YazilimciIndex[Sayac[2]]].Get_Calisan_ID()==0)
			{
				Ekipler[b].Ekip_Duzenleme(b,Sube_Konum,"Yazilimci",Calisanlar[YazilimciIndex[yaz]]);
				Calisanlar[YazilimciIndex[Sayac[0]]].Set_EkipNo(b);
				b++;
			}
	
		}
		// cCalisan Dizilierinin Bos Dolu olmasýna göre eþitleme düzenleme fonksiyonu içinde yapAd
		int Sayac2[3];
		for(int tek=0;tek<=CalisanSayisi;tek+=3)
		{	Sayac2[0]=tek;
			Sayac2[1]=tek+1;
			Sayac2[2]=tek+2;
			if(		Calisanlar[TeknisyenIndex[Sayac2[0]]].Get_Calisan_ID()!=0 &&
					Calisanlar[TeknisyenIndex[Sayac2[1]]].Get_Calisan_ID()!=0 &&
					Calisanlar[TeknisyenIndex[Sayac2[2]]].Get_Calisan_ID()!=0)
			{	
				Ekipler[b].Ekip_Duzenleme(b,Sube_Konum,"Teknisyen",Calisanlar[TeknisyenIndex[Sayac2[0]]],Calisanlar[TeknisyenIndex[Sayac2[1]]],Calisanlar[TeknisyenIndex[Sayac2[2]]]);
				Calisanlar[TeknisyenIndex[Sayac2[0]]].Set_EkipNo(b);
				Calisanlar[TeknisyenIndex[Sayac2[1]]].Set_EkipNo(b);
				Calisanlar[TeknisyenIndex[Sayac2[2]]].Set_EkipNo(b);
				b++;
			}
			else if(Calisanlar[TeknisyenIndex[Sayac2[0]]].Get_Calisan_ID()!=0 &&
					Calisanlar[TeknisyenIndex[Sayac2[1]]].Get_Calisan_ID()!=0 &&
					Calisanlar[TeknisyenIndex[Sayac2[2]]].Get_Calisan_ID()==0)
			{
				Ekipler[b].Ekip_Duzenleme(b,Sube_Konum,"Teknisyen",Calisanlar[TeknisyenIndex[Sayac2[0]]],Calisanlar[TeknisyenIndex[Sayac2[1]]]);
				Calisanlar[TeknisyenIndex[Sayac2[0]]].Set_EkipNo(b);
				Calisanlar[TeknisyenIndex[Sayac2[1]]].Set_EkipNo(b);
				b++;
			}
			else if(Calisanlar[TeknisyenIndex[Sayac2[0]]].Get_Calisan_ID()!=0 &&
					Calisanlar[TeknisyenIndex[Sayac2[1]]].Get_Calisan_ID()==0 &&
					Calisanlar[TeknisyenIndex[Sayac2[2]]].Get_Calisan_ID()==0)
			{
				Ekipler[b].Ekip_Duzenleme(b,Sube_Konum,"Teknisyen",Calisanlar[TeknisyenIndex[tek]]);
				Calisanlar[TeknisyenIndex[Sayac2[0]]].Set_EkipNo(b);
				b++;
			}			
		}
	}
	void Sube::MusteriBilgileri()const 
	{
		cout<<"	Konum : "<<Get_Sube_Konum()<<endl<<endl;
		for(int i =0 ; i<30 ;i++)
		{
			Musteriler[i].Musteri_Bilgi();
		}
	}
	
	int Sube::Calisan_Sayisi()const
	{
		int Sayac=0;
		for(int i=0;i<30;i++)
		{
			if(Calisanlar[i].Calisan_Dogrulama()==true)
			{ 
				Sayac++;
			}
		}
		return Sayac;
	}
	void Sube::Zam_Yap(float Zam_Orani)
	{
		Zam_Orani/=100;
		float Maas;
		for(int i=0 ; i<30 ; i++)
		{
		if(Calisanlar[i].Get_Calisan_ID()!=0)
		{
			Maas=Calisanlar[i].Get_Calisan_Maas();
			Maas=Maas*Zam_Orani+Maas;
			Calisanlar[i].Maas_Degistir(Maas);
		}
		}
	}
	
	void Sube::CalisanSil(int CalisanID)
	{
		Calisanlar[CalisanID].CalisanDuzenleme();
		cout<<"Calisan Silindi"<<endl<<endl;
	}
	void Sube::MusteriSil(int ID)
	{
		Musteriler[ID].Musteri_Duzenleme();
		cout<<"Musteri Silindi"<<endl<<endl;
	}
	void Sube::YoneticiSil()
	{
		Sube_Yoneticisi.Yonetici_Duzenleme();
		cout<<"Yonetici Silindi"<<endl<<endl;
	}
	
	int Sube::Aktif_Yazilim_Ariza_Sayisi()const
	{
		int sayac=0;
		for(int i=0;i<25;i++)
		{
			if(Yazilim_Ariza[i].Get_Ariza_No()!=0)
			{
				sayac++;
			}
		}
		return sayac;
	}
	int Sube::Aktif_Teknik_Ariza_Sayisi() const
	{
		int sayac=0;
		for(int i=0;i<25;i++)
		{
			if(Teknik_Ariza[i].Get_Ariza_No()!=0)
			{
				sayac++;
			}
		}
		return sayac;
	}
	int Sube::Yazilimci_Sayisi()const
	{
		int sayac=0;
		for(int i=0;i<25;i++)
		{
			if(Calisanlar[i].Get_Calisan_Gorev()=="Yazilimci")
			{
				sayac++;
			}
		}
		return sayac;
	}
	int Sube::Teknisyen_Sayisi()const
	{
		int sayac=0;
		for(int i=0;i<25;i++)
		{
			if(Calisanlar[i].Get_Calisan_Gorev()=="Teknisyen")
			{
				sayac++;
			}
		}
		return sayac;
	}

//*************************************************************************************************************************************************
//---------------------------------------------------- Ekiplere de ki eleman sayiya orana  ariza atama Fonks
//*************************************************************************************************************************************************

void Sube::Yazilim_Talepleri_Atanmasi()// for da dizi içi a ile iler deðiþti
{
	int sayac=0;
	int sayac2=0;
	for(int i=1;i<20;i++)
	{
		if(Ekipler[i].Get_Ekip_Gorev()=="Yazilimci")
		{
			YazilmciEkipleri[sayac]=i;
			sayac++;
		}
	}
	int Dolu_Yazilim_Arizalari[20];
	for(int i=1;i<20;i++)
	{
		if(Yazilim_Ariza[i].Get_Ariza_No()!=0)
		{
			Dolu_Yazilim_Arizalari[sayac2]=i;
			sayac2++;
		}
	}
	float Yazilimci_Sayisi_ = Yazilimci_Sayisi();
	float Aktif_Yazilim_Ariza_Sayisi_ = Aktif_Yazilim_Ariza_Sayisi();
	float KisiBasiYuk;
	KisiBasiYuk =Aktif_Yazilim_Ariza_Sayisi_/Yazilimci_Sayisi_ ;
	int Calisan_Sayi;

	int TamSayiKismi;
	float EkipYuku;
	float KontrolDegeri;//=TamSayiKismi+0.5;
	int sonuc;
	int CalisanSayisi;
	int YazilimArizalari=0;
	for(int i=0;i<sayac;i++)
	{
		Calisan_Sayi=Ekipler[YazilmciEkipleri[i]].Get_Calisan_Sayisi();
		EkipYuku=Ekipler[YazilmciEkipleri[i]].Get_Calisan_Sayisi()*KisiBasiYuk;
		TamSayiKismi=Ekipler[YazilmciEkipleri[i]].Get_Calisan_Sayisi()*KisiBasiYuk;
		KontrolDegeri=TamSayiKismi+0.5;
		if(TamSayiKismi%2==0)
		{
			if(EkipYuku>KontrolDegeri)
			{
				TamSayiKismi++;
				TamSayiKismi+=i;
				for(int a=i;a<TamSayiKismi;a++)
				{
					Yazilim_Talep[a].Talep_Duzenle(Ekipler[YazilmciEkipleri[i]],Yazilim_Ariza[Dolu_Yazilim_Arizalari[YazilimArizalari]],1);
										YazilimArizalari++;

				}
			}
			else
			{
				TamSayiKismi+=i;
				for(int a=i;a<TamSayiKismi;a++)
				{
					Yazilim_Talep[a].Talep_Duzenle(Ekipler[YazilmciEkipleri[i]],Yazilim_Ariza[Dolu_Yazilim_Arizalari[YazilimArizalari]],1);
										YazilimArizalari++;

				}
			}
		
		}
		else
		{
			if(EkipYuku>=KontrolDegeri)
			{
				TamSayiKismi+=i;
				TamSayiKismi++;
				for(int a=i;a<TamSayiKismi;a++)
				{
					Yazilim_Talep[a].Talep_Duzenle(Ekipler[YazilmciEkipleri[i]],Yazilim_Ariza[Dolu_Yazilim_Arizalari[YazilimArizalari]],1);
										YazilimArizalari++;

				}
			}
			else
			{
				TamSayiKismi+=i;
				for(int a=i;a<TamSayiKismi;a++)
				{
					
					Yazilim_Talep[a].Talep_Duzenle(Ekipler[YazilmciEkipleri[i]],Yazilim_Ariza[Dolu_Yazilim_Arizalari[YazilimArizalari]],1);
					YazilimArizalari++;
				}
			}
		}
	}
	
}
void Sube::Teknik_Talepleri_Atanmasi()
{
	int sayac=0;
	int sayac2=0;
	for(int i=1;i<20;i++)
	{
		if(Ekipler[i].Get_Ekip_Gorev()=="Teknisyen")
		{
			TeknisyenEkipleri[sayac]=i;
			sayac++;
		}
	}
	int Dolu_Teknik_Arizalari[20];
	for(int i=1;i<20;i++)
	{
		if(Teknik_Ariza[i].Get_Ariza_No()!=0)
		{
			Dolu_Teknik_Arizalari[sayac2]=i;
			sayac2++;
		}
	}
	float Teknisyen_Sayis=Teknisyen_Sayisi();
	float Aktif_Teknik_Ariza_Sayis=Aktif_Teknik_Ariza_Sayisi();
	float KisiBasiYuk;
	KisiBasiYuk=Aktif_Teknik_Ariza_Sayis/Teknisyen_Sayis;
	int TamSayiKismi;
	float EkipYuku;
	float KontrolDegeri;//=TamSayiKismi+0.5;
	int sonuc;
	int TeknikArizalari=0;
	int Calisan_Sayi;
		for(int i=0;i<sayac;i++)
	{
		Calisan_Sayi=Ekipler[TeknisyenEkipleri[i]].Get_Calisan_Sayisi();
		EkipYuku=Calisan_Sayi*KisiBasiYuk;
		TamSayiKismi=Ekipler[TeknisyenEkipleri[i]].Get_Calisan_Sayisi()*KisiBasiYuk;
		KontrolDegeri=TamSayiKismi+0.5;
	//	cout<<"Calisan_Sayi"<<Calisan_Sayi<<endl<<"EkipYuku"<<EkipYuku<<endl<<TamSayiKismi<<endl<<KontrolDegeri<<"KontrolDegeri"<<endl;
		if(TamSayiKismi%2==0)
		{
			if(EkipYuku>KontrolDegeri)
			{
				TamSayiKismi=TamSayiKismi+i+1;
				for(int a=i;a<TamSayiKismi;a++)
				{

					Teknik_Talep[a].Talep_Duzenle(Ekipler[TeknisyenEkipleri[i]],Teknik_Ariza[Dolu_Teknik_Arizalari[TeknikArizalari]],1);
					TeknikArizalari++;

				}
			}
			else
			{
				TamSayiKismi+=i;
				for(int a=i;a<TamSayiKismi+i;a++)
				{

					Teknik_Talep[a].Talep_Duzenle(Ekipler[TeknisyenEkipleri[i]],Teknik_Ariza[Dolu_Teknik_Arizalari[TeknikArizalari]],1);
															TeknikArizalari++;

				}
			}
		
		}
		else
		{
			if(EkipYuku>=KontrolDegeri)
			{
				TamSayiKismi+=i;
				TamSayiKismi++;
				for(int a=i;a<TamSayiKismi;a++)
				{

					Teknik_Talep[a].Talep_Duzenle(Ekipler[TeknisyenEkipleri[i]],Teknik_Ariza[Dolu_Teknik_Arizalari[TeknikArizalari]],1);
															TeknikArizalari++;

				}
			}
			else
			{				
				TamSayiKismi+=i;
				for(int a=i;a<TamSayiKismi;a++)
				{
					Teknik_Talep[a].Talep_Duzenle(Ekipler[TeknisyenEkipleri[i]],Teknik_Ariza[Dolu_Teknik_Arizalari[TeknikArizalari]],1);
															TeknikArizalari++;

				}
			}
		}
	}
}
//*************************************************************************************************************************************************
//---------------------------------------------------- Ekiplere Ariza Mudahele Fonks
//*************************************************************************************************************************************************

void Sube::Teknik_Ekip_EnKisa_Yol(int EkipId)
{
	if(Ekipler[EkipId].Get_Ekip_No()!=0&& Ekipler[EkipId].Get_Ekip_Gorev()=="Teknisyen")
	{
		Teknik_Talepleri_Atanmasi();
	int sayac=1;//ekibe dusen msuteriyi verir
	int GidilecekMusteriId[9];
	GidilecekMusteriId[0]=0;
	for(int i=1;i<25;i++)
	{
		if(Ekipler[EkipId].Get_Ekip_No()==Teknik_Talep[i].ekip.Get_Ekip_No())
		{
			GidilecekMusteriId[sayac]=Teknik_Talep[i].ariza.musteri.Get_Musteri_ID();
			sayac++;
		}
	}
	int Matris=sayac+1;
	
	int StandarGraf[9][9]=
	{
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8 },
    { 1, 0, 12, 0, 0, 0, 0, 11, 0 },
    { 2, 12, 0, 7, 0, 6, 0, 0, 20 },
    { 3, 0, 7, 0, 9, 14, 0, 0, 0 },
    { 4, 0, 0, 9, 0, 10, 0, 0, 0 },
    { 5, 0, 6, 14, 10, 0, 2, 0, 0 },
    { 6, 0, 0, 0, 0, 2, 0, 5, 6 },
    { 7, 11, 0, 0, 0, 0, 5, 0, 7 },
    { 8, 0, 20, 0, 0, 0, 6, 7, 0 }
	};
	int YeniGraf[Matris][Matris];
	for(int satir=0;satir<=sayac;satir++)
	{
		for(int sutun=0;sutun<=sayac;sutun++)
		{
			if(satir==0 || sutun==0)
			{
				if(satir==0)
				{
					YeniGraf[satir][sutun]=Teknik_Talep[sutun].ariza.musteri.Get_Musteri_Uzaklik();
				}
				if(sutun==0)
				{
					YeniGraf[satir][sutun]=Teknik_Talep[sutun].ariza.musteri.Get_Musteri_Uzaklik();
				}
			}
			else
			{
				YeniGraf[satir][sutun]=StandarGraf[satir][sutun];
			}			
		}
	}
	
	//src=0 V=matris
	int dist[Matris];
    bool sptSet[Matris];

    for (int i = 0; i < Matris; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[0] = 0;

    for (int sayi = 0; sayi < Matris - 1; sayi++) {
        int u, min = INT_MAX;
        for (int v = 0; v < Matris; v++)
        {
        	if (!sptSet[v] && dist[v] <= min)
                min = dist[v], u = v;
		}
            

        sptSet[u] = true;

        for (int v = 0; v < Matris; v++)
        {
        	if (!sptSet[v] && YeniGraf[u][v] && dist[u] != INT_MAX && dist[u] + YeniGraf[u][v] < dist[v])
                dist[v] = dist[u] + YeniGraf[u][v];
		}
            
    }
    int a;
	cout<<Ekipler[EkipId].Get_Ekip_No()<<". Ekip icin ";
    cout << "En Kisa Yol:\n";
    int dongu;
    dongu=Matris-1;
    for (int i = 0; i < dongu; i++)
    {
    	a=i+1;
    	cout << Teknik_Talep[i].ariza.musteri.Get_Musteri_Firma() << " : " << dist[a] <<"km"<< endl;
	}
	}
	
}

 void Sube::Yazilimci_Ekip_Kontrol_Sirasi(int EkipId)
 {
	if(Ekipler[EkipId].Get_Ekip_No()!=0&& Ekipler[EkipId].Get_Ekip_Gorev()=="Yazilimci")
	{
 		Yazilim_Talepleri_Atanmasi();
 		int sayac=0;//ekibe dusen msuteriyi verir
		int GidilecekMusteriId[9];
		for(int i=0;i<25;i++)
		{
			if(Ekipler[EkipId].Get_Ekip_No()==Yazilim_Talep[i].ekip.Get_Ekip_No())
			{
				GidilecekMusteriId[sayac]=Yazilim_Talep[i].ariza.musteri.Get_Musteri_ID();
				sayac++;
			}
		}
		cout<<Ekipler[EkipId].Get_Ekip_No()<<". Ekip ";
		cout<<"	Mudahele Sirasi"<<endl;
		for(int i=0;i<sayac;i++)
		{
			cout<<i<<". "<<Yazilim_Talep[i].ariza.musteri.Get_Musteri_Firma()<<endl;
		}	
	}
 
 }







