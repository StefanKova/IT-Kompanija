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
    int brojClanova()const
    {
        return r.size();
    }

        friend ostream& operator<<(ostream& izlaz, const Timovi& o)
    {

        izlaz<<"Naziv tima : "<<o.naziv<<endl;
        /* Profesorka ovaaj deo koda bas nisam znao,  pokusavao sam da ga resim ali nisam uspeo
        for(int i=0;i<o.brojClanova();i++){

            izlaz<<o.r[i]<<endl;
        } */

        return izlaz;

    }


};


#endif // TIMOVI_HPP_INCLUDED
