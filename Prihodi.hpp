#ifndef PRIHODI_HPP_INCLUDED
#define PRIHODI_HPP_INCLUDED
class Prihodi
{

protected:
    string naziv;
    double iznos;

public:
    Prihodi() {};
    Prihodi(string Naziv, double Iznos)
    {
        naziv=Naziv;
        iznos=Iznos;
    };
    Prihodi(const Prihodi& r)
    {
        naziv=r.naziv;
        iznos=r.iznos;
    }

    string getNaziv()
    {
        return naziv;
    }
    double getIznos(){return iznos;};

    void setNaziv(string Naziv)
    {
        naziv=Naziv;
    }
    void setIznos(double Iznos)
    {
        iznos=Iznos;
    }

        friend ostream& operator<<(ostream& izlaz, const Prihodi& o)
    {

        izlaz<<"Naziv prihoda : "<<o.naziv<<endl;
        izlaz<<"Iznos prihoda : "<<o.iznos<<endl;
        return izlaz;

    }



};


#endif // PRIHODI_HPP_INCLUDED
