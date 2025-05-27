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
TCandidate* TPopulation::promote_candidate() {
    
    double total_rating = 0;
    for (const auto& c : candidates) {
        total_rating += c.getRating();
    }

    double r = ((double)rand() / RAND_MAX) * total_rating; // generowanie od 0 do total_ating

    double sum = 0;
    for (auto& c : candidates) {
        sum += c.getRating();
        if (r < sum) {
            return &c;
        }
    }

    return &candidates.back();
}


void TPopulation::test_histogram(int num_draws)
{
    vector<int> counts(candidates.size(), 0);

    for (int i = 0; i < num_draws; ++i) {
        TCandidate* selected = promote_candidate();
        for (size_t j = 0; j < candidates.size(); ++j) {
            if (selected == &candidates[j]) {
                counts[j]++;
                break;
            }
        }
    }

    cout << "\nHistogram losowan kandydatow:\n";
    for (size_t i = 0; i < counts.size(); ++i) {
        cout << "Kandydat #" << i << ": ";
        int bars = counts[i] * 50 / num_draws;
        for (int k = 0; k < bars; ++k) {
            cout << "|";
        }
        cout << " (" << counts[i] << ")\n";
    }
}




