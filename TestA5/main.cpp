#include <iostream>
#include "Simulation.h"
#include "Faculty.h"
#include "file.h"
#include "Process.h"
#include "Simulation.h"
#include "Stack.h"
#include "Student.h"
#include "Tree.h"
using namespace std;

/*
Abby Bechtel and Koby Yoshida
abechtel@chapman.edu and koyoshida@chapman.edu
2312284 and 1023362
*/

int main()
{

	Person *s = new Student(11111, "Abby", "Sophomore", "Physics", 3.9, 200000);
	Person *f = new Faculty(12345, "Rene", "Professor", "Comp Sci");

	cout << (s < f) << endl;

	delete s;
	delete f;

	Simulation *sim = new Simulation();
	sim->run();

	delete sim;

	return 0;
}
