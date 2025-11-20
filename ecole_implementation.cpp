#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cstdio>

#include "ecole_implementation.h"

using namespace std;

static const int NBR_ELEVE = 6; // make it static cuz #define wouldn't work

class ecole {
    protected:
        char* nom;
        char* adr;
        int ne;
        int* eleve;

        bool valid_eleve(const int* eleve){
            if (!eleve)
            {
                return true;
            }
            for (int i = 0; i < NBR_ELEVE; i++)
            {
                if (eleve[i]<0)
                {
                    return false;
                }
            }
        }

        char* copy_str(const char* str){
            if (!str)
            {
                return nullptr;
            }

            char* ptr = new char[strlen(str) + 1];
            strcpy(ptr,str);
            return ptr;
        }

    public:
        ecole(const char* _nom_=NULL, const char* _adr_=NULL, int _ne_=NULL, int* _eleve_=NULL) {
            //check ne
            if (_ne_<0)
            {
                cerr <<"NE <0";
            }

            //check
            if (!valid_eleve(_eleve_))
            {
                cerr <<"CHECK ELEVE";
            }

            nom = copy_str(_nom_);
            adr = copy_str(_adr_);
            ne = _ne_;

            eleve = new int[NBR_ELEVE];
            if (_eleve_){
                for (int i = 0; i < NBR_ELEVE; i++)
                {
                    eleve[i] = _eleve_[i];
                }
            }else{
                for (int i = 0; i < NBR_ELEVE; i++){
                    eleve[i] = 0;
                }
            }        
        };

        //constructeur par copie
        ecole(const ecole& e){
            nom = copy_str(e.nom);
            adr = copy_str(e.adr);
            ne = e.ne;
            for (int i = 0; i < NBR_ELEVE; i++)
            {
                eleve[i] = e.eleve[i];
            }
        }

        virtual ~ecole(){
            delete[] nom;
            delete[] adr;
            delete[] eleve;
        }

        const char* get_nom(){
            return nom;
        }

        const int get_eleve_niveau(int niveau){
            if (niveau<1 || niveau>NBR_ELEVE)
            {
                cerr <<"CHECK NIVEAU";
            }
            return eleve[niveau-1];
        }

        //surdefinition
        ecole operator++(){
            ++ne;
            return *this;
        }

        ecole operator+(const ecole& e){
            int new_ne = this->ne + e.ne;
            int new_eleve[NBR_ELEVE];
            for (int i = 0; i < NBR_ELEVE; i++){
                new_eleve[i] = this->eleve[i] + e.eleve[i];
            }

            char new_nom[20];
            char new_adr[20];

            cout <<"FUSION: ENTRER NEW NOM: ";
            while (strlen(new_nom)==0)
            {
                cin.getline(new_nom,20);
            }
            
            cout <<"FUSION: ENTRER NEW ADR: ";
            while (strlen(new_adr)==0)
            {
                cin.getline(new_adr,20);
            }

            ecole result(new_nom, new_adr, new_ne, new_eleve);
            return result;
        }

        virtual operator char*(){
            char* output = new char[100];
            output[99] = '\0';
            
            strcat(output,"nom:");
            strcat(output,nom);

            strcat(output,"adr:");
            strcat(output,adr);

            char buff[50];
            sprintf(buff, "ne:%d eleve:",ne);
            strcat(output,buff);

            for (int i = 0; i < NBR_ELEVE; i++)
            {
                sprintf(buff,"%d  ",eleve[i]);
                strcat(output,buff);
            }
            
            return output;
        }

        virtual void view(){
            printf("nom : %s\n", nom ? nom : "NULL");
            printf("adr : %s\n", adr ? adr : "NULL");
            printf("ne : %d\n", ne);
            printf("eleve: ");
            for (int i = 0; i < NBR_ELEVE; i++)
            {
                printf("%d", eleve[i]);
            }
        }

};

class ecole_privee : public ecole{
    protected:
        char* gerant;
        float capital;
    public: 
        ecole_privee(const char* _nom_ = NULL, const char* _adr_ = NULL, int _ne_ = 0, const int* _eleve_ = NULL, const char* gerant_ = NULL, float capital_ = 0.0f)
        : ecole( _nom_, _adr_, _ne_, _eleve_), gerant(nullptr), capital(capital_){
            gerant = copy_str(gerant_);
        }

        virtual ~ecole_privee() {
            delete[] gerant;
        }

        virtual operator char*(){
            char* base = this->operator char *();
            char* out = new char[50];

            out[49] = '\0';
            strcat(out,base);

            char buffer[50];
            sprintf(buffer,"gerant:%s\tcapital:%.2f",gerant,capital);

            delete[] base;
            return out;
        }

        virtual void view(){
            ecole::view();
            printf("gerant:%s\t capital:%.2f\n",gerant,capital);
        }

};