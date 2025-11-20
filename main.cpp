#include "ecole_implementation.h"

int main(){
    int eleve_1[6] = { 10, 12, 11, 9, 8, 7 };
    int eleve_2[6] = { 5, 6, 4, 7, 3, 2 };

    ecole e1("3abes ben farnes", "la4i9iya", 5, eleve_1);
    ecole e2("ben laden", "tora bora", 3, eleve_2);

    cout << "e1:\n"; e1.view();
    cout << "e2:\n"; e2.view();

    ++e1;
    cout << "\nAfter ++s1:\n"; e1.view();

    ecole e3 = e1 + e2; // will prompt
    cout << "\nResult of fusion (e3):\n";
    e3.view();

    ecole_privee p("so9rat", "kazakhistan", 2, eleve_1, "M. Gerant", 12345.67f);
    cout << "\nEcole privee p:\n"; p.view();

    ecole* pb = &p;
    pb->view();

    char* pstr = p;
    printf("\nconvert_ecole (priv): %s\n", pstr);
    delete[] pstr;

    return 0;
}