#include "TCandidateZad2.h"
#include <iostream>
using namespace std;

TCandidateZad2::TCandidateZad2() : TCandidate(3, 2) {
    x1.set_val(rand() % 8);
    x2.set_val(rand() % 4);  
    rate();
}

void TCandidateZad2::info() const {
    cout << "[Zad2] x1 = " << x1.get_val() << ", x2 = " << x2.get_val() << ", rate = " << rating << endl;
}