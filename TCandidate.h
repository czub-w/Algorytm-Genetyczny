#pragma once

#include "TParam.h"
#include <string>

class TCandidate {
protected:
    TParam x1, x2;
    double rating;
    int x1_bits, x2_bits;

public:
    TCandidate(int x1_bits = 3, int x2_bits = 2);
    virtual void rate();
    virtual void info() const;
    virtual ~TCandidate() {}
    double getRating() const;

    virtual std::string encodeBinary() const;
    virtual void decodeBinary(const std::string& bin);
};

void crossover(TCandidate& a, TCandidate& b);
void mutate(TCandidate& c);