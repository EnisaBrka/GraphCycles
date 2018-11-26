#ifndef CVOR_H
#define CVOR_H
#include <vector>
#include "Grana.h"

using namespace std;
class Cvor
{
    private:
        char key;
        int stepen;
        int status; //0- ne posjeæene, 1-posjeæen
        vector<Cvor*> SusjediCvora; //obrisati ako mogne sa granama
        vector<Grana> susjedi; //lista izlaznih ivica
    public:
        Cvor();
        Cvor(char);

        char dajKljuc(){return key;};
        int dajStepen(){return stepen;};
        int dajStatus(){return status;};

        void PovecajStepen();
        void PovecajStatus();
//grane:
        void DodajSusjede(Cvor*);
        bool Susjedi(Cvor*);
        vector<Grana>&dajListuSusjeda(){return susjedi;};
        void PrikaziListuSusjeda();

        virtual ~Cvor();
};

#endif // CVOR_H
