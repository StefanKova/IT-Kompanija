#ifndef VODJATIMA_HPP_INCLUDED
#define VODJATIMA_HPP_INCLUDED
#include "Radnik.hpp"
#include "Timovi.hpp"
#include "Kvalifikacije.hpp"

class VodjaTima: public Radnik
{
protected:
    Timovi tim;
    int realizovaniProjekti;
    int ukupnoProjekata;
public :

    VodjaTima(): Radnik()
    {

    }
    VodjaTima(Timovi Tim, int RealizovaniProjekti, int UkupnoProjekata, string Ime,string Prezime,string Adresa, Kvalifikacije K,Pozicija Poz, double KoefPlata): Radnik(Ime,Prezime,Adresa,K,Poz,KoefPlata)
    {
        tim=Tim;
        realizovaniProjekti = RealizovaniProjekti;
        ukupnoProjekata = UkupnoProjekata;
    }

    VodjaTima(const VodjaTima& vt):Radnik(vt)
    {
        tim=vt.tim;
        realizovaniProjekti = vt.realizovaniProjekti;
        ukupnoProjekata = vt.ukupnoProjekata;
    }

    VodjaTima(const Radnik& r, Timovi Tim, int RealizovaniProjekti,int UkupnoProjekata):Radnik(r)
    {
        tim=Tim;
        realizovaniProjekti = RealizovaniProjekti;
        ukupnoProjekata = UkupnoProjekata;
    }

    Timovi getTim()
    {
        return tim;
    }
    int getRealizovaniProjekti()
    {
        return realizovaniProjekti;
    }

    int getUkupnoProjekata()
    {
        return ukupnoProjekata;
    }

    void setTim(Timovi Tim)
    {
        tim=Tim;
    }
    void setRealizovaniProjekti(int RealizovaniProjekti)
    {
        realizovaniProjekti=RealizovaniProjekti;
    }
    void setUkupnoProjekata(int ukupnoProjekata)
    {
        ukupnoProjekata=ukupnoProjekata;
    }

    double Rejting()
    {
        if(ukupnoProjekata==0)
        {
            cout<<"Nije moguce dobiti rejting "<<endl;

        }

        double rejting = 1.0 * realizovaniProjekti / ukupnoProjekata;

        return rejting;
    }

    void dodajRealizovaneProjekte(int x)
    {
        realizovaniProjekti+=x;
        ukupnoProjekata+=x;
    }

    void dodajNerealizovaneProjekte(int x)
    {
        ukupnoProjekata+=x;
    }

    void Bonus(double x)
    {
        if(x>0.8)
        {
            koefPlata*=1.2;

        }
    }

    friend ostream& operator<<(ostream& izlaz, const VodjaTima& v)
    {
        string x;
        if(v.pozicija==0)
        {
            x="junior";
        }
        if(v.pozicija==1)
        {
            x="medior";
        }
        if(v.pozicija==2)
        {
            x="senior";
        }

        izlaz<<"Vodja Tima: "<<v.ime<<endl;
        izlaz<<"Prezime vodje : "<<v.prezime<<endl;
        izlaz<<"Adresa vodje je : "<<v.adresa<<endl;
        izlaz<<"Kvalifikacije vodje : "<<endl<<v.k;
        izlaz<<"Pozicija vodje : "<<x<<endl;
        izlaz<<"Koeficijent plate vodje je : "<<v.koefPlata<<endl;
        izlaz<<"Plata vodje je : "<<v.plata<<endl;
        izlaz<<v.tim;
        izlaz<<"Ukupno projekata: "<<v.ukupnoProjekata<<" "<<endl;
        izlaz<<"Realizovani projekti: "<<v.realizovaniProjekti<<endl;

        return izlaz;

    }



};


#endif // VODJATIMA_HPP_INCLUDED
