#include "TCandidateZad2.h"
#include <cstdlib>
TCandidateZad2::TCandidateZad2() { init_vector(); rate(); }
void TCandidateZad2::init_vector() {
    genotype = {
        TParam("x1", 0, 20, 1),
        TParam("x2", 0, 10, 1)
    };

    for (auto& param : genotype) {
        int range = (param.get_x_end() - param.get_x_start()) / param.get_dx() + 1;
        int los = rand() % range;
        param.set_val(param.get_x_start() + los * param.get_dx());
    }
}

void TCandidateZad2::rate() {
    rating = genotype[0].get_val() * genotype[0].get_val() + genotype[1].get_val();
}
TCandidate* TCandidateZad2::create_new() const { return new TCandidateZad2(); }
TCandidate* TCandidateZad2::create_copy() const { return new TCandidateZad2(*this); }

