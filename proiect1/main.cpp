#include <iostream>
#include<string.h>

using namespace std;

class Angajat
{
private:
    string nume;
    string prenume;
    int varsta;
    string meserie;    //bucatar, chelner etc
    int salariu;
    int nrLuni;        //de cate luni e angajat
    int *rating;       //rating pe luni      IL INDEXAM DE LA 1

public:
    Angajat()
    {
        //  rating = new int[1];   //initializam vectoru pt ca cand declaram fara sa initializam in main se cheama constr asta fara param si dupa la destruct nu are ce rating initial ca sa  poate da delete
        rating = NULL;
    }
    Angajat(string, string, int, string, int, int);       // rating nu se transmite ca param
    Angajat(const Angajat&);                              //constructor de copiere
    Angajat& operator=(Angajat&);                         //constructor de atribuire
    ~Angajat();                                           //destructor

    friend istream& operator>>(istream&, Angajat&);
    friend ostream& operator<<(ostream&, Angajat&);
    friend bool operator==(Angajat&, Angajat&);
    friend bool operator!=(Angajat&, Angajat&);

    void setNume(string nume)
    {
        this->nume = nume;
    }
    void setPreume(string prenume)
    {
        this->prenume = prenume;
    }
    void setVarsta(int varsta)
    {
        this->varsta =  varsta;
    }
    void setMeserie(string meserie)
    {
        this->meserie = meserie;
    }
    void setSalariu(int salariu)
    {
        this->salariu = salariu;
    }
    void setnrLuni(int nrLuni)
    {
        this->nrLuni = nrLuni;
    }
    void setRating(int val, int luna)
    {
        if(luna <= this->nrLuni)
        {
            cout<<"Ratingul pentru luna "<<luna<<" a fost modificat de la "<<this->rating[luna]<<" la "<<val<<" cu succes!"<<endl<<endl;
            this->rating[luna]= val;
        }
        else
            cout<<"Angajatul lucreaza de mai putin de "<<luna<<" luni. Ratingul nu a putut fi modificat!";
    }


    string getNume()
    {
        return this->nume;
    }
    string getPrenume()
    {
        return this->prenume;
    }
    int getVarsta()
    {
        return this->varsta;
    }
    string getMeserie()
    {
        return this->meserie;
    }
    int getSalariu()
    {
        return this->salariu;
    }
    int getnrLuni()
    {
        return this->nrLuni;
    }
    int getRating(int luna)
    {
        return this->rating[luna];
    }
};

Angajat::Angajat(string nume, string prenume, int varsta, string meserie, int salariu, int nrLuni)
{
    this->nume = nume;
    this->prenume = prenume;
    this->varsta = varsta;
    this->meserie = meserie;
    this->salariu = salariu;
    this->nrLuni = nrLuni;
    this->rating = new int[this->nrLuni + 1];

    cout<<"Introduceti ratingul pentru cele "<<this->nrLuni<<" luni!"<<endl;

    for(int luna = 1; luna <= this->nrLuni; luna++)
    {
        cout<<"Rating luna: "<<luna<<" : ";
        cin>>this->rating[luna];
    }
    cout<<endl;
}
Angajat::Angajat(const Angajat& obj)
{
    this->nume = obj.nume;
    this->prenume = obj.prenume;
    this->varsta = obj.varsta;
    this->meserie = obj.meserie;
    this->salariu = obj.salariu;
    this->nrLuni = obj.nrLuni;

    if(this->rating != nullptr)
        delete[] rating;

    this->rating = new int[this->nrLuni + 1];

    for(int luna = 1; luna <= this->nrLuni; luna++)
        this->rating[luna] = obj.rating[luna];
}

Angajat& Angajat::operator=(Angajat& obj)
{
    if(this != &obj)
    {
        this->nume = obj.nume;
        this->prenume = obj.prenume;
        this->varsta = obj.varsta;
        this->meserie = obj.meserie;
        this->salariu = obj.salariu;
        this->nrLuni = obj.nrLuni;

        this->rating = new int[this->nrLuni + 1];

        for(int luna = 1; luna <= this->nrLuni; luna++)
            this->rating[luna] = obj.rating[luna];

    }

    return *this;
}

Angajat::~Angajat()
{
    delete[] rating;
    //  cout<<"DELETED Angajat: "<<nume<<" "<<prenume<<endl;
}

istream& operator>>(istream& in, Angajat& angajat)
{
    cout<<"Nume(introduceti un cuvant): ";
    in>>angajat.nume;

    cout<<"Prenume(introduceti un cuvant): ";
    in>>angajat.prenume;

    cout<<"Varsta: ";
    in>>angajat.varsta;

    cout<<"Meserie (introduceti un cuvant): ";
    in>>angajat.meserie;

    cout<<"Salariu: ";
    in>>angajat.salariu;

    cout<<"Numar luni de cand este angajat (ulterior v-a trebui sa introduceti o valoare pt fiecare luna): ";
    in>>angajat.nrLuni;

    if(angajat.rating != nullptr)
        delete[] angajat.rating;

    angajat.rating = new int[angajat.nrLuni + 1];

    for(int luna = 1; luna <= angajat.nrLuni; luna++)
    {
        cout<<"Rating luna "<<luna<<": ";
        in>>angajat.rating[luna];
    }

    cout<<endl;
    return in;
}

ostream& operator<<(ostream& out, Angajat& angajat)
{
    out<<"Nume: "<<angajat.nume<<endl;
    out<<"Prenume: "<<angajat.prenume<<endl;
    out<<"Varsta: "<<angajat.varsta<<endl;
    out<<"Meserie (introduceti un cuvant): "<<angajat.meserie<<endl;
    out<<"Salariu: "<<angajat.salariu<<endl;
    out<<"Numar luni de cand este angajat: "<<angajat.nrLuni<<endl;

    for(int luna = 1; luna <= angajat.nrLuni; luna++)
        cout<<"Rating luna (un int)"<<luna<<" : "<<angajat.rating[luna]<<endl;

    out<<endl;
    // return out;
}

bool operator==(Angajat& angajat1, Angajat& angajat2)
{
    if(angajat1.nume == angajat2.nume && angajat1.prenume == angajat2.prenume)
        return true;

    return false;
}

bool operator!=(Angajat& angajat1, Angajat& angajat2)
{
    if(angajat1.nume != angajat2.nume || angajat1.prenume != angajat2.prenume)
        return true;

    return false;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Restaurant
{
private:
    string locatie;
    int id;                  //idu e per oras
    int nrAngajati;
    Angajat *angajati;       //INDEXAT DE LA 1

public:
    Restaurant()
    {
        angajati = NULL;
    }
    Restaurant(string, int, int);
    Restaurant(const Restaurant&);
    Restaurant& operator=(Restaurant&);
    ~Restaurant();

    friend istream& operator>>(istream&, Restaurant&);
    friend ostream& operator<<(ostream&, Restaurant&);
    friend bool operator==(Restaurant&, Restaurant&);
    friend bool operator!=(Restaurant&, Restaurant&);

    void setLocatie(string locatie)
    {
        this->locatie = locatie;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setnrAngajati(int nrAngajati)
    {
        this->nrAngajati = nrAngajati;
    }
    void setAngajat(Angajat& angajat, int pos)
    {
        if(pos <= this->nrAngajati)
        {
            cout<<"Angajatul "<<this->angajati[pos].getNume()<<" "<<this->angajati[pos].getPrenume()<<" a fost inlocuit cu "<<angajat.getNume()<<" "<<angajat.getPrenume()<<endl;
            this->angajati[pos] = angajat;
        }
        else
        {
            cout<<"Nu exista "<<pos<<" angajati. Angajatul nu a fost inlocuit!";
        }
    }

    string getLocatie()
    {
        return this->locatie;
    }
    int getId()
    {
        return this->id;
    }
    int getnrAngajati()
    {
        return this->nrAngajati;
    }
    Angajat getAngajat(int pos)
    {
        return this->angajati[pos];
    }

};

Restaurant::Restaurant(string locatie, int id, int nrAngajati)
{
    Angajat angajat;
    bool introdus;

    this->locatie = locatie;
    this->id = id;
    this->nrAngajati = nrAngajati;
    this->angajati = new Angajat[nrAngajati + 1];

    for(int i = 1; i <= this->nrAngajati; i++)
    {
        cout<<"Introduceti angajatul numarul "<<i<<":"<<endl;
        cin>>angajat;
        introdus = false;
        for(int j = 1; j < i; j++)
            if(angajat == this->angajati[j])
            {
                introdus = true;
                break;
            }

        if(introdus == false)
        {
            this->angajati[i] = angajat;
            cout<<"Angajat introdus cu succes!"<<endl<<endl;
        }
        else
        {
            i--;
            cout<<"Angajatul a fost deja introdus! Introduceti alt angajat! "<<endl<<endl;
        }

    }
}

Restaurant::Restaurant(const Restaurant& obj)
{
    this->locatie = obj.locatie;
    this->id = obj.id;
    this->nrAngajati = obj.nrAngajati;

    this->angajati = new Angajat[this->nrAngajati + 1];
    for(int i = 1; i <= this->nrAngajati; i++)
        this->angajati[i] = obj.angajati[i];
}

Restaurant& Restaurant::operator=(Restaurant& obj)
{
    if(this != &obj)
    {
        this->locatie = obj.locatie;
        this->id = obj.id;
        this->nrAngajati = obj.nrAngajati;
        this->angajati = new Angajat[this->nrAngajati + 1];

        for(int i = 1; i <= this->nrAngajati; i++)
            this->angajati[i] = obj.angajati[i];
    }

    return *this;
}

Restaurant::~Restaurant()
{
    delete[] angajati;
    //  cout<<"DELETED: Restaurant "<<id<<" from "<<locatie<<endl;
}

istream& operator>>(istream& in, Restaurant& restaurant)
{
    Angajat angajat;
    bool introdus;

    cout<<"Locatie (introduceti un cuvant): ";
    in>>restaurant.locatie;

    cout<<"Id (introduceti un int): ";
    in>>restaurant.id;

    cout<<"Numar angajati: ";
    in>>restaurant.nrAngajati;

    if(restaurant.angajati != nullptr)
        delete[] restaurant.angajati;

    restaurant.angajati = new Angajat[restaurant.nrAngajati + 1];

    for(int i = 1; i <= restaurant.nrAngajati; i++)
    {
        cout<<"Introduceti angajatul numarul "<<i<<":"<<endl;
        cin>>angajat;
        introdus = false;
        for(int j = 1; j < i; j++)
            if(angajat == restaurant.angajati[j])
            {
                introdus = true;
                break;
            }

        if(introdus == false)
        {
            restaurant.angajati[i] = angajat;
            cout<<"Angajat "<<angajat.getNume()<<" "<<angajat.getPrenume()<<" a fost introdus cu succes!"<<endl<<endl;
        }
        else
        {
            i--;
            cout<<"Angajatul "<<angajat.getNume()<<" "<<angajat.getPrenume()<<" a fost deja introdus! Introduceti alt angajat! "<<endl<<endl;
        }
    }

    return in;
}

ostream& operator<<(ostream& out, Restaurant& restaurant)
{
    out<<"##########################################"<<endl;
    out<<"Locatie: "<<restaurant.locatie<<endl;
    out<<"Id: "<<restaurant.id<<endl;
    out<<"Numar angajati: "<<restaurant.nrAngajati<<endl<<endl;

    out<<"Doriti informatii detaliate despre angajati? [DA/NU]"<<endl<<endl;
    string raspuns;
    bool raspunsAcceptat = false;
    cin>>raspuns;

    while(raspunsAcceptat == false)
    {
        if(raspuns == "DA")
        {
            raspunsAcceptat = true;
            for(int i = 1; i <= restaurant.nrAngajati; i++)
                out<<restaurant.angajati[i];
        }
        else if(raspuns == "NU")
        {
            raspunsAcceptat = true;
            for(int i = 1; i <= restaurant.nrAngajati; i++)
                out<<restaurant.angajati[i].getNume()<<" "<<restaurant.angajati[i].getPrenume()<<endl;
        }

        if(raspunsAcceptat == false)
        {
            out<<"Introduceti un raspuns valid! [DA/NU]"<<endl;
            cin>>raspuns;
        }
    }

    out<<"##########################################"<<endl;

    return out;
}

bool operator==(Restaurant& res1, Restaurant& res2)
{
    if(res1.locatie == res2.locatie && res1.id == res2.id)
        return true;

    return false;
}

bool operator!=(Restaurant& res1, Restaurant& res2)
{
    if(res1.locatie != res2.locatie || res1.id != res2.id)
        return true;

    return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Produs
{
private:
    int cod;
    string nume;
    int pret;
    int ziExpirare;
    int lunaExpirare;
    int anExpirare;

public:
    Produs() {};
    Produs(int, string, int, int, int,int);
    Produs(const Produs&);
    Produs& operator=(Produs&);

    friend istream& operator>>(istream&, Produs&);
    friend ostream& operator<<(ostream&, Produs&);
    friend bool operator==(Produs&, Produs&);
    friend bool operator!=(Produs&, Produs&);
    Produs operator+(int);
    Produs operator-(int);
    Produs operator+=(int);
    Produs operator-=(int);
    bool operator<(int);
    bool operator>(int);

    void setCod(int cod)
    {
        this->cod = cod;
    }
    void setNume(string nume)
    {
        this->nume = nume;
    }
    void setPret(int pret)
    {
        this->pret = pret;
    }
    void setZiExpirare(int ziExpirare)
    {
        this->ziExpirare = ziExpirare;
    }
    void setLunaExpirare(int lunaExpirare)
    {
        this->lunaExpirare = lunaExpirare;
    }
    void setAnExpirare(int anExpirare)
    {
        this->anExpirare = anExpirare;
    }

    int getCod()
    {
        return this->cod;
    }
    string getNume()
    {
        return this->nume;
    }
    int getPret()
    {
        return this->pret;
    }
    int getZiExpirare()
    {
        return this->ziExpirare;
    }
    int getLunaExpirare()
    {
        return this->lunaExpirare;
    }
    int getAnExpirare()
    {
        return this->anExpirare;
    }
};

Produs::Produs(int cod, string nume, int pret, int ziExpirare, int lunaExpirare, int anExpirare)
{
    this->cod = cod;
    this->nume = nume;
    this->pret = pret;
    this->ziExpirare = ziExpirare;
    this->lunaExpirare = lunaExpirare;
    this->anExpirare = anExpirare;
}

Produs::Produs(const Produs& obj)
{
    this->cod = obj.cod;
    this->nume = obj.nume;
    this->pret = obj.pret;
    this->ziExpirare = obj.ziExpirare;
    this->lunaExpirare = obj.lunaExpirare;
    this->anExpirare = obj.anExpirare;
}

Produs& Produs::operator=(Produs& obj)
{
    if(this != &obj)
    {
        this->cod = obj.cod;
        this->nume = obj.nume;
        this->pret = obj.pret;
        this->ziExpirare = obj.ziExpirare;
        this->lunaExpirare = obj.lunaExpirare;
        this->anExpirare = obj.anExpirare;
    }

    return *this;
}

istream& operator>>(istream& in, Produs& produs)
{
    cout<<"Cod produs: ";
    in>>produs.cod;

    cout<<"Nume produs: ";
    in>>produs.nume;

    cout<<"Pret: ";
    in>>produs.pret;

    cout<<"Zi expirare: ";
    in>>produs.ziExpirare;

    cout<<"Luna expirare: ";
    in>>produs.lunaExpirare;

    cout<<"An expirare: ";
    in>>produs.anExpirare;

    cout<<endl;

    return in;
}

ostream& operator<<(ostream& out, Produs& produs)
{
    out<<"Cod produs: "<<produs.cod<<endl;
    out<<"Nume produs: "<<produs.nume<<endl;
    out<<"Pret: "<<produs.pret<<endl;
    out<<"Zi expirare: "<<produs.ziExpirare<<endl;
    out<<"Luna expirare: "<<produs.lunaExpirare<<endl;
    out<<"An expirare: "<<produs.anExpirare<<endl<<endl;

    return out;
}

bool operator==(Produs& prod1, Produs& prod2)
{
    if(prod1.cod == prod2.cod && prod1.nume == prod2.nume && prod1.pret == prod2.pret)
        return true;
    return false;
}

bool operator!=(Produs& prod1, Produs& prod2)
{
    if(prod1.cod != prod2.cod || prod1.nume != prod2.nume || prod1.pret != prod2.pret)
        return true;
    return false;
}

Produs Produs::operator+(int x)
{
    Produs newProd;
    newProd.cod = this->cod;
    newProd.nume = this->nume;
    newProd.pret = this->pret + x;
    newProd.ziExpirare = this->ziExpirare;
    newProd.lunaExpirare = this->lunaExpirare;
    newProd.anExpirare = this->anExpirare;

    return newProd;
}

Produs Produs::operator-(int x)
{
    Produs newProd;
    newProd.cod = this->cod;
    newProd.nume = this->nume;
    newProd.pret = this->pret - x;
    if(newProd.pret < 0)
        newProd.pret = 0;
    newProd.ziExpirare = this->ziExpirare;
    newProd.lunaExpirare = this->lunaExpirare;
    newProd.anExpirare = this->anExpirare;

    return newProd;
}

Produs Produs::operator+=(int x)
{
    this->pret = this->pret + x;
    return *this;
}

Produs Produs::operator-=(int x)
{
    this->pret = this->pret - x;
    if(this->pret < 0)
        this->pret = 0;

    return *this;
}

bool Produs::operator<(int x)
{
    if(this->pret < x)
        return true;
    return false;
}

bool Produs::operator>(int x)
{
    if(this->pret > x)
        return true;
    return false;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void comanda2(string comenzi[], int nrComenzi)
{
    cout<<"Comenzile care pot fi utilizate sunt: "<<endl;

    for(int i = 1; i <= nrComenzi; i++)
        cout<<"'"<<comenzi[i]<<"'"<<endl;

    cout<<endl;
}

Restaurant* comanda3(int& nrRestaurante)
{
    Restaurant *restaurante;
    cout<<"Numarul restaurantelor este: ";
    cin>>nrRestaurante;
    restaurante = new Restaurant[nrRestaurante + 1];

    for(int i = 1; i <= nrRestaurante; i++)
    {
        Restaurant restaurant;
        bool introdus = false;
        cout<<"Introduceti restaurantul numarul "<<i<<":"<<endl;
        cin>>restaurant;

        for(int j = 1; j < i; j++)
            if(restaurant == restaurante[j])
            {
                introdus = true;
                break;
            }

        if(introdus == false)
        {
            restaurante[i] = restaurant;
            cout<<"Restaurantul a fost adaugat cu succes!"<<endl<<endl;
        }
        else
        {
            i--;
            cout<<"Restaurantul a fost deja introdus. Introduceti alt restaurant!"<<endl;
        }
    }

    return restaurante;
}

void comanda4(Restaurant *restaurante, int nrRestaurante)
{
    for(int i = 1; i <= nrRestaurante; i++)
    {
        cout<<"Informatii despre restaurant: "<<endl;
        cout<<restaurante[i];
    }
}

Produs* comanda5(int &nrProduse)
{
    Produs *produse;

    cout<<"Numarul produselor este: ";
    cin>>nrProduse;
    produse = new Produs[nrProduse + 1];

    for(int i = 1; i <= nrProduse; i++)
    {
        cout<<"Introduceti produsul "<<i<<": "<<endl;
        cin>>produse[i];
        cout<<endl;
    }

    return produse;
}

void comanda6(Produs *produse, int nrProduse)
{
    for(int i = 1; i <= nrProduse; i++)
    {
        cout<<"Informatii despre produsul nr "<<i<<": "<<endl;
        cout<<produse[i];
        cout<<endl;
    }
}

void comanda7(Produs *produse, int nrProduse)
{
    int pos, val;
    cout<<"Introduceti numarul produsului caruia ii cresteti pretul: ";
    cin>>pos;

    if(pos > nrProduse || pos < 1)
        cout<<"Nu exista produsul cu numarul "<<pos<<"! Numarul de produse este "<<nrProduse<<endl;
    else
    {
        cout<<"Introduceti valoarea cu care vreti sa cresteti pretul produsului: ";
        cin>>val;

        produse[pos] += val;
        cout<<"Pretul produsului a fost modificat!"<<endl<<endl;
    }
}

void comanda8(Produs *produse, int nrProduse)
{
    int pos, val;
    cout<<"Introduceti numarul produsului caruia ii scadeti pretul: ";
    cin>>pos;

    if(pos > nrProduse)
        cout<<"Nu exista produsul cu numarul "<<pos<<"! Numarul de produse este "<<nrProduse<<endl;
    else
    {
        cout<<"Introduceti valoarea cu care vreti sa scadeti pretul produsului: ";
        cin>>val;

        produse[pos] -= val;
        cout<<"Pretul produsului a fost modificat!"<<endl<<endl;
    }
}

Restaurant* comanda9(Restaurant *restaurante, int& nrRestaurante)
{
    int i;
    Restaurant *restaurante2 = new Restaurant[nrRestaurante + 2];

    for(i = 1; i <= nrRestaurante; i++)
        restaurante2[i] = restaurante[i];

    nrRestaurante++;
    cin>>restaurante2[nrRestaurante];

    if(restaurante != nullptr)
        delete[] restaurante;

    cout<<"Restaurantul a fost adaugat cu succes!"<<endl<<endl;

    return restaurante2;
}

Restaurant* comanda10(Restaurant *restaurante, int& nrRestaurante)
{
    int i, k = 1, pos;

    cout<<"Introduceti numarul restaurantului pe care doriti sa-l stergeti: ";
    cin>>pos;

    if(pos > nrRestaurante || pos < 1)
    {
        cout<<"Restaurantul numarul "<<pos<<" nu exista!"<<endl;
        return restaurante;
    }
    else
    {
        Restaurant *restaurante2 = new Restaurant[nrRestaurante];

        for(i = 1; i < pos; i++)
            restaurante2[k++] = restaurante[i];

        for(i = pos + 1; i <= nrRestaurante; i++)
            restaurante2[k++] = restaurante[i];

        nrRestaurante--;

        if(restaurante != nullptr)
            delete[] restaurante;

        cout<<"Restaurantul a fost sters cu succes!"<<endl<<endl;

        return restaurante2;
    }

}

void comanda11(Restaurant *restaurante, int nrRestaurante)
{
    int pos;
    string raspuns;
    bool raspunsValid;

    cout<<"Introduceti numarul restaurantului pe care doriti sa-l modificati: ";
    cin>>pos;

    if(pos > nrRestaurante || pos < 1)
    {
        cout<<"Restaurantul cu numarul "<<pos<<" nu exista!"<<endl;
    }
    else
    {
        cout<<"Doriti sa modificati LOCATIA? [DA/NU]"<<endl;
        cin>>raspuns;
        raspunsValid = false;
        while(raspunsValid == false)
        {
            if(raspuns == "DA")
            {
                raspunsValid = true;
                cout<<"Introduceti noua locatie (un cuvant): ";
                string locatie;
                cin>>locatie;
                restaurante[pos].setLocatie(locatie);
                cout<<"Locatie modificata cu succes!"<<endl;
            }
            else if(raspuns == "NU")
            {
                raspunsValid = true;
                cout<<endl;
            }
            else
            {
                cout<<"Raspuns invalid! Introduceti un raspuns valid [DA/NU]"<<endl;
                cin>>raspuns;
            }
        }

        /////////////////////

        cout<<"Doriti sa modificati ID-ul? [DA/NU]"<<endl;
        cin>>raspuns;
        raspunsValid = false;
        while(raspunsValid == false)
        {
            if(raspuns == "DA")
            {
                raspunsValid = true;
                cout<<"Introduceti noua locatie (un int): ";
                int id;
                cin>>id;
                restaurante[pos].setId(id);
                cout<<"ID modificat cu succes!"<<endl;
            }
            else if(raspuns == "NU")
            {
                raspunsValid = true;
                cout<<endl;
            }
            else
            {
                cout<<"Raspuns invalid! Introduceti un raspuns valid [DA/NU]"<<endl;
                cin>>raspuns;
            }
        }

        //////////////////////


    }
}

int main()
{
    int nrComenzi = 11, nrRestaurante = 0, nrProduse = 0, i, j;
    Restaurant *restaurante = NULL;        //indexat de la 1
    Produs *produse = NULL;                //indexat de la 1
    string comanda, comenzi[nrComenzi + 1];
    comenzi[1] = "Inchide";
    comenzi[2] = "Ajutor";
    comenzi[3]= "Introdu_restaurante";
    comenzi[4] = "Afiseaza_restaurante";
    comenzi[5] = "Introduceti_produse";
    comenzi[6] = "Afisati_produse";
    comenzi[7] = "Creste_pret_produs";
    comenzi[8] = "Scade_pret_produs";
    comenzi[9] = "Adauga_restaurant";
    comenzi[10] = "Sterge_restaurant";
    comenzi[11] = "Modifica_restaurant";



    comanda2(comenzi, nrComenzi);
    cout<<"Introduceti o comanda: ";
    cin>>comanda;

    while(comanda != "Inchide")
    {
        bool validCommand = false;
        for(i = 2; i <= nrComenzi; i++)
            if(comanda == comenzi[i])
            {
                validCommand = true;
                break;
            }

        if(validCommand == false)
        {
            cout<<"Comanda invalida. Introduceti alta comanda: ";
            cin>>comanda;
        }
        else
        {
            if(comanda == comenzi[2])
                comanda2(comenzi, nrComenzi);
            else if(comanda == comenzi[3])
                restaurante = comanda3(nrRestaurante);
            else if(comanda == comenzi[4])
                comanda4(restaurante, nrRestaurante);
            else if(comanda == comenzi[5])
                produse = comanda5(nrProduse);
            else if(comanda == comenzi[6])
                comanda6(produse, nrProduse);
            else if(comanda == comenzi[7])
                comanda7(produse, nrProduse);
            else if(comanda == comenzi[8])
                comanda8(produse, nrProduse);
            else if(comanda == comenzi[9])
                restaurante = comanda9(restaurante, nrRestaurante);
            else if(comanda == comenzi[10])
                restaurante = comanda10(restaurante, nrRestaurante);
             else if(comanda == comenzi[11])
                comanda11(restaurante, nrRestaurante);

            cout<<"Introduceti o comanda: ";
            cin>>comanda;
        }

    }

    cout<<endl<<"Proces incheiat!"<<endl;


    return 0;
}
