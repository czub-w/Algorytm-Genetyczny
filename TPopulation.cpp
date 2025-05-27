#include "TPopulation.h"
#include <iostream>
#include "TCandidate.h"

using namespace std;

int TPopulation::_id = 0;

TPopulation::TPopulation(int n) {
    for (int i = 0; i < n; ++i) {
        candidates.push_back(TCandidate());
    }
    _id++;  
}

void TPopulation::calculate() {
    for (auto& candidate : candidates) {
        candidate.rate();
    }
}

void TPopulation::info() {
    cout << endl << "===== POPULATION #" << _id << " =====" << endl;
    for (size_t i = 0; i < candidates.size(); ++i) {
        cout << "== candidate#" << i << ": " << endl;
        candidates[i].info();
        cout << endl;
    }
}

void TPopulation::bestCandidate() const {
    if (candidates.empty()) return;

    size_t bestIndex = 0;

    for (size_t i = 1; i < candidates.size(); ++i) {
        if (candidates[i].getRating() > candidates[bestIndex].getRating()) {
            bestIndex = i;
        }
    }

    const TCandidate* best = &candidates[bestIndex];

    cout << "\nNajlepszy osobnik (kandydat #" << bestIndex << ") z populacji #" << _id << ":\n";
    best->info(); // to jest to samo
    (*best).info(); // co to

}

const std::vector<TCandidate>& TPopulation::getCandidates() const {
    return candidates;
}


