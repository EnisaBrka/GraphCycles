#ifndef GRANA_H
#define GRANA_H
#include <map>

class Cvor;

class Grana
{
    private:
        Cvor *pocetni;
        Cvor *krajnji;
        int status; //0-ne posjecena, 1-trenutna, 2-posjecena
    public:
        Grana(Cvor*, Cvor*);
        Cvor* dajPocetni(){return pocetni;};
        Cvor* dajKrajnji(){return krajnji;};
        void PostaviStatus(int st){status=st;};
        virtual ~Grana();

};

#endif // GRANA_H
