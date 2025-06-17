#include "TCandidateZad3.h"
TCandidateZad3::TCandidateZad3() { init_vector(); rate(); }
void TCandidateZad3::init_vector() {
    genotype = { TParam("x1", 1, 10, 1), TParam("x2", 1, 5, 1), TParam("x3", 1, 8, 1) };
    genotype[0].set_val(rand() % 10 + 1);
    genotype[1].set_val(rand() % 5 + 1);
    genotype[2].set_val(rand() % 8 + 1);
}
void TCandidateZad3::rate() {
    rating = genotype[0].get_val() * genotype[1].get_val() - genotype[2].get_val();
}
TCandidate* TCandidateZad3::create_new() const { return new TCandidateZad3(); }
TCandidate* TCandidateZad3::create_copy() const { return new TCandidateZad3(*this); }

