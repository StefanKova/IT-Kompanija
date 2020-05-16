#ifndef KOMPANIJA_HPP_INCLUDED
#define KOMPANIJA_HPP_INCLUDED


class Kompanija{

    protected:
        string naziv;
        int godinaOsnivanja;
        string www;
    public:
        Kompanija(){
         naziv="Nepoznat";
         godinaOsnivanja=0;
         www="Nepoznat";
        }
     Kompanija(string nazivKompanije,int godinaOsnivanjaKompanije, string wwwKompanije){
         naziv=nazivKompanije;
         godinaOsnivanja=godinaOsnivanjaKompanije;
         www=wwwKompanije;
     }
     string getNaziv(){
        return naziv;
     }
      int getGodinaOsnvianja(){
        return godinaOsnivanja;
     }
      string getWww(){
        return www;
     }
      void setNaziv(string nazivKompanije){
        naziv=nazivKompanije;
    }
     void setGodinaOsnivanjaKompanije(int godinaOsnivanjaKompanije){
        godinaOsnivanja=godinaOsnivanjaKompanije;
    }
     void setWwwKompanije(string wwwKompanije){
        www=wwwKompanije;
    }
    void Informacije()const{
        cout<<"Kompanija se zove"<<naziv<<", osnovana je"<<godinaOsnivanja<<", pristupiti na"<<www<<endl;
    }
};



#endif // KOMPANIJA_HPP_INCLUDED


