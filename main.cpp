#include <iostream>

using namespace std;
/* Dodavanje klasa u main */
#include "Kompanija.hpp"
#include "Kancelarije.hpp"
#include "Radnik.hpp"
#include "Timovi.hpp"
#include "Projekti.hpp"
#include "SoftverskiAlati.hpp"
#include "Oprema.hpp"
#include "Klijenti.hpp"
#include "Prihodi.hpp"
#include "Rashodi.hpp"
#include "Kvalifikacije.hpp"
#include "VodjaTima.hpp"
/* Kraj dodavanja klasa u main */


int main()
{
    Kvalifikacije FrontEndProgramer(true,false,true,false,true,false,"balbal");
    Kvalifikacije Programer(true,true,true,true,true,true,"balbal");

    Radnik Pera("Pera","Peric","Negde daleko",FrontEndProgramer,junior,5.45);

    cout<<"Plata od: "<<Pera.getIme()<<" je "<<Pera.plata(100)<<"e"<<endl;

    Radnik Miki("Miki","Peric","Negde daleko od kuce",FrontEndProgramer,medior,10.45);

    Radnik Stefan("Stefan","K","Negde daleko od kuce",Programer,senior,15.45);

    Timovi timA("Tim A");

    Radnik r[3];

    r[0] = Pera;
    r[1] = Miki;
    r[2] = Stefan;


    timA.setRadnici(r);


    cout<<"Naziv tima je "<<timA.getNaziv()<<endl;

    VodjaTima StefanVT1(Stefan,timA,8,10);
    cout<<"Rejting vodje tima A je "<<StefanVT1.Rejting()<<endl;

    Timovi timB("Tim B");
    VodjaTima vodjaTima2(timB,7,10,"Stefan","K","",Programer,senior,12);
    cout<<"Rejting vodje tima B je "<<vodjaTima2.Rejting()<<endl;





    return 0;
}
