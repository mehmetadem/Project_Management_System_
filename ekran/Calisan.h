// isim , soy isim, Ekip , Görev , Maaþ , Þube
#ifndef CALISAN_H
#define CALISAN_H

#include <iostream>
#include <string>

using namespace std;
class Calisan
{

	protected:
		int Calisan_ID;
		string Calisan_Isim;
		string Calisan_Soyisim;
		string Calisan_Gorev;
		int EkipNo;
		float Calisan_Maas;
		
	
		// Bilgilerin Alýnmasi
		
		void Set_Calisan_ID(int _Calisan_ID);
		void Set_Calisan_Isim(string _Calisan_Isim);
		void Set_Calisan_Soyisim(string _Calisan_Soyisim);
		void Set_Calisan_Gorev(string _Calisan_Gorev);
		void Set_Calisan_Maas(float _Calisan_Maas);

		
	public:
		static Calisan defaultCalisan;
		explicit Calisan(int ID=0,string isim=" ", string soyisim=" ",string gorev=" ",int ekipno=0,float maas=0);
		~Calisan();
		
		void Set_EkipNo(int _EkipNo);
		
		int Get_Calisan_ID()const;
		string Get_Calisan_Isim()const;
		string Get_Calisan_Soyisim()const;
		string Get_Calisan_Gorev()const;
		int Get_EkipNo()const;
		float Get_Calisan_Maas()const;
		
		void CalisanlarBilgi()const;
		void CalisanDuzenleme(int _Calisan_ID=0,string _Calisan_Isim=" ",string _Calisan_Soyisim=" ",string _Calisan_Gorev=" ",float _Calisan_Maas=0);
		void CalisanDuzenleme(int Calisan_ID,string Calisan_Isim,string Calisan_Soyisim,string Calisan_Gorev,int EkipNo,float Calisan_Maas);
		bool Calisan_Dogrulama()const;
		void Maas_Degistir(float Yeni_Maas);
};
#endif
