#include <iostream>
#include <fstream>
#include "Cvor.h"
#include "Graf.h"
#include "Grana.h"

using namespace std;

int main(){
    Graf graf;

    ifstream ucitaj;
    ucitaj.open("susjedi.txt");

    char prvi,k;
    string linija;
    Cvor *novi, *novi1;
    Grana* grana1;

    while(true){
        ucitaj>>prvi;
        novi=new Cvor(prvi);

        if(graf.NadjiCvorGrafa(prvi)==NULL){ //ako nadje cvor, poveca njegov stepen, i vrati !=NULL
            graf.dodajCvor(novi); //dodaje cvor novi u graf
            graf.dodajNoviCvor(novi); //dodaje cvor u vektor koji kreira listu susjeda

            getline(ucitaj,linija);
            for(int i=0; i<linija.length();i++){
                k=linija.at(i);
                if(k!=' '){
                    novi1=new Cvor(k);
                    graf.dodajNoviCvor(novi1);
                    if(graf.NadjiCvorGrafa(k)==NULL){
                        novi1->PovecajStepen();
                    }
                    novi->DodajSusjede(novi1);
                    if(k==prvi){
                       // cout<<"isti su: "<<k<<prvi<<endl;
                        novi1->PovecajStepen();
                        novi->DodajSusjede(novi1);
                    }
                    novi->PovecajStepen();
                }
            }
        }
        else{
            graf.dodajNoviCvor(novi); //dodaje cvor u vektor koji kreira listu susjeda
            getline(ucitaj,linija);
            for(int i=0; i<linija.length();i++){
                k=linija.at(i);
                if(k!=' '){
                    novi1=new Cvor(k);
                    graf.dodajNoviCvor(novi1);
                    novi->DodajSusjede(novi1);
                    if(graf.NadjiCvorGrafa(k)==NULL){
                        novi1->PovecajStepen();
                    }
                    if(k==prvi){
                      //  cout<<"isti su: "<<k<<prvi<<endl;
                        novi1->PovecajStepen();
                        graf.NadjiCvorGrafa(prvi);
                        novi->DodajSusjede(novi1);
                    }
                    novi->PovecajStepen();
                }
            }
        }
        if(ucitaj.eof())break;
    }


    cout<<endl<<"Èvorovi grafa su: "<<endl;
    graf.PrikaziCvoroveGrafa();
    cout<<endl;
    cout<<endl<<"Uneseni graf je: "<<endl;
    graf.PrikaziGraf();
    cout<<endl;

    ofstream upis; //obrisati cikluse od prethodnog grafa
    upis.open("ciklusi.txt", ios::trunc);
    upis.close();

    if(graf.Paran()==true) graf.NadjiCikluse(0); //0-ti cvor je pocetni;

    cout<<endl<<"Maksimalan broj ciklusa unesenog grafa je: "<<graf.dajBrojCiklusa()<<endl;

    ucitaj.close();
}
