#include "TAlgorithm.h"
#include "TPopulation.h"
#include <iostream>
#include <algorithm>

using namespace std;

TAlgorithm::TAlgorithm(unsigned int c_count, unsigned int max_p_count, unsigned int min_impr, const TCandidate* proto)
    : candidates_count(c_count), max_population_count(max_p_count), min_improvement_proc(min_impr), prototype(proto) {
}

void TAlgorithm::run() {
    unsigned int total_count = 0;
    TPopulation population(candidates_count, prototype, total_count + 1);

    while (total_count < max_population_count) {
        population.calculate();
        population.info();
        population.bestCandidate();

        double current_best = 0.0;
        for (const auto& cand : population.getCandidates()) {
            current_best = std::max(current_best, cand->getRating());
        }

        std::cout << "Population #" << (total_count + 1)
            << " best val: " << current_best << std::endl;

        last_bests.push_back(current_best);
        ++total_count;

        
        if (last_bests.size() >= window_size) {
            size_t start = last_bests.size() - window_size;
            double start_val = last_bests[start];
            double end_val = last_bests.back();

            if (start_val > 0 && ((end_val - start_val) / start_val) * 100 >= min_improvement_proc) {
                std::cout << "Osiagnieto poprawe >= " << min_improvement_proc
                    << "% w ostatnich " << window_size << " populacjach.\n";
                std::cout << "Koniec algorytmu genetycznego.\n";

                std::cout << "\n=== Najlepsze wartosci z kazdej populacji ===\n";
                for (size_t i = 0; i < last_bests.size(); ++i) {
                    std::cout << "Populacja #" << (i + 1) << ": " << last_bests[i] << std::endl;
                }
                return;
            }
        }

       
        std::vector<TCandidate*> new_candidates;
        while (new_candidates.size() < candidates_count) {
            TCandidate* parent1 = population.promote_candidate();
            TCandidate* parent2 = population.promote_candidate();

            if (!parent1 || !parent2) continue;

            TCandidate* child1 = nullptr;
            TCandidate* child2 = nullptr;

            if ((rand() % 100) < 75) {
                std::string bin1 = parent1->encodeBinary();
                std::string bin2 = parent2->encodeBinary();
                int cut = rand() % bin1.size();
                std::string new_bin1 = bin1.substr(0, cut) + bin2.substr(cut);
                std::string new_bin2 = bin2.substr(0, cut) + bin1.substr(cut);

                child1 = parent1->create_new();
                child2 = parent1->create_new();
                child1->decodeBinary(new_bin1);
                child2->decodeBinary(new_bin2);
            }
            else {
                child1 = parent1->create_copy();
                child2 = parent2->create_copy();
            }

            for (TCandidate* child : { child1, child2 }) {
                std::string bin = child->encodeBinary();
                for (char& bit : bin) {
                    if ((rand() % 100) < 5) {
                        bit = (bit == '0') ? '1' : '0';
                    }
                }
                child->decodeBinary(bin);
                new_candidates.push_back(child);
                if (new_candidates.size() >= candidates_count) break;
            }
        }

        TPopulation new_population(new_candidates, total_count + 1);
        population = std::move(new_population);

    }

    std::cout << "Osiagnieto limit populacji (" << max_population_count << ") bez stabilnej poprawy.\n";
    std::cout << "Koniec algorytmu genetycznego.\n";

    std::cout << "\n=== Najlepsze wartosci z kazdej populacji ===\n";
    for (size_t i = 0; i < last_bests.size(); ++i) {
        std::cout << "Populacja #" << (i + 1) << ": " << last_bests[i] << std::endl;
    }



}
