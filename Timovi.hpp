#ifndef TIMOVI_HPP_INCLUDED
#define TIMOVI_HPP_INCLUDED
#include "Radnik.hpp"
#include <vector>
class Timovi
{
protected:
    string naziv;
    vector<Radnik> r;
public:
    Timovi()
    {
        naziv="Nema naziv";
    }
    Timovi(string Naziv, vector<Radnik> R)
    {
        naziv=Naziv;
        r=R;
    }
    Timovi(const Timovi& t)
    {
        naziv=t.naziv;
        r=t.r;

    }

    string getNaziv()
    {
        return naziv;
    }

    vector<Radnik> getRadnici()
    {
        return r;
    }


    void setRadnici(vector<Radnik> R)
    {
        r=R;

    }
    int brojClanova()
    {
        return r.size();
    }

    void clanoviTima()
    {
        for(auto it=r.begin(); it<r.end(); it++)
        {
            cout<<*it<<" ";

            cout<<endl;

        }

    }

    friend ostream& operator<<(ostream& izlaz, const Timovi& o)
    {


        izlaz<<"Naziv tima : "<<o.naziv<<endl;
        izlaz<<"Clanovi tima su: "<<endl;
        for(auto it=o.r.begin(); it!=o.r.end(); it++ )
        {


            izlaz<<*it<<endl;
        }


        return izlaz;

    }


    void dodavanjeRadnika(Radnik o)
    {
        r.push_back(o);
        cout<<"Radnik je uspsno ubacen u tim"<<endl;
    }


    void uklanjanjeRadnika()
    {
        int x;
        cout<<"Unesite broj pozicije radnika kojeg zelite da uklonite: ";
        cin>>x;
        r.erase(r.begin()+x);
        cout<<"Radnik na mestu "<<x<<" je uklonjen"<<endl;
    }

    bool PostojiTimUFajlu()
    {
        string linija;
        string nazivIzFajla;
        ifstream fajl("Timovi.txt");
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


    /*  void DodajTimUFajl()
    {
      ofstream fajl;
     // fajl.open ("Timovi.txt", ios_base::app);
      fajl <<getNaziv() << ";" << getRadnici() << ";" << endl;
      fajl.close();
    } */




};


#endif // TIMOVI_HPP_INCLUDED
