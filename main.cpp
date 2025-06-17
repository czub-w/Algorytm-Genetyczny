#include <iostream>
#include "TAlgorithm.h"
#include "TCandidateZad1.h"
#include "TCandidateZad2.h"
#include "TCandidateZad3.h"
using namespace std;

int main() {
    srand(time(NULL));

    int choice;
    cout << "Wybierz klase kandydata:\n1 - Zad1\n2 - Zad2\n3 - Zad3\n> ";
    cin >> choice;

    int pop_size;
    cout << "Podaj liczebnosc populacji: ";
    cin >> pop_size;

    const TCandidate* prototype = nullptr;
    switch (choice) {
    case 1: prototype = new TCandidateZad1(); break;
    case 2: prototype = new TCandidateZad2(); break;
    case 3: prototype = new TCandidateZad3(); break;
    default: cout << "Nieprawid³owy wybór!" << endl; return 1;
    }

    TAlgorithm alg(pop_size, 10, 25, prototype);
    alg.run();

    delete prototype;
    return 0;
}
