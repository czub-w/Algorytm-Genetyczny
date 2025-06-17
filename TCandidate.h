#pragma once
#include "TParam.h"
#include <vector>
#include <string>

class TCandidate {
protected:
    std::vector<TParam> genotype;
    double rating;

public:
    virtual ~TCandidate() {}

    virtual void rate() = 0;
    virtual void init_vector() = 0;

    virtual std::string encodeBinary() const;
    virtual void decodeBinary(const std::string& bin);
    virtual void mutate(); 
    virtual TCandidate* crossover(const TCandidate& other) const;

    virtual TCandidate* create_new() const = 0;
    virtual TCandidate* create_copy() const = 0;

    virtual void info() const;
    double getRating() const { return rating; }
};