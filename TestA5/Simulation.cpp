#include "Simulation.h"
#include "Stack.h"
#include "Tree.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <fstream>

using namespace std;

/*
Abby Bechtel and Koby Yoshida
abechtel@chapman.edu and koyoshida@chapman.edu
2312284 and 1023362
*/

Simulation::Simulation()
{
	masterStudent = new Tree<Student>(); //instaintiating new Trees
	masterFaculty = new Tree<Faculty>();
	studentStack = new Stack<Tree>(5);
	facultyStack = new Stack<Tree>(5);

	keepGoing = true;
  //loadFiles(); //should load the files for new tree
}

Simulation::~Simulation()
{
	delete masterStudent;
	delete masterFaculty;
}

void Simulation::setStudentTree(Tree<Student>* s)
{
	masterStudent = s;
}

void Simulation::setFacultyTree(Tree<Faculty>* f)
{
	masterFaculty = f;
}

Tree<Student>* Simulation::getStudentTree()
{
	return masterStudent;
}

Tree<Faculty>* Simulation::getFacutlyTree()
{
	return masterFaculty;
}

void Simulation::run()
{
	while(keepGoing)
	{
		displayOptions();
	}
}

//THESE ARE HELPER METHODS TO SIMPLIFY INPUT CHECKING
int Simulation::getInput(string message, int data)
{
	while(true)
	{
		cout << message;
		cin >> data;

		if(!cin)
		{
			cout << "Invalid Input!" << endl;
			cin.clear();
			cin.ignore();
		}
		else
      break;
	}
	return data;
}

string Simulation::getInput(string message, string data)
{
	while(true)
	{
		cout << message;
		cin >> data;

		if(!cin)
		{
			cout << "Invalid Input!" << endl;
			cin.clear();
			cin.ignore();
		}
		else
      break;
	}
	return data;
}

double Simulation::getInput(string message, double data)
{
	while(true)
	{
		cout << message;
		cin >> data;

		if(!cin)
		{
			cout << "Invalid Input!" << endl;
			cin.clear();
			cin.ignore();
		}

		else
      break;
	}
	return data;
}

void Simulation::displayOptions()
{
	int option;

	while(true)
	{
    cout << "1. Print all students and their information (sorted by ascending id #) \n" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #) \n" << endl;
    cout << "3. Find and display student information given the students id \n" << endl;
    cout << "4. Find and display faculty information given the faculty id \n" << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor \n" << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees. \n" << endl;
    cout << "7. Add a new student \n" << endl;
    cout << "8. Delete a student given the id \n" << endl;
    cout << "9. Add a new faculty member \n" << endl;
    cout << "10. Delete a faculty member given the id. \n" << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id. \n" << endl;
    cout << "12. Remove an advisee from a faculty member given the ids \n" << endl;
    cout << "13. Rollback \n" << endl;
    cout << "14. Exit \n" << endl;
		cin >> option;

		if(!cin)
		{
			cout << "Invalid Input" << endl;
			cin.clear();
			cin.ignore();
		}

		else
      break;
	}

  if(option == 1){
    printAllStudents();
  }

	else if(option == 2){
    printAllFaculty();
  }

  else if(option == 3){
		displayStudent();
  }

  else if(option == 4){
    displayFaculty();
  }

  else if(option == 5){
		displayAdvisor();
  }

  else if(option == 6){
		displayAdvisees();
  }

  else if(option == 7){
		insertStudent();
  }

  else if(option == 8){
		deleteNodeStudent();
  }

  else if(option == 9){
    insertFaculty();
  }

  else if(option == 10){
		deleteNodeFaculty();
  }

  else if(option == 11){
		reassignAdvisee();
  }

  else if(option == 12){
		removeAdvisee();
  }

  else if(option == 13){
    //rollBack();
  }

  else if(option == 14){
    writeFacultyToFile("FacultyTree.txt");
    writeStudentsToFile("StudentTree.txt");
    keepGoing= false;
  }
}


//Koby I can't figure this part out :(
// void rollBack()
// {
// }

// //I'm having trouble with this method
void Simulation::loadFiles()
{
	ifstream file;
	file.open("FacultyTree.txt");
	string line;
	while(getline(file, line))
	{
		if(line!=""){
      Faculty *temp;
      temp = new Faculty(line);
      masterFaculty->insert(temp->getID(), *temp);
    }
	}
	file.close();
	file.open("StudentTree.txt");
	while(getline(file, line))
	{
		if(line!=""){
      Student *temp;
  	  temp = new Student(line);
  	  masterStudent->insert(temp->getID(), *temp);
    }
	}
}


void Simulation::writeFacultyToFile(string name)
{
	ofstream file;
	file.open(name);
	if(file.is_open())
	{
		while(!masterFaculty->isEmpty())
		{
			Faculty f1 = masterFaculty->deleteRoot();
			f1.print();
			file << f1.toFacultyString() << endl;
      cout << "success" << endl; //successfully wrote to file
		}
	}
	file.close();
}

void Simulation::writeStudentsToFile(string name)
{
	ofstream file;
	file.open(name);
	if(file.is_open())
	{
		while(!masterStudent->isEmpty())
		{
			Student s1 = masterStudent->deleteRoot();
			s1.print();
			file << s1.toStudentString() << endl;
			cout << "success" <<endl; //successfully wrote to file
		}
	}
	file.close();
}

//1
void Simulation::printAllStudents()
{
	if(!masterStudent->isEmpty())
	{
		for(int i = 1; i <= masterStudent->getMax()->data.Person::getID(); ++i)
		{
			if(masterStudent->contains(i)) masterStudent->find(i)->print();
		}
	}

	else
    cout << endl << "There are no students to print" << endl;
}

//2
void Simulation::printAllFaculty()
{
	if(!masterFaculty->isEmpty())
	{
		for(int i = 1; i <= masterFaculty->getMax()->data.Person::getID(); ++i)
		{
			if(masterFaculty->contains(i)) masterFaculty->find(i)->print();
		}
	}

	else
    cout << endl << "There are no faculty to print" << endl;
}

//3
void Simulation::displayStudent()
{
	int studID;
	studID = getInput("Enter the ID of the student: ", studID);

	if(masterStudent->contains(studID))
	{
		masterStudent->find(studID)->print();
	}

	else cout << "Student not found" << endl;
}

//4
void Simulation::displayFaculty()
{
	int facID;
	facID = getInput("Enter the ID of the faculty: ", facID);

	if(masterFaculty->contains(facID))
	{
		masterFaculty->find(facID)->print();
	}

	else
    cout << "Faculty not found" << endl;
}

//5
void Simulation::displayAdvisor()
{
	int studID;
	studID = getInput("Enter the ID of the student: ", studID);

	if(masterStudent->contains(studID))
	{
		int factID = masterStudent->find(studID)->getAdvisor();
		masterFaculty->find(factID)->print();
	}

	else cout << "Student not found" << endl;
}

//6
void Simulation::displayAdvisees()
{
	int facID;
	facID = getInput("Enter the ID of the Faculty: ", facID);

	if(masterFaculty->contains(facID)) //checking if the faculty exists
	{
		Faculty *temp = masterFaculty->find(facID);

		if(temp->getSize() > 0)
		{
			GenLinkedList<int> advisees = temp->getAdvisees();

		  for(int i = 0; i < temp->getSize(); ++i){
				if(masterStudent->contains(advisees.returnIndex(i)) && masterFaculty->find(facID)->contains(advisees.returnIndex(i))) masterStudent->find(advisees.returnIndex(i))->print(); //prints the returns list of advisees
			}
		}
		else cout << "There are no advissees" << endl; //error handling
	}

	else cout << "Advisor does not exist" << endl; //error handling
}

//7
void Simulation::insertStudent()
{
	lastUpdateToStudent = true;
	if(!masterFaculty->isEmpty())
	{
		int ID = 0;
		int advisorID;
		string name;
		string level;
		string major;
		double gpa;
		bool cancel = false;

		cout << "Enter the student's information." << endl;

		while(masterStudent->contains(ID) || ID == 0)
		{
			ID = generateStudentID();
		}

		cout << "ID: " << ID << endl;
		name = getInput("Name: ", name);
		level = getInput("Year: ", level);
		major = getInput("Major: ", major);
		gpa = getInput("GPA: ", gpa);

		while(true)
		{
			advisorID = getInput("Advisor ID: ", advisorID);

			if(masterFaculty->contains(advisorID))
			{
				masterFaculty->find(advisorID)->addAdvisee(ID);
				break;
			}

			else
			{
				cout << "The advisor does not exist " << advisorID << "\nTry again: " << endl;

				while(true)
				{
					string c;
					c = getInput("Try a different advisor? (Y/N) ", c);
					transform(c.begin(), c.end(), c.begin(), ::tolower); //makes string choice lowercase

					if(c == "y")
            break;
					else if(c == "n")
					{
						cancel = true;
						goto cancel;
					}
					else
            cout << "Invalid input! Please try again!" << endl;
				}
			}
		}

    Student *temp;
  	temp = new Student(ID, name, level, major, gpa, advisorID);
  	masterStudent->insert(ID, *temp);

		cout << "Student was entered" << endl;

    cancel://tag for cancelling insert
		if(cancel) cout << "Cancelled!" << endl;
	}

	else
    cout << "Cannot add student with out valid advisor" << endl;
}

//9
void Simulation::insertFaculty()
{
	lastUpdateToStudent = false;
	int ID = 0;
	int adviseeID;
	string name;
	string level;
	string dept;
	bool cancel = false;

	cout << "Enter the faculty info: " << endl;

	while(masterFaculty->contains(ID) || ID == 0)
	{
		ID = generateFacultyID();
	}

	cout << "ID: " << ID << endl;
	name = getInput("Name: ", name);
	level = getInput("Position: ", level);
	dept = getInput("Department: ", dept);

	Faculty *temp;
	temp = new Faculty(ID, name, level, dept);
	masterFaculty->insert(ID, *temp);

	while(true)
	{
		string result;

		result = getInput("Add an advisee? (Y/N) ", result);
		transform(result.begin(), result.end(), result.begin(), ::tolower); //makes string choice lowercase

		if(result == "y")
		{
			adviseeID = getInput("Advisee ID: ", adviseeID);

			if(masterStudent->contains(adviseeID))
			{
				int tempID = masterStudent->find(adviseeID)->getAdvisor();

				while(true)
				{
					string c;
					cout << "Student with ID " << adviseeID << "is previously assigned to: " << tempID << endl;
					c = getInput("Would you like to continue assigning (Y/N) ", c);
					transform(c.begin(), c.end(), c.begin(), ::tolower); //makes string c lowercase

					if(c == "y")
					{
						temp->addAdvisee(adviseeID);
						changeAdvisor(adviseeID, ID);
						cout << "Student reassigned!" << endl;
						break;
					}
					else if(c == "n")
					{
						cout << "Cancelled" << endl;
						break;
					}
					else cout << "Invalid Input! Try again!" << endl;
				}
			}
			else //advisee does not exist
			{
				while(true)
				{
					string choice;
					cout << "Student does not exist" << endl;
					choice = getInput("Create this new student? (Y/N) ", choice);
					transform(choice.begin(), choice.end(), choice.begin(), ::tolower); //makes string choice lowercase

					if(choice == "y")
					{
						insertStudent();
						break;
					}
					else if(choice == "n")
					{
						cout << "Cancelled" << endl;
						break;
					}
					else cout << "Invalid Input! Try again!" << endl;
				}
			}
		}
		else if(result == "n") break;
		else
      cout << "Invalid input" << endl;
	}

	cout << "Faculty entered" << endl;

	cancel://cancelling goto operation
		if(cancel)
      cout << "Cancelled" << endl;
}

//8
void Simulation::deleteNodeStudent()
{
	lastUpdateToStudent = true;
	int ID;
	ID = getInput("Please Enter Student ID: ", ID);

	if(masterStudent->contains(ID))
	{
		cout << "Old Advisees: " << endl;

		int facID = masterStudent->find(ID)->getAdvisor();
		masterFaculty->find(facID)->printAdvisees();
		masterStudent->deleteNode(ID); //deleting student
    masterFaculty->find(facID)->removeAdvisee(ID); //removing the advisee from faculty

    cout << "New Advisees:" << endl;
		masterFaculty->find(facID)->printAdvisees();
	}
  else
	{
		cout << ID << ": is not a valid student ID" << endl;
		return;
	}
}

//10
void Simulation::deleteNodeFaculty(){
  int ID;
	lastUpdateToStudent = false;
  ID = getInput("Please Enter Faculty ID: ", ID);
  if(masterFaculty->contains(ID))
  {
    Faculty *temp = masterFaculty->find(ID);
    int numOfAdvisees = temp->getSize();
    //reassign advisees
    if(numOfAdvisees > 0)
    {
      GenLinkedList<int> advisees = temp->getAdvisees();
      cout << "Advisor has " << numOfAdvisees << " student(s) needing a new advisor" << endl;
      for(int i = 0; i < numOfAdvisees; ++i)
      {
        while(true)
        {
          int choice;
          cout << "Who will be the new advisor for " << advisees.returnIndex(i) << endl;
          choice = getInput("Advisor ID: ", choice);

          if(choice == ID)
            cout << endl << "That faculty ID is being deleted" << endl;
          else if(changeAdvisor(advisees.returnIndex(i), choice))
            break;
          else
            cout << "Invalid, try again" << endl;
        }
      }
    }
    masterFaculty->deleteNode(ID);
  }

  else
  {
    cout << "Invalid faculty ID" << endl;
    return;
  }

  cout << "sucessful delete of faculty" << endl;
}

//11
bool Simulation::changeAdvisor(int studID, int newID)
{
	if(masterStudent->contains(studID) && masterFaculty->contains(newID))
	{
		int oldID = masterStudent->find(studID)->getAdvisor();
		masterFaculty->find(oldID)->removeAdvisee(studID);
		masterStudent->find(studID)->setAdvisor(newID);
		masterFaculty->find(newID)->addAdvisee(studID);


		cout << "Change successful!" << endl;

		return true;
	}

	else
	{
		cout << "An error occured with one of the entered ID's"<< endl;
		return false;
	}
}

//11
void Simulation::reassignAdvisee()
{
	int studID;
	int newID;

	cin.clear();
	cin.ignore();
	studID = getInput("Enter the ID of the student you want to reassign: ", studID);
	newID = getInput("Enter the ID of the advisor you want to assign: ", newID);

	changeAdvisor(studID, newID);
}

//12
void Simulation::removeAdvisee()
{
	int facID;
	int studID;

	facID = getInput("Enter the ID of the advisor: ", facID);
	studID = getInput("Enter the ID of the student: ", studID);

	if(masterFaculty->contains(facID) && masterStudent->contains(studID))
	{
		if(masterFaculty->find(facID)->contains(studID))
		{
			masterFaculty->find(facID)->removeAdvisee(studID);
			cout << "Advisee " << studID << " needs to be reassigned!" << endl;
			while(true)
			{
				int choice;
				choice = getInput("Enter the ID of the advisor you want to assign to student: ", choice);
				if(changeAdvisor(studID,choice))
          break;
				else
          continue;
			}
		}
		else
      cout << "Faculty " << facID << " is not assigned to student " << studID << endl;
	}

	else
    cout << "An ID entered was incorrect" << endl;
}

//13
void Simulation::rollBack(){
	if(lastUpdateToStudent){//if the last insert/delete update was to the student tree
		//masterStudent = studentStack[0].runUndo();
		//call the runUndo on some object here
	}
	else if (!lastUpdateToStudent){//the last insert/delete update was done to the faculty tree
		//masterFaculty = studentStack[0].runUndo();
		//same as above
	}
}


int Simulation::generateFacultyID(){//this function should generate a random number between 10000 and 20000, have not tested yet
  int max = 10000;
  int min = 20000;
  int randNum = rand()%(max-min + 1) + min;
  return randNum;
}

int Simulation::generateStudentID(){//this function should generate a random number between 0-1000, have not tested yet
  int max = 1000;
  int min = 0;
  int randNum = rand()%(max-min + 1) + min;
  return randNum;
}
