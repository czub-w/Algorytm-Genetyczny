#pragma once

#include "TParam.h"

class TCandidate {
private:
    TParam x1, x2;
    double rating;

public:
    TCandidate();      // tu inicjalizuje zmienne x1, x1   
    void rate();       // f. do obliczania ratingu   
    void info();        // f. do wyswietlania informacji
};
