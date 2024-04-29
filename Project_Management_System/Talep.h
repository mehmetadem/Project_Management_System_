#ifndef TALEP_H
#define TALEP_H
#include <iostream>
#include "Ariza.h"
#include "Ekip.h"
class Talep
{
	public:
		void Bilgiler();
		Ekip ekip;
		Ariza ariza;
		
		Musteri defautMusteri;
		Calisan defaultCalisan;
		
		void Talep_Duzenle( Ekip &_ekip , Ariza &_ariza ,int i = 0);
};

#endif 
