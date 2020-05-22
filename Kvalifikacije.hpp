#ifndef KVALIFIKACIJE_HPP_INCLUDED
#define KVALIFIKACIJE_HPP_INCLUDED

class Kvalifikacije
{

protected:
    bool html;
    bool c_;
    bool javascript;
    bool java;
    bool css;
    bool bazePodataka;
    string ostalo;
public:
    Kvalifikacije(bool htmlMTP, bool cMTP,bool javascriptMTP, bool javaMTP, bool cssMTP, bool bazaMTP, string ostaloMTP)
    {
        html=htmlMTP;
        c_=cMTP;
        javascript=javascriptMTP;
        java=javaMTP;
        css=cssMTP;
        bazePodataka=bazaMTP;
        ostalo=ostaloMTP;
    }
    Kvalifikacije()
    {
        html=false;
        c_=false;
        javascript=false;
        java=false;
        css=false;
        bazePodataka=false;
        ostalo="";
    }

    Kvalifikacije(const Kvalifikacije& kvalifikacije)
    {
        html=kvalifikacije.html;
        c_=kvalifikacije.c_;
        javascript=kvalifikacije.javascript;
        java=kvalifikacije.java;
        css=kvalifikacije.css;
        bazePodataka=kvalifikacije.bazePodataka;
        ostalo=kvalifikacije.ostalo;

    }
    bool getHtml()const
    {
        return html;
    }
    bool getC_()const
    {
        return c_;
    }
    bool getJavascripts()const
    {
        return javascript;
    }
    bool getJava()const
    {
        return java;
    }
    bool getCss()const
    {
        return css;
    }
    bool getBaza()const
    {
        return bazePodataka;
    }

    string getOstalo()const
    {
        return ostalo;
    }
    void setHtml(bool Html)
    {
        html=Html;
    }
    void setC_(bool C_)
    {
        c_=C_;
    }
    void setJavasripts(bool Javascripts)
    {
        javascript=Javascripts;
    }
    void setJava(bool Java)
    {
        java=Java;
    }
    void setCss(bool Css)
    {
        css=Css;
    }
    void setBaze(bool Baze)
    {
        bazePodataka=Baze;
    }

    string imaKvalifikacije()
    {
        string kvalifikacije= "";

        if(html==true)
        {
            kvalifikacije= kvalifikacije+ " HTML ";
        }
        if(c_==true)
        {
            kvalifikacije= kvalifikacije + " C ";
        }
        if(javascript==true)

        {
            kvalifikacije += " JAVASCRIPTS ";
        }
        if(java==true)
        {
            kvalifikacije= kvalifikacije +" JAVA ";
        }
        if(css==true)
        {
            kvalifikacije=kvalifikacije +" CSS ";
        }
        if(bazePodataka==true)
        {
            kvalifikacije =kvalifikacije + " BAZE ";
        }

        kvalifikacije = kvalifikacije + ostalo;


        return kvalifikacije;
    }
       /*     void DodajKvalifikacijeUFajl()
   {
        ofstream fajl;
        fajl.open ("Radnici.txt", ios_base::app);
        fajl << getIme() << ";" << getPrezime() << ";" << getAdresa()<< ";" << getPozicija()<<";"<<getKoefPlata()<<";"<<getPlata()<< endl;
        fajl.close();
    } */

};



#endif // KVALIFIKACIJE_HPP_INCLUDED
