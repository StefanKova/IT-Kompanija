#ifndef RASHODI_HPP_INCLUDED
#define RASHODI_HPP_INCLUDED



class Rashodi
{

protected:

    string naziv;
    double iznos;
public:
    Rashodi(string Naziv, double Iznos){
        naziv=Naziv;
        iznos=Iznos;
    }

    double getIznos(){
        return iznos;
    }

     string getNaziv(){return naziv;};

     void setNaziv(string Naziv){naziv=Naziv;}

    void setIznos(double Iznos){
        iznos=Iznos;
    }


    void DodajRashodeUFajl()
    {
        ofstream fajl;
        fajl.open ("Rashodi.txt", ios_base::app);
        fajl <<getNaziv() << ";" << getIznos()<< endl;
        fajl.close();
    }

};


#endif // RASHODI_HPP_INCLUDED
