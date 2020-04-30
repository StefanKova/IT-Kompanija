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
    int brojClanova(){
        return r.size();
    }


};


#endif // TIMOVI_HPP_INCLUDED
