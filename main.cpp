#include <iostream>
#include <cstdlib>
#include <time.h>

#include "TCandidate.h"

using namespace std;

int main() {
	srand(time(0));

	TCandidate os1;
	os1.rate();
	os1.info();

	return 0;
}