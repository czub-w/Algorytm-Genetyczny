#include "TCandidateZad1.h"
TCandidateZad1::TCandidateZad1() { init_vector(); rate(); }
void TCandidateZad1::init_vector() {
    genotype = {
        TParam("x1", 0, 7, 1),
        TParam("x2", 0, 3, 1)
    };

    for (auto& param : genotype) {
        int range = (param.get_x_end() - param.get_x_start()) / param.get_dx() + 1;
        int los = rand() % range;
        param.set_val(param.get_x_start() + los * param.get_dx());
    }
}

void TCandidateZad1::rate() {
    rating = 2 * (genotype[0].get_val() + genotype[1].get_val());
}
TCandidate* TCandidateZad1::create_new() const { return new TCandidateZad1(); }
TCandidate* TCandidateZad1::create_copy() const { return new TCandidateZad1(*this); }
