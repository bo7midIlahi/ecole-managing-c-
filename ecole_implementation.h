#ifndef ECOLE_H
#define ECOLE_H

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cstdio>

using namespace std;

static const int NBR_ELEVE = 6;

class ecole {
protected:
    char* nom;
    char* adr;
    int   ne;
    int*  eleve;

    bool valid_eleve(const int* eleve);
    char* copy_str(const char* str);

public:
    ecole(const char* _nom_ = NULL, const char* _adr_ = NULL, int _ne_ = 0, int* _eleve_ = NULL);

    ecole(const ecole& e);

    virtual ~ecole();

    const char* get_nom();
    const int   get_eleve_niveau(int niveau);

    ecole operator++();

    ecole operator+(const ecole& e);

    virtual operator char*();

    virtual void view();
};

class ecole_privee : public ecole {
protected:
    char* gerant;
    float capital;

public:
    ecole_privee(const char* _nom_ = NULL, const char* _adr_ = NULL, int _ne_ = 0, const int* _eleve_ = NULL, const char* gerant_ = NULL, float capital_ = 0.0f);

    virtual ~ecole_privee();

    virtual operator char*();
    virtual void view();
};

#endif
