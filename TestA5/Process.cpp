#include "Process.h"

using namespace std;

/*
Abby Bechtel and Koby Yoshida
abechtel@chapman.edu and koyoshida@chapman.edu
2312284 and 1023362
*/

Process::Process() : facultyTree(), studentTree() // default constructor
{
}

Process::Process(Tree<Faculty> fTree, Tree<Student> sTree) // overloaded constructor
{
	setFTree(fTree);
	setSTree(sTree);
}

Process::~Process()	// deconstructor
{}

Tree<Faculty> Process::getFTree()	//accessor for the faculty tree
{
	return facultyTree;
}

Tree<Student> Process::getSTree() //accessor for the student tree
{
	return studentTree;
}

void Process::setFTree(Tree<Faculty> fTree)	//mutator for the faculty tree
{
	facultyTree = fTree;
}

void Process::setSTree(Tree<Student> sTree)	//mutator for the student tree
{
	studentTree = sTree;
}
