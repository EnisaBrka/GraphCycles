#include "Cvor.h"
#include "Grana.h"
#include <ostream>
#include <iostream>
#include <algorithm>
using namespace std;

Cvor::Cvor()
{
    stepen++;
}

Cvor::Cvor(char k)
{
    key=k;
    stepen=0;
    status=0;
}

void Cvor::PovecajStepen()
{
    stepen++;
}

void Cvor::PovecajStatus()
{
    status++;
}

//grane grafa:
void Cvor::DodajSusjede(Cvor* s)
{
    Grana nova(this, s);
    susjedi.push_back(nova);
}

void Cvor::PrikaziListuSusjeda()
{
    for(int i=0; i<susjedi.size();i++){
        Grana grana=susjedi[i];
        cout<<key<<'\t'<<grana.dajKrajnji()->dajKljuc()<<endl;
    }
}

bool Cvor::Susjedi(Cvor* drugi)
{
    for(int i=0; i<susjedi.size();i++){
        Grana grana1=susjedi[i];
        if(this->dajKljuc()==grana1.dajPocetni()->dajKljuc() && drugi->dajKljuc()==grana1.dajKrajnji()->dajKljuc()) return true;
    }
    return false;
}


Cvor::~Cvor()
{
    susjedi.clear();
}
