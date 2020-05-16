#ifndef SOFTVERSKIALATI_HPP_INCLUDED
#define SOFTVERSKIALATI_HPP_INCLUDED
#include "Oprema.hpp"
class SoftverskiAlati: public Oprema
{

protected:
    string verzija;
    bool aktivnaLicenca;
    vector <Oprema*> opreme;
public:

SoftverskiAlati(string Naziv, string Verzija, bool al):Oprema(Naziv,vrsta){
    naziv=Naziv;
    verzija=Verzija;
    aktivnaLicenca=al;
}

void VrstaOpreme(){
    Oprema::VrstaOpreme();
}
int identifikacija(){return 2;}

void dodavanjeOpreme(Oprema &o)
{
    opreme.push_back(&o);
    cout<<"Oprema dodata"<<endl;
}
void uklanjanjeOpreme()
{
    int x;
    cout<<"Unesite broj pozicije objekta koji zelite da uklonite: ";
    cin>>x;
    opreme.erase(opreme.begin()+x);
    cout<<"Oprema na mestu "<<x<<" je uklonjena"<<endl;
}
void pretraga()
{
    bool x;
    cout<<"Unesite 0 ako zelite da pretrazimo hardver, a neki veci broj ako zelite da pretrazimo softver: ";
    cin>>x;
    if(x)
    {
        cout<<"Pretraga je izvrsena, pronadjen je softver"<<endl;
    }
    else
        cout<<"Pretraga je izvrsena, pronadjen je hardver"<<endl;
}
void ispisOpreme()
{
    for(auto it=opreme.begin(); it!=opreme.end(); it++)
        cout<<**it<<" ";
}

};


#endif // SOFTVERSKIALATI_HPP_INCLUDED
