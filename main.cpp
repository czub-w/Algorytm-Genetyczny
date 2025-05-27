#include <iostream>
#include <cstdlib>
#include <time.h>
#include "TAlgorithm.h"

using namespace std;

int main() {
    srand(time(0));

    TPopulation pop(10);
    pop.calculate();
    pop.info();

    cout << "\n==== LOSOWANIE KANDYDATOW====\n";

    const int num_to_select = 3;

    for (int i = 0; i < num_to_select; ++i) {
        TCandidate* selected = pop.promote_candidate();
        cout << "Wybrany kandydat #" << i + 1 << ":\n";
        selected->info();
    }
    pop.test_histogram(10000);

    return 0;
}