#ifndef RADNICI_HPP_INCLUDED
#define RADNICI_HPP_INCLUDED
#include "Kvalifikacije.hpp"

enum  Pozicija{junior,medior,senior};

class Radnik{

    protected:
        string ime;
        string prezime;
        string adresa;
        Kvalifikacije k;
        Pozicija pozicija;
        double koefPlata;


    public:
        Radnik(): k(){
         ime="Nepoznato";
         prezime="Nepoznato";
         adresa="Nepoznato";
         koefPlata=0;
         pozicija=junior;

        }
     Radnik(string Ime,string Prezime,string Adresa, Kvalifikacije K,Pozicija Poz, double KoefPlata) : k(K){
         ime=Ime;
         prezime=Prezime;
         adresa=Adresa;
         k=K;
         pozicija=Poz;
         koefPlata=KoefPlata;

     }
    Radnik(const Radnik& r)
    {
        ime=r.ime;
        prezime=r.prezime;
        adresa=r.adresa;
        k=r.k;
        pozicija=r.pozicija;
        koefPlata=r.koefPlata;

    }
     string getIme(){
        return ime;
     }
     string getPrezime(){
        return prezime;
     }
      string getAdresa(){
        return adresa;
     }
     Pozicija getPozicija(){
        return pozicija;
     }
     Kvalifikacije getKvalifikacije(){
        return k;
     }
     double getKoefPlata(){
        return koefPlata;
     }


      void setIme(string Ime){
        ime=Ime;
      }
       void setPrezime(string Prezime){
        prezime=Prezime;
      }
       void setAdresa(string Adresa){
        adresa=Adresa;
      }
      void setKvalifikacije(Kvalifikacije K){
        k=K;
      }
      void setPozicija(Pozicija Poz){
        pozicija=Poz;
      }
      void setKoefPlata(double KoefPlata){
        koefPlata=KoefPlata;
      }

      double plata(int radnisati){
        return koefPlata*radnisati;
      }

};

#endif // RADNICI_HPP_INCLUDED