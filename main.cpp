#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

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




vector<string> splitSen(string str, char c=';')
{
    string w = "";
    vector<string> v;
    for (auto rem : str)
    {
        if (rem==c)
        {
            v.push_back(w);
            w="";
        }
        else
        {
            w=w+rem;
        }
    }
    v.push_back(w);

    return v;
}
vector<string> split2(string NazivFajla)
{
    vector<string> v,line ;
    string linija;
    ifstream fajl (NazivFajla);
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            line=(splitSen(linija));
            v.insert(v.end(), line.begin(), line.end());
        }
        fajl.close();
    }

    else
        cout << "Neuspesno otvoren fajl";
    return v;
}

void citajTxt(string nazivFajla)
{
    string linija;
    ifstream fajl (nazivFajla.c_str());
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            cout << linija << '\n';
        }
        fajl.close();
    }

    else
        cout << "Neuspesno otvoren fajl";

}

void IspisKlijenata(vector <string> klijenti)
{

    for(auto i=klijenti.begin(); i!= klijenti.end(); i++)
    {
        cout<<*i<<endl;

    }



}

void IspisRadnika(vector <string> radnici)
{
    for(auto i=radnici.begin(); i!= radnici.end(); i++)
    {
        cout<<*i<<endl;

    }

}
void IspisProjekata(vector <string> projekti)
{

    for(auto i=projekti.begin(); i!= projekti.end(); i++)
    {

        cout<<*i<<endl;

    }

}

void IspisOpreme(vector <string> oprema)
{

    for(auto i=oprema.begin(); i!= oprema.end(); i++)
    {

        cout<<*i<<endl;

    }

}

void IspisiTim(vector <string> tim)
{

    for(auto i=tim.begin(); i!= tim.end(); i++)
    {

        cout<<*i<<endl;

    }

}

void NapraviRadnika()
{

    string ime, prezime,adresa,ostalo;
    double plata;
    bool html;
    bool c_;
    bool javascript;
    bool java;
    bool css;
    bool bazePodataka;


    cout<<"Unesite ime : "<<endl;
    cin>>ime;
    cout<<"Unesi prezime : "<<endl;
    cin>>prezime;
    cout<<"Unesi adresu"<<endl;
    cin>>adresa;
    cout<<"Unesi platu";
    cin>>plata;
    cout<<"Kvalifikacije radnika"<<endl;
    cout<<"Unesi 1 ako radnik zna Html ili 0 ako ne zna";
    cin>>html;
    cout<<"Unesi 1 ako radnik zna C ili 0 ako ne zna";
    cin>>c_;
    cout<<"Unesi 1 ako radnik zna JavaSripts ili 0 ako ne zna";
    cin>>javascript;
    cout<<"Unesi 1 ako radnik zna Java ili 0 ako ne zna";
    cin>>java;
    cout<<"Unesi 1 ako radnik zna CSS ili 0 ako ne zna";
    cout<<"Unesi 1 ako radnik zna BazePodataka ili 0 ako ne zna";
    cin>>bazePodataka;
    cout<<"Ostalo : ";
    cin>>ostalo;
    cout<<"Unesite znanje radnika (junior=0, medior=1, senior=2)";


    Kvalifikacije kva(html,c_,javascript,java,css,bazePodataka,ostalo);
    Radnik r(ime,prezime,adresa,kva,junior,plata);


    if(r.PostojiRadnikUFajlu()==false)
    {
        r.DodajRadnikaUFajl();
        cout<<"Uspeno je dodar radnik";
    }
    else
    {
        cout<<"Radnik vec postoji u fajlu";
    }



}

void NapraviKlijenta()
{

    string naziv;
    string adresa;
    string kontaktTelefon;
    string email;
    int tip;

    cout<<"Unesite naziv klijenta : "<<endl;
    cin>>naziv;
    cout<<"Unesite adresu klijenta : "<<endl;
    cin>>adresa;
    cout<<"Unesite kontakt telefon : "<<endl;
    cin>>kontaktTelefon;
    cout<<"Unesite email"<<endl;
    cin>>email;
    cout<<"Unesite tim preduzeca (malo=0,srednje=1, veliko=2) ";
    cin>>tip;
    TipPreduzeca val = static_cast<TipPreduzeca>(tip);

    Klijenti k(naziv,adresa,kontaktTelefon,email,val);

    if(k.PostojiKlijentUFajlu()==false)
    {
        k.DodajKlijentaUFajl();
        cout<<"Uspeno je dodat klijenat";
    }
    else
    {
        cout<<"Klijenat vec postoji u fajlu";
    }




}

void NapraviProjekat()
{

    string naziv,rok;
    double budzet;

    cout<<"Unesite naziv projekta : "<<endl;
    cin>>naziv;
    cout<<"Unesite budzet projekta : "<<endl;
    cin>>budzet;
    cout<<"Unesite rok projekta : "<<endl;
    cin>>rok;

    Projekti pro(naziv,budzet,rok);



    if(pro.PostojiProjekatUFajlu())
    {
        pro.DodajProjekatUFajl();
        cout<<"Uspeno je dodat projekat";
    }
    else
    {
        cout<<"Projekat vec postoji u fajlu";
    }

}

void NapraviOpremu()
{

    string naziv;
    bool vrsta;

    cout<<"Unesite naziv Opreme : "<<endl;
    cin>>naziv;
    cout<<"Unesite vrstu opreme (1-softver, 0- hardver) : "<<endl;
    cin>>vrsta;

    Oprema pro(naziv,vrsta);



    if(pro.PostojiOpremaUFajlu()==false)
    {
        pro.DodajOpremuUFajl();
        cout<<"Uspeno je dodata oprema";
    }
    else
    {
        cout<<"Oprema vec postoji u fajlu";
    }

}



void IspisiPrihode(vector <string> prihodi)
{

    for(auto i=prihodi.begin(); i!= prihodi.end(); i++)
    {

        cout<<*i<<endl;

    }

}

void IspisiRashode(vector <string> rashodi)
{

    for(auto i=rashodi.begin(); i!= rashodi.end(); i++)
    {

        cout<<*i<<endl;

    }

}

void ObracunajPlate(vector <string> radnici)
{
    double ukupno;
    for(int i=0; i< radnici.size(); i++)
    {
        if ((i+1) %6 == 0)
        {
            ukupno += atof(radnici[i].c_str());
        }
    }

    Rashodi r("Plate",ukupno);
    r.DodajRashodeUFajl();

    cout<<"Obracun Plata : ";
    cout<<ukupno<<endl;
}

void IzracunajDobit(vector <string> prihodi, vector <string> rashodi)
{
    double prih;
    double rash;

    for(int i=0; i< prihodi.size(); i++)
    {
        if ((i+1) % 2 == 0)
        {
            prih += atof(prihodi[i].c_str());
        }
    }

    for(int i=0; i< rashodi.size(); i++)
    {
        if ((i+1) % 2 == 0)
        {
            rash += atof(rashodi[i].c_str());
        }
    }

    cout<<"Prohodi : ";
    cout<<prih<<endl;

    cout<<"Rashodi : ";
    cout<<rash<<endl;

    cout<<"-----------------------------"<<endl;

    cout<<"Dobit : ";
    cout<<prih - rash<<endl;

}



int main()
{
    vector <string> klijenti=split2("Klijenti.txt");
    vector <string> radnici=split2("Radnici.txt");
    vector <string> projekti=split2("Projekat.txt");
    vector <string> oprema=split2("Oprema.txt");
    vector <string> prihodi=split2("Prihodi.txt");
    vector <string> rashodi=split2("Rashodi.txt");
    vector <string> timovi=split2("Timovi.txt");

    //Uvesti sve kancelarije kojima ce raspolagati kompanija.

    //Zatim cu radnike smestiti u vec napomenute kancelarije, po kojima ce se formirati i timovi.

    //Zatim cu dodati klijente koji ce dodeljivati projekte, a klijente ce pronalaziti sluzba za marketing.

    //Sluzba za marketing ce biti obican radnik koji ce imati odredjene razlicitosti.

    //Na projektima ce raditi timovi, s vodjom tima na celu koji ce snositi sve posledice.

    //Da bi timovi mogli da rade koristice odredjenu opremu, hardver i softberske alate, koji ce se uracunavati u rashode.

    //Prihodi ce se racunati iskljucivo na osnovu projekata i odrzavanja na mesecnom nivou istih, dakle projekat ce imati pocetnu cenu za koju je klijenat kupi i ugovor koliko ce morati da koristi isti za odredjenu cenu na mesecnom  nivou.

    //Rashodi ce se racunati na osnovu skoro svega, od obicne plate radnika do racuna, npr. potrosnja struje pa sve do komunalija ili do nekih nepredvidivih okolnosti kao na primer sto je ova sad.

    //Dobit firme cu izracunati tek na kraju, nakon striknog definisanja prihoda i rashoda.

    //Sa dobitom firme cu vrsiti funkcionalost tako sto cu manipulisati njenom vrednoscu i odredjidjivati u kom smeru ce novac ici.Npr. imacu knjigu utisaka u koju ce moci da pisu radnici i klijenti, pa cu tako napraviti prostor za napredak firme.

    //Od konkretnih funkcionalosti program ce posedovati npr, izracunavanje plate svakog pojedinacnog radnika, izracunavanje kranje dobiti u svakom trenutku, izracunavanjee dobiti u buducnosti ako firma nastavi u odredjenom smeru, upozoravati ako je odredjena licenca za softver pri kraju, ako klijenat kasni sa uplacivanjem, ako vodja tima ima los rejting ili ima rejting iznad proseka da se nagradi s odredjenim bonusima. Bukvalno ce raditi sve automatizovaano za jednu IT-firmu da se ne bi desilo da ista promakne i da ta firma ide u svom najbolljem mogucem smeru.





//    SoftverskiAlati s("Alat", "Verzija 2.0", true, true);


    /*s.dodavanjeOpreme(s);
    s.dodavanjeOpreme(s1);
    s.ispisOpreme();
    s.uklanjanjeOpreme();
    s.ispisOpreme();

    cout<<endl<<endl;
    cout<<o<<endl;
    s.pretraga();*/

    //


    /*  Oprema* o2=&s;
      o2->VrstaOpreme();  */
    int choice,subChoice;


    do
    {


        cout << endl
             << " 1 - Klijenti"<<endl
             << " 2 - Projekti"<<endl
             << " 3 - Oprema"<<endl
             << " 4 - Radnici"<<endl
             << " 5 - Timovi"<<endl
             << " 6 - Dobit"<<endl
             << " 0 - Izlaz iz programa"<<endl
             << " Odaberite opciju: "<<endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            do
            {
                cout<<endl
                    << " 1 - Lista klijenata"<<endl
                    << " 2 - Unos novog klijenta "<<endl
                    << " 9 - Vrati se na prethodnu stranu"<<endl
                    << " Odaberite opciju : ";
                cin>>subChoice;
                switch(subChoice)
                {
                case 1:
                    IspisKlijenata(klijenti);
                    break;

                case 2:
                    NapraviKlijenta();
                    break;
                }


            }
            while (subChoice !=9);

            break;
        case 2:

            do
            {
                cout<<endl
                    << " 1 - Lista projekata"<<endl
                    << " 2 - Unos novog projekta "<<endl
                    << " 9 - Vrati se na prethodnu stranu"<<endl
                    << " Odaberite opciju : ";
                cin>>subChoice;
                switch(subChoice)
                {
                case 1:

                    IspisProjekata(projekti);

                    break;

                case 2:
                    NapraviProjekat();
                    break;
                }

            }
            while (subChoice !=9);

            break;
        case 3:

            do
            {
                cout<<endl
                    << " 1 - Lista opreme"<<endl
                    << " 2 - Unos nove opreme "<<endl
                    << " 9 - Vrati se na prethodnu stranu"<<endl
                    << " Odaberite opciju : ";
                cin>>subChoice;
                switch(subChoice)
                {
                case 1:

                    IspisOpreme(oprema);

                    break;
                case 2:
                    NapraviOpremu();
                    break;
                }

            }
            while (subChoice !=9);

            break;
        case 4:

            do
            {
                cout<<endl
                    << " 1 - Lista radnika"<<endl
                    /*<< " 2 - Unos novog radnika "<<endl*/
                    << " 9 - Vrati se na prethodnu stranu"<<endl
                    << " Odaberite opciju : ";
                cin>>subChoice;
                switch(subChoice)
                {
                case 1:

                    IspisRadnika(radnici);

                    break;

                    /*case 2:
                        NapraviRadnika();
                        break;*/

                }

            }
            while (subChoice !=9);

            break;
        case 5:


            do
            {
                cout<<endl
                    << " 1 - Prikazi timove : "<<endl
                    << " 9 - Vrati se na prethodnu stranu"<<endl
                    << " Odaberite opciju : ";
                cin>>subChoice;
                switch(subChoice)
                {
                case 1:

                    IspisiTim(timovi);

                    break;
                }

            }
            while (subChoice !=9);

            break;

        case 6:


            do
            {
                cout<<endl
                    << " 1 - Prikazi prihode i njegovu vrednost"<<endl
                    << " 2 - Prikazi rashode i njegovu vrednost "<<endl
                    << " 3 - Obracun plata"<<endl
                    << " 4 - Izracunaj konacnu dobit"<<endl
                    << " 9 - Vrati se na prethodnu stranu"<<endl
                    << " Odaberite opciju : ";
                cin>>subChoice;
                switch(subChoice)
                {
                case 1:

                    IspisiPrihode(prihodi);

                    break;
                case 2:

                    IspisiRashode(rashodi);
                    break;
                case 3:
                    ObracunajPlate(radnici);
                    break;
                case 4:
                    IzracunajDobit(prihodi,rashodi);
                    break;
                }

            }
            while (subChoice !=9);

            break;

        default:
            cout << "Not a Valid Choice. \n"
                 << "Choose again.\n";
            break;
        }

    }
    while (choice !=0);


    /*     Oprema o("tako",true);

          Kancelarije k("1234",123);
          k.dodavanjeOpreme(o);
          cout<<k<<endl;

          vector <Radnik> r;
          Kvalifikacije kva(true,true,true,true,true,true,"ostalo");
          Radnik a("Aleksa","Siriski","Detos",kva,senior,1.65);



          Timovi timA("tima",r);

          timA.dodavanjeRadnika(a);
          cout<<timA;

            cout<<endl<<endl<<endl;
          VodjaTima b(a,timA,100,120);

          cout<<b;
          cout<<endl<<endl<<endl;
          cout<<endl<<endl<<endl;

          SoftverskiAlati sof("Aparat za kafat","2.0",false, true);
          HardverskaOprema har(1,2,true,"bla",false);

          cout<<sof;
          cout<<har;

         cout<<endl<<endl<<endl;
          cout<<endl<<endl<<endl;
     cout<<endl<<endl<<endl;
          cout<<endl<<endl<<endl;

          cout<<a;
          a.imaKvalifikacije();



          string av;
          string c;

          av="lala";

          av=av+"ababa";

          cout<<av<<endl;

          cout<<a.imaKvalifikacije();

          a.DodajRadnikaUFajl(); */


    return 0;
}
