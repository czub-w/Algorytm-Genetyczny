#include <iostream>
#include "TCandidate.h"

using namespace std;

TCandidate::TCandidate()
    : x1("x1", 0, 10, 1),   
      x2("x2", 0, 10, 1)    
{
    //lista inicjalizacyjna, bo brak konstruktora domyslnego TParam
}



//f. wyswietlajaca rating, zapisywany jako zmienna w .h
void TCandidate::rate() {
    double val1 = x1.get_val();
    double val2 = x2.get_val();
    rating = val1 * val1 + val2;
}

// f. wyswietlajaca info o danym kandydacie
void TCandidate::info() {
    cout << "===============================" << endl;
    cout << "== gens count: 2" << endl;
    cout << "== \"x1\" value: " << x1.get_val() << endl;
    cout << "== \"x2\" value: " << x2.get_val() << endl;
    cout << "===============================" << endl;
    cout << "== rate: " << rating << endl;
    cout << "===============================" << endl;
}
