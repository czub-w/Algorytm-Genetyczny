#include <iostream>
#include <cstdlib>
#include <time.h>
#include "TAlgorithm.h"

using namespace std;

int main() {
	srand(time(0));

	unsigned int candidates_count = 5;
	unsigned int max_population_count = 100;
	unsigned int min_improvement_proc = 2;

	TAlgorithm task{
		candidates_count,
		max_population_count,
		min_improvement_proc
	};
	task.run();
	return 0;
}