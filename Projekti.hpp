#ifndef PROJEKTI_HPP_INCLUDED
#define PROJEKTI_HPP_INCLUDED
#include "Timovi.hpp"
#include "VodjaTima.hpp"
#include "Klijenti.hpp"
#include <vector>
#include <iostream>
#include <fstream>
class Projekti
{

protected:
    string naziv;
    int budzet;
    Klijenti klijenat;
    VodjaTima vodja;
    string rok;
public:
    Projekti(string Naziv, int Budzet, Klijenti Klijenat,VodjaTima Vodja,string Rok)
    {
        naziv=Naziv;
        budzet=Budzet;
        klijenat=Klijenat;
        vodja=Vodja;
        rok=Rok;
    }
    Projekti(string Naziv,int Budzet, string Rok)
    {

        naziv=Naziv;
        budzet=Budzet;
        rok=Rok;

    }
    string getNaziv()
    {
        return naziv;
    }
    string getRok()
    {
        return rok;
    }
    int getBudzet()
    {
        return budzet;
    }
    Klijenti getKlijenat()
    {
        return klijenat;
    }
    VodjaTima getVodja()
    {
        return vodja;
    }

    void setNaziv(string Naziv)
    {
        naziv=Naziv;
    }
    void setBudzet(int Budzet)
    {
        budzet=Budzet;
    }
    void setKlijenat(Klijenti K)
    {
        klijenat=K;
    }
    void setRok(string Rok)
    {
        rok=Rok;
    }
    void setVodja(VodjaTima Vodja)
    {
        vodja=Vodja;
    }

    bool PostojiProjekatUFajlu()
    {
        string linija;
        string nazivIzFajla;
        ifstream fajl("Projekti.txt");
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
    void DodajProjekatUFajl()
    {
        ofstream fajl;
        fajl.open ("Projekat.txt", ios_base::app);
        fajl <<getNaziv() <<";" << getBudzet() << ";" << getRok()<<endl;
        fajl.close();
    }



};


#endif // PROJEKTI_HPP_INCLUDED
