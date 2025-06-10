#include <iostream>
#include <cstdlib>
#include <ctime>
#include "TAlgorithm.h"
#include "TPopulation.h"

using namespace std;

int main() {
    srand(time(0));

    TPopulation pop(30);
    pop.calculate();

    cout << "==== POCZATKOWA POPULACJA ====" << endl;
    pop.info();

    cout << "\n==== KRZYZOWANIE PAR ====" << endl;

    for (int i = 0; i < 15; ++i) {
        TCandidate* c1 = pop.promote_candidate();
        TCandidate* c2 = pop.promote_candidate();

        cout << "\n--- Para #" << i + 1 << " ---" << endl;
        cout << "Przed krzyzowaniem:" << endl;
        c1->info();
        c2->info();

        int x = rand() % 100;
        if (x < 75) {
            crossover(*c1, *c2);

            cout << "Po krzyzowaniu:" << endl;
            c1->info();
            c2->info();

            cout << "Mutacja kandydatow:" << endl;
            mutate(*c1);
            mutate(*c2);

            cout << "Po mutacji:" << endl;
            c1->info();
            c2->info();
        }
        else {
            cout << "Krzyzowanie pominiete (los < 75% nie spelniony). los = " << x << endl;
        }
    }

    return 0;
}
