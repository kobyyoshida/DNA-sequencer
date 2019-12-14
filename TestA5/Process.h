#ifndef SERIALIZE_H
#define SERIALIZE_H

#include "Faculty.h"
#include "Student.h"
#include "Tree.h"

class Process
{
  public:
  	Process(); // default constructor
  	Process(Tree<Faculty> fTree, Tree<Student> sTree);// overloaded constructor
  	~Process();	// deconstructor

    Tree<Faculty> getFTree();	//accessor for the faculty tree
    Tree<Student> getSTree(); //accessor for the student tree
  	void setFTree(Tree<Faculty> fTree);	//mutator for the faculty tree
  	void setSTree(Tree<Student> sTree);	//mutator for the student tree


  private:
  	Tree<Faculty> facultyTree;
  	Tree<Student> studentTree;
};

#endif
