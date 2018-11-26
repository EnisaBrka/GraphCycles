#ifndef GRAF_H
#define GRAF_H
#include <map>
#include <vector>
#include "Cvor.h"
using namespace std;

class Graf
{
    private:
        vector<Cvor*> cvoroviGrafa;
        int broj_ciklusa;
        vector<Cvor*> listaCvorova; //susjedni cvorovi-grane

    public:
        Graf();
        void dodajCvor(Cvor*);
        Cvor* NadjiCvorGrafa(char);
        void PrikaziCvoroveGrafa();

        void dodajNoviCvor(Cvor*);
        void PrikaziGraf();

        bool Paran();
        int dajBrojCiklusa(){return broj_ciklusa;};
        void PovecajBrojCiklusa();
        void PrepoloviBrojCiklusa();
        void NadjiCikluse(int);


        Cvor* NadjiCvor(int);
        vector<Cvor*>&dajListuCvorova(){return listaCvorova;};


        vector<Cvor*>&dajCvoroveGrafa(){return cvoroviGrafa;};



        virtual ~Graf();
};

#endif // GRAF_H
