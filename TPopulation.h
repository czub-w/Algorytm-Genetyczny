#pragma once
#include "TCandidate.h"
#include <vector>

class TPopulation {
private:
    std::vector<TCandidate*> candidates;
    int _id;

public:
    TPopulation(int n, const TCandidate* prototype, int id_);
    TPopulation(const std::vector<TCandidate*>& new_cands, int id_);
    ~TPopulation();

    void calculate();
    void info();
    void bestCandidate() const;
    const std::vector<TCandidate*>& getCandidates() const;
    TCandidate* promote_candidate();

    void setId(int id);
    int getId() const;
    TPopulation& operator=(TPopulation&& other) noexcept;

};
