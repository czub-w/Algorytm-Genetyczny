#include "TPopulation.h"
#include "TCandidate.h"
#include <iostream>
#include <algorithm>

using namespace std;

TPopulation::TPopulation(const vector<TCandidate*>& new_cands, int id_) : _id(id_) {
    for (TCandidate* c : new_cands) {
        candidates.push_back(c->create_copy());
    }
}

TPopulation::TPopulation(int n, const TCandidate* prototype, int id_) : _id(id_) {
    for (int i = 0; i < n; ++i) {
        candidates.push_back(prototype->create_new());
    }
}

TPopulation::~TPopulation() {
    for (TCandidate* c : candidates) delete c;
}

void TPopulation::calculate() {
    vector<TCandidate*> new_generation;

    while (new_generation.size() < candidates.size()) {
        TCandidate* parent1 = promote_candidate();
        TCandidate* parent2 = promote_candidate();

        if (!parent1 || !parent2) {
            cerr << "[ERROR] Brak rodziców do krzy¿owania.\n";
            break;
        }

        if ((rand() % 100) < 75) {
            TCandidate* child1 = parent1->crossover(*parent2);
            TCandidate* child2 = parent2->crossover(*parent1);

            child1->mutate();
            child2->mutate();

            new_generation.push_back(child1);
            if (new_generation.size() < candidates.size())
                new_generation.push_back(child2);
            else
                delete child2;
        }
        else {
            TCandidate* copy = parent1->create_copy();
            copy->mutate();
            new_generation.push_back(copy);
        }
    }

    for (auto& c : candidates)
        delete c;

    candidates = std::move(new_generation);

    for (auto& c : candidates)
        c->rate();
}

void TPopulation::info() {
    cout << endl << "===== POPULATION #" << _id << " =====" << endl;
    for (size_t i = 0; i < candidates.size(); ++i) {
        cout << "== candidate#" << i << ": ";
        candidates[i]->info();
    }
}

void TPopulation::bestCandidate() const {
    if (candidates.empty()) return;
    auto best = *max_element(candidates.begin(), candidates.end(),
        [](TCandidate* a, TCandidate* b) {
            return a->getRating() < b->getRating();
        });
    cout << "\nNajlepszy osobnik:\n";
    best->info();
}

const std::vector<TCandidate*>& TPopulation::getCandidates() const {
    return candidates;
}

TCandidate* TPopulation::promote_candidate() {
    if (candidates.empty()) return nullptr;
    double total = 0;
    for (auto c : candidates) total += c->getRating();
    double r = ((double)rand() / RAND_MAX) * total, sum = 0;
    for (auto c : candidates) {
        sum += c->getRating();
        if (r <= sum) return c;
    }
    if (!candidates.empty())
        return candidates.back();
    else
        return nullptr;

}

TPopulation& TPopulation::operator=(TPopulation&& other) noexcept {
    if (this != &other) {
        for (TCandidate* c : candidates)
            delete c;
        candidates = std::move(other.candidates);
        _id = other._id;
    }
    return *this;
}

void TPopulation::setId(int id) {
    _id = id;
}

int TPopulation::getId() const {
    return _id;
}
