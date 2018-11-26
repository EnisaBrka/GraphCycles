#include "Graf.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>

Graf::Graf()
{
    broj_ciklusa=0;
}

void Graf::dodajCvor(Cvor *novi)
{
    cvoroviGrafa.push_back(novi);
}

void Graf::PrikaziCvoroveGrafa()
{
    for(int i=0; i<cvoroviGrafa.size(); i++)
        {
            Cvor* cvor1=cvoroviGrafa[i];
            cout<<"kljuc "<<cvor1->dajKljuc()<<'\t'<<"stepen "<<cvor1->dajStepen()<<'\t'<<"status "<<cvor1->dajStatus()<<endl;
        }
}

Cvor* Graf::NadjiCvorGrafa(char kljuc)
{
    for(int i=0; i<cvoroviGrafa.size(); i++)
        {
            if((cvoroviGrafa[i]->dajKljuc())==kljuc) return cvoroviGrafa[i];
        }
    return NULL;
}

//za listu susjeda-grane
void Graf::dodajNoviCvor(Cvor *novi)
{
    listaCvorova.push_back(novi);
}

void Graf::PrikaziGraf()
{
    for(int i=0; i<listaCvorova.size(); i++)
        {
            listaCvorova[i]->PrikaziListuSusjeda();
        }
}

bool Graf::Paran()
{
        for(int i=0; i<cvoroviGrafa.size(); i++)
        {
            if(cvoroviGrafa[i]->dajStepen()%2!=0 && cvoroviGrafa[i]->Susjedi(cvoroviGrafa[i])==false) return false;
        }
        return true;
}



void Graf::PovecajBrojCiklusa()
{
        broj_ciklusa=dajBrojCiklusa()+1;
}

void Graf::PrepoloviBrojCiklusa()
{
        broj_ciklusa=dajBrojCiklusa()/2;
}

void Graf::NadjiCikluse(int i)
{
    stack<char> ciklus;
    stack<char> ciklus_tmp;


    ofstream upis;
    upis.open("ciklusi.txt", ios::app);
    for(int i=0; i<cvoroviGrafa.size(); i++){
        if(cvoroviGrafa[i]->Susjedi(cvoroviGrafa[i])==true){
            upis<<cvoroviGrafa[i]->dajKljuc()<<'\t'<<cvoroviGrafa[i]->dajKljuc()<<endl;
            PovecajBrojCiklusa();
        }
        for(int j=0; j<cvoroviGrafa.size(); j++){
            if(cvoroviGrafa[j]->Susjedi(cvoroviGrafa[i])==true && cvoroviGrafa[i]->Susjedi(cvoroviGrafa[j])){
                upis<<cvoroviGrafa[i]->dajKljuc()<<'\t'<<cvoroviGrafa[j]->dajKljuc()<<'\t'<<cvoroviGrafa[i]->dajKljuc()<<endl;
                cvoroviGrafa[i]->PovecajStatus();
                PovecajBrojCiklusa();
            }
        }
    }

    PrepoloviBrojCiklusa();

    int najmanji=cvoroviGrafa[0]->dajStatus();

    for(int j=0; j<cvoroviGrafa.size(); j++){
        if(najmanji>cvoroviGrafa[j]->dajStatus()){
            najmanji=cvoroviGrafa[j]->dajStatus();
        }
    }

    ciklus.push(cvoroviGrafa[najmanji]->dajKljuc());
  //  cout<<"na steku je: "<<ciklus.top()<<endl;
    upis<<cvoroviGrafa[najmanji]->dajKljuc()<<'\t';

    bool b=false;
    for(int j=0; j<cvoroviGrafa.size(); j++){
    if(b==true){
        for(int m=0; m<cvoroviGrafa.size(); m++){
            if(cvoroviGrafa[m]->dajStatus()<=cvoroviGrafa[m]->dajStepen()-1){
            //    cout<<"novi pocetni je: "<<cvoroviGrafa[m]->dajKljuc()<<" sa statusom: "<<cvoroviGrafa[m]->dajStatus()<<endl;
                if(cvoroviGrafa[m]->dajKljuc()==ciklus_tmp.top()) ciklus_tmp.pop();
                ciklus.push(cvoroviGrafa[m]->dajKljuc());
           //     cout<<"na steku je: "<<ciklus.top()<<endl;
                upis<<cvoroviGrafa[m]->dajKljuc()<<'\t';
                j=m;
                najmanji=m;
                break;

            }
        }

    }
    for(int k=0; k<=cvoroviGrafa.size(); k++){
        if(cvoroviGrafa[j]->Susjedi(cvoroviGrafa[k])==true && cvoroviGrafa[k]->dajStatus()<cvoroviGrafa[k]->dajStepen()){
            if(ciklus_tmp.empty() || (cvoroviGrafa[k]->dajKljuc()!=ciklus_tmp.top() && cvoroviGrafa[k]->dajKljuc()!=ciklus.top())){
            if(!ciklus_tmp.empty()) ciklus_tmp.pop();
        //    cout<<"susjedi "<<cvoroviGrafa[j]->dajKljuc()<<'\t'<<cvoroviGrafa[k]->dajKljuc()<<endl;
         //   cout<<cvoroviGrafa[k]->dajKljuc()<<"<<"<<cvoroviGrafa[k]->dajStatus()<<endl;
            ciklus.push(cvoroviGrafa[k]->dajKljuc());
         //   cout<<"na steku je: "<<ciklus.top()<<endl;
            cvoroviGrafa[j]->PovecajStatus();
         //   cout<<"cvor i status: "<<cvoroviGrafa[k]->dajKljuc()<<'\t'<<cvoroviGrafa[k]->dajStatus()<<endl;
            cvoroviGrafa[k]->PovecajStatus();
            upis<<cvoroviGrafa[k]->dajKljuc()<<'\t';
            b=false;
            if(cvoroviGrafa[k]->dajKljuc()==cvoroviGrafa[najmanji]->dajKljuc()){
          //      cout<<"isti su"<<endl;
                cvoroviGrafa[najmanji]->PovecajStatus();
                PovecajBrojCiklusa();
                upis<<endl;
                while(!ciklus.empty()){
                    char c=ciklus.top();
                    ciklus.pop();
                    ciklus_tmp.push(c);

                }
                b=true;
            }
            break;
        }else ciklus_tmp.pop();

        }
      //  else cout<<"nisu susjedi"<<'\t'<<cvoroviGrafa[k]->dajKljuc()<<endl;
    }
    }
    upis.close();
}


Graf::~Graf()
{
        for(int i=0; i<listaCvorova.size(); i++)
        {
            delete listaCvorova[i];
            listaCvorova.clear();
        }
}
