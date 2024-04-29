#ifndef ARIZA_H
#define ARIZA_H
#include <string>
#include  "Musteri.h"
using namespace std;

class Ariza
{
	private:
		int Ariza_No;
		string Ariza_Turu;
		string Konum;
		
	
		void Set_Ariza_No(int _Ariza_No);
		void Set_Ariza_Turu(string _Ariza_Turu);

		
	public:
		Musteri musteri;
		Musteri defaultMusteri;
		
		explicit Ariza(int _Ariza_No=0,string _Ariza_Turu=" ", string _Konum=" ");
		~Ariza();
	
		int Get_Ariza_No()const;
		string Get_Ariza_Turu()const;
		string Get_Ariza_Konum()const;
	
		void Ariza_Duzenle(int _Ariza_No,string _Ariza_Turu, Musteri &_musteri );
		void Ariza_Sifirla( Musteri& _musteri,int _Ariza_No=0,string _Ariza_Turu=" ");
		void Ariza_Bilgileri()const;
};
#endif

