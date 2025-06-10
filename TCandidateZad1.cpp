#include "TCandidateZad1.h"
#include <iostream>
using namespace std;

TCandidateZad1::TCandidateZad1() : TCandidate(3, 2) {}

void TCandidateZad1::rate() {
    rating = 2 * (x1.get_val() + x2.get_val());
}

void TCandidateZad1::info() const {
    cout << "[Zad1] x1 = " << x1.get_val() << ", x2 = " << x2.get_val() << ", rate = " << rating << endl;
}