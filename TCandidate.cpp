#include <iostream>
#include "TCandidate.h"
#include <bitset>

using namespace std;

TCandidate::TCandidate(int x1_bits_, int x2_bits_)
    : x1("x1", 0, 7, 1), x2("x2", 0, 3, 1), rating(0), x1_bits(x1_bits_), x2_bits(x2_bits_)
{
    
}


void TCandidate::rate() {
    double val1 = x1.get_val();
    double val2 = x2.get_val();
    rating = val1 * val1 + val2;
}

void TCandidate::info() const {
    cout << "===============================" << endl;
    cout << "== gens count: 2" << endl;
    cout << "== \"x1\" value: " << x1.get_val() << endl;
    cout << "== \"x2\" value: " << x2.get_val() << endl;
    cout << "===============================" << endl;
    cout << "== rate: " << rating << endl;
    cout << "===============================" << endl;
}
double TCandidate::getRating() const {
    return rating;
}

string TCandidate::encodeBinary() const {
    int x1val = static_cast<int>(x1.get_val());
    int x2val = static_cast<int>(x2.get_val());

    auto toBinary = [](int val, int bits) {
        std::string res(bits, '0');
        for (int i = bits - 1; i >= 0; --i) {
            res[i] = (val & 1) ? '1' : '0';
            val >>= 1;
        }
        return res;
        };

    return toBinary(x1val, x1_bits) + toBinary(x2val, x2_bits);
}

void TCandidate::decodeBinary(const string& bin) {
    if (bin.size() != x1_bits + x2_bits) return;

    auto fromBinary = [](const string& s) {
        int val = 0;
        for (char c : s) {
            val = (val << 1) | (c - '0');
        }
        return val;
        };

    int x1val = fromBinary(bin.substr(0, x1_bits));
    int x2val = fromBinary(bin.substr(x1_bits, x2_bits));

    x1.set_val(x1val);
    x2.set_val(x2val);
    rate();
}