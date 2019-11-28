#ifndef SIMULATION_H
#define SIMULATION_H

#include "Student.h"
#include "Faculty.h"
#include "Tree.h"

class Simulation
{
	private:
		Tree<Student> *masterStudent;
		Tree<Faculty> *masterFaculty;

		bool keepGoing;

	public:


		Simulation();//constructor
		~Simulation(); //destructor

    //mutators and accessors for the Trees
		Tree<Student>* getStudentTree(); //accessor for student tree
		Tree<Faculty>* getFacutlyTree(); //accessor for faculty tree
		void setStudentTree(Tree<Student>* s);//mutator for student tree
    void setFacultyTree(Tree<Faculty>* f); // mutator for faculty treee

    int generateFacultyID(); //generates random faculty ID
    int generateStudentID();

    void displayOptions(); //showing the database options
		void run(); //starting the database
		void printAllStudents(); //1
		void printAllFaculty();	//2
		void displayStudent(); //3
		void displayFaculty(); //4
		void displayAdvisor();//5
		void displayAdvisees(); //6
		void insertStudent();	//7
		void insertFaculty();	//9
		void deleteNodeStudent();	//8
    void deleteNodeFaculty(); //10
		bool changeAdvisor(int studID, int newID);//swaping advisors
		void reassignAdvisee();	//11
		void removeAdvisee();	//12
    //void rollBack(); //13
    void loadFiles();
		void writeFacultyToFile(string file);		//writes faculty tree to file
		void writeStudentsToFile(string file);		//writes student tree to file
		void openDB();	//starting old database

		//to help with error checking
		int getInput(string message, int data);
		string getInput(string message, string data);
		double getInput(string message, double data);
};
#endif
