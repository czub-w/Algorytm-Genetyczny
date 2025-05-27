#include "TAlgorithm.h"
#include <iostream>

using namespace std;

TAlgorithm::TAlgorithm(unsigned int c_count, unsigned int max_p_count, unsigned int min_impr)
    : candidates_count(c_count), max_population_count(max_p_count), min_improvement_proc(min_impr), best_rating(0) {
}

void TAlgorithm::run() {
    unsigned int total_count = 0;

    while (total_count < max_population_count) {

        TPopulation population(candidates_count);
        population.calculate();
        population.info();
        population.bestCandidate();

        double current_best = 0.0;
        for (const auto& cand : population.getCandidates()) {
            current_best = max(current_best, cand.getRating());
        }
        cout << "Population #" << (total_count + 1)
            << " best val: " << current_best << endl;

        last_bests.push_back(current_best);
        ++total_count;

        if (last_bests.size() >= window_size) {
            for (size_t start = 0; start <= last_bests.size() - window_size; ++start) {
                bool all_improved = true;

                for (int j = 1; j < window_size; ++j) {
                    double prev = last_bests[start + j - 1];
                    double curr = last_bests[start + j];

                    if (prev == 0) {
                        all_improved = false;
                        break;
                    }

                    double improvement = ((curr - prev) / prev) * 100;
                    if (improvement < min_improvement_proc) {
                        all_improved = false;
                        break;
                    }
                }

                if (all_improved) {
                    cout << "Osiagnieto poprawe >= " << min_improvement_proc
                        << "% w oknie [" << start << " - " << (start + window_size - 1) << "].\n";
                    cout << "Koniec algorytmu genetycznego.\n";
                    return;
                }
            }
        }
    }

    cout << "Osiagnieto limit maksymalnej liczby populacji (" << max_population_count << ") bez stabilnej poprawy.\n";
    cout << "Koniec algorytmu genetycznego.\n";
}

