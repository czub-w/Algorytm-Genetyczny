#pragma once

#include "TCandidate.h"
#include <vector>

class TPopulation {
private:
    std::vector<TCandidate> candidates;

public:
    static int _id;

    TPopulation(int n);       // konstruktor - tworzy populacjê
    void calculate();         // oblicza wartoœci wszystkich kandydatów
    void info();              // wyœwietla informacje o populacji
    void bestCandidate() const;
    const std::vector<TCandidate>& getCandidates() const;
};
