#include "TPopulation.h"
#include <iostream>
#include "TCandidate.h"
#include <algorithm>

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


bool porownaj_pary(const pair<int, size_t>& a, const pair<int, size_t>& b) {
    return a.first > b.first;
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

    vector<pair<int, size_t>> wyniki;
    for (size_t i = 0; i < counts.size(); ++i) {
        wyniki.push_back(make_pair(counts[i], i));
    }

    sort(wyniki.begin(), wyniki.end(), porownaj_pary);

    cout << "\nHistogram losowan kandydatow:\n";
    for (const auto& para : wyniki) {
        size_t j = para.second;
        cout << "Kandydat #" << j << ": ";
        int bars = counts[j] * 50 / num_draws;
        for (int k = 0; k < bars; ++k) {
            cout << "|";
        }
        cout << " (" << counts[j] << ")\n";
    }
}


void crossover(TCandidate& a, TCandidate& b) {
    string bin1 = a.encodeBinary();
    string bin2 = b.encodeBinary();

    int pos = rand() % 4 + 1;
    cout << "Krzyzowanie na pozycji: " << pos << endl << endl;
    string new1 = bin1.substr(0, pos) + bin2.substr(pos);
    string new2 = bin2.substr(0, pos) + bin1.substr(pos);

    a.decodeBinary(new1);
    b.decodeBinary(new2);
}

void mutate(TCandidate& c) {
    string bin = c.encodeBinary();

    for (size_t i = 0; i < bin.size(); ++i) {
        int chance = rand() % 100;
        if (chance < 5) {
            bin[i] = (bin[i] == '0') ? '1' : '0';
            cout << "Mutacja na bicie #" << i << " -> nowy bit: " << bin[i] << endl;
        }
    }

    c.decodeBinary(bin);
}