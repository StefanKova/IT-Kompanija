#ifndef TIMOVI_HPP_INCLUDED
#define TIMOVI_HPP_INCLUDED
#include "Radnik.hpp"
class Timovi
{
protected:
    string naziv;
    Radnik r[];
public:
    Timovi()
    {
        naziv="Nema naziv";
    }
    Timovi(string Naziv)
    {
        naziv=Naziv;
    }
    Timovi(const Timovi& t)
    {
        naziv=t.naziv;

    }

    string getNaziv()
    {
        return naziv;
    }

    Radnik* getRadnici()
    {
        return r;
    }


    void setNaziv(string Naziv)
    {
        naziv=Naziv;
    }

    void setRadnici(Radnik* R)
    {
        int velicinaNiza =sizeof(R)/sizeof(R[0]);
        for (int i = 0; i < velicinaNiza; i++)
        {
            r[i]=R[i];
        }
    }
};


#endif // TIMOVI_HPP_INCLUDED
