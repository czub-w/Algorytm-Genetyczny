#pragma once
#include "TCandidate.h" 
#include <vector>


class TAlgorithm {
private:
    unsigned int candidates_count;
    unsigned int max_population_count;
    unsigned int min_improvement_proc;
    const TCandidate* prototype;

    std::vector<double> last_bests;
    const int window_size = 5;

public:
    TAlgorithm(unsigned int candidates_count, unsigned int max_population_count, unsigned int min_improvement_proc, const TCandidate* prototype);
    void run();
};
