#include <iostream>
#include <memory>
#include "TCandidate.h"
#include "TCandidateZad1.h"
#include "TCandidateZad2.h"

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    cout << "Wybierz typ osobnika:" << endl;
    cout << "0 - TCandidate (x1^2 + x2)" << endl;
    cout << "1 - TCandidateZad1 (2 * (x1 + x2))" << endl;
    cout << "2 - TCandidateZad2 (jak TCandidate, ale losowe wartosci)" << endl;

    int choice;
    cin >> choice;

    unique_ptr<TCandidate> candidate;

    switch (choice) {
    case 0:
        candidate = make_unique<TCandidate>();
        candidate->rate();
        break;
    case 1:
        candidate = make_unique<TCandidateZad1>();
        candidate->rate();
        break;
    case 2:
        candidate = make_unique<TCandidateZad2>();
        break;
    default:
        cout << "Niepoprawny wybor." << endl;
        return 1;
    }

    candidate->info();

    return 0;
}
