#pragma once
#include "TCandidate.h"
#include <iostream>

inline void mutate(TCandidate* c) {
    std::string bin = c->encodeBinary();
    for (char& b : bin) {
        if ((rand() % 100) < 5) {
            b = (b == '0') ? '1' : '0';
        }
    }
    c->decodeBinary(bin);
}

inline void crossover(TCandidate* a, TCandidate* b) {
    std::string bin1 = a->encodeBinary();
    std::string bin2 = b->encodeBinary();
    int pos = rand() % bin1.size();
    std::string new1 = bin1.substr(0, pos) + bin2.substr(pos);
    std::string new2 = bin2.substr(0, pos) + bin1.substr(pos);
    a->decodeBinary(new1);
    b->decodeBinary(new2);
}
