#ifndef OPREMA_HPP_INCLUDED
#define OPREMA_HPP_INCLUDED
#include <vector>
#include <iostream>
#include <fstream>
class Oprema
{

protected:
    string naziv;
    bool vrsta;
public:

Oprema(string Naziv, bool V){
    naziv=Naziv;
    vrsta=V;
}


virtual void VrstaOpreme(){

    if(vrsta==true)
    {
        cout<<"Ovo je softverski alat";
    }
    else
    {
        cout<<"Ovo je hardver";
    }
}

    string getNaziv(){
        return naziv;
    }

    friend ostream& operator<<(ostream& izlaz, const Oprema& o)
    {
        string x;
        if(o.vrsta){
            x="Softver";
        }
        else{
            x="Hardver";
        }

        izlaz<<"Naziv : "<<o.naziv<<endl;
        izlaz<<"Vrsta opreme : "<<x<<endl;

        return izlaz;

    }
    string getVrsta()
    {
        if(vrsta==true)
        {
            return "Softver";
        }
        else
        {
            return "Hardver";
        }
    }

            bool PostojiOpremaUFajlu()
    {
        string linija;
        string nazivIzFajla;
        ifstream fajl("Oprema.txt");
        if (fajl.is_open())
        {
            while(getline(fajl, linija))
            {
                nazivIzFajla=" ";
                for(int i = 0; i < linija.size(); i++)
                {
                    if(linija[i] == ';')
                    {
                        break;
                    }
                    nazivIzFajla += linija[i];
                }
                if(naziv == nazivIzFajla)
                {
                    fajl.close();
                    return true;
                }
            }
            fajl.close();
            return false;
        }

        return true;
    }

       void DodajOpremuUFajl()
    {
        ofstream fajl;
        fajl.open ("Oprema.txt", ios_base::app);
        fajl <<getNaziv() << ";" << getVrsta()  << endl;
        fajl.close();
    }




};


#endif // OPREMA_HPP_INCLUDED
