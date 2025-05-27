#include <iostream>
#include "TCandidate.h"

using namespace std;

TCandidate::TCandidate()
    : x1("x1", 0, 100, 1),
      x2("x2", 0, 10, 1),
       rating(0) 
{
    
}

void TCandidate::rate() {
    double val1 = x1.get_val();
    double val2 = x2.get_val();
    rating = val1 * val1 + val2;
}

void TCandidate::info() const {
    cout << "===============================" << endl;
    cout << "== gens count: 2" << endl;
    cout << "== \"x1\" value: " << x1.get_val() << endl;
    cout << "== \"x2\" value: " << x2.get_val() << endl;
    cout << "===============================" << endl;
    cout << "== rate: " << rating << endl;
    cout << "===============================" << endl;
}
double TCandidate::getRating() const {
    return rating;
}
