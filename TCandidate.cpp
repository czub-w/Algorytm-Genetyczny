#include "TCandidate.h"
#include <cmath>
#include <bitset>
#include <iostream>
using namespace std;

string TCandidate::encodeBinary() const {
    std::string binary;
    for (const auto& g : genotype) {
        int val = g.get_val();
        int count = (g.get_x_end() - g.get_x_start()) / g.get_dx() + 1;
        int bits = std::ceil(std::log2(count));

        string part(bits, '0');
        for (int i = bits - 1; i >= 0; --i) {
            part[i] = (val & 1) ? '1' : '0';
            val >>= 1;
        }
        binary += part;
    }
    return binary;
}

void TCandidate::decodeBinary(const string& bin) {
    //cout << "[decodeBinary] bin: " << bin << "\n";
    size_t pos = 0;
    for (auto& g : genotype) {
        int count = (g.get_x_end() - g.get_x_start()) / g.get_dx() + 1;
        int bits = ceil(std::log2(count));
        string part = bin.substr(pos, bits);
        pos += bits;

        int val = 0;
        for (char c : part) {
            val = (val << 1) | (c - '0');
        }

        //cout << "   -> Parametr: " << g.get_name() << " = " << val << " (bin: " << part << ")\n";
        g.set_val(val);
    }
    rate();
}

void TCandidate::info() const {
    //std::cout << "[Kandydat] ";
    for (const auto& g : genotype) {
        cout << g.get_name() << "=" << g.get_val() << ", ";
    }
    cout << "rate = " << rating << std::endl;
}
void TCandidate::mutate() {
    //std::cout << "[MUTATE] Start\n";
    string bin = encodeBinary();
    for (char& bit : bin) {
        if ((rand() % 100) < 5) {
            bit = (bit == '0') ? '1' : '0';
        }
    }
    decodeBinary(bin);
    /*std::cout << "[MUTATE] Result: " << encodeBinary() << "\n";*/
    rate();
}


TCandidate* TCandidate::crossover(const TCandidate& other) const {
    std::string bin1 = encodeBinary();
    std::string bin2 = other.encodeBinary();

    if (bin1.length() != bin2.length()) throw runtime_error("Dlugosci binarne sie nie zgadzaja!");

    int pos = rand() % bin1.length();
    std::string child1_bin = bin1.substr(0, pos) + bin2.substr(pos);
    std::string child2_bin = bin2.substr(0, pos) + bin1.substr(pos);

    TCandidate* child = create_new();
    child->decodeBinary(child1_bin);

    //std::cout << "[CROSSOVER] p1: " << bin1 << ", p2: " << bin2 << ", cut@" << pos << " => " << child1_bin << "\n";

    return child;
}


