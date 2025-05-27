#pragma once

#include "TCandidate.h"
#include <vector>

class TPopulation {
private:
    std::vector<TCandidate> candidates;

public:
    static int _id;

    TPopulation(int n);       // konstruktor - tworzy populacj�
    void calculate();         // oblicza warto�ci wszystkich kandydat�w
    void info();              // wy�wietla informacje o populacji
    void bestCandidate() const;
    const std::vector<TCandidate>& getCandidates() const;
};
