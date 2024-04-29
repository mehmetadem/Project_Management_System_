#include "Talep.h"
using namespace std;
void Talep::Talep_Duzenle(Ekip &_ekip,Ariza &_ariza,int i)
{
	if(i!=0)
	{
		ekip=_ekip;
		ariza=_ariza;
	}
	else
	{
		ekip.Ekip_Sifirlama(defaultCalisan,defaultCalisan,defaultCalisan);
		ariza.Ariza_Sifirla(defautMusteri);
	}
}
void Talep::Bilgiler()
{
	if(ariza.musteri.Get_Musteri_Firma()!=" ")
	{
		cout<<"Musteri: "<<ariza.musteri.Get_Musteri_Firma()<<endl;
		cout<<"Mudahele Edecek Ekip  "<<endl;
		ekip.Ekip_Bilgi();
		cout<<endl<<endl;
	}
}

