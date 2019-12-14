#include "Faculty.h"

using namespace std;

/*
Abby Bechtel and Koby Yoshida
abechtel@chapman.edu and koyoshida@chapman.edu
2312284 and 1023362
*/

Faculty::Faculty() //constructor
{

}

Faculty::Faculty(int i, string n, string l, string d) : advisees()
//overloaded constructor
{
  Person::ID = i;
  Person::name = n;
  Person::level = l;
  size = 0;
  max = 10;
  dept = d;
}

Faculty::~Faculty()//deconstructor
{
}

Faculty::Faculty(string srlz) //creates faculty from serialized string
{
  int c = 0;

	string i;
	string n;
	string l;
	string d;
	string studID;

	while(srlz[c]!=';')
	{
		i += srlz[c];
		c++;
	}
	Person::ID = stoi(i);
	c++;

	while(srlz[c]!=';')
	{
		n += srlz[c];
		c++;
	}

	Person::name = n;
	c++;

	while(srlz[c]!=';')
	{
		l += srlz[c];
		c++;
	}

	Person::level = l;
	c++;

	while(srlz[c]!=';')
	{
		d += srlz[c];
		c++;
	}

	dept = d;
	c++;

	//creating the faculties advisees
	while(true)
	{
		if(srlz[c] == ';' || srlz[c]=='.')
		{
			addAdvisee(stoi(studID));
			studID = "";
			if(srlz[c] == '.')
				break;
		}else{
			studID += srlz[c];
		}
		c++;
	}
}

void Faculty::setDepartment(string d){
  dept = d;
}

string Faculty::getDepartment(){
  return dept;
}

void Faculty::addAdvisee(int studID){
  advisees.insertBack(studID);
}

GenLinkedList<int> Faculty::getAdvisees(){
  return advisees;
}

void Faculty::printAdvisees(){
  advisees.printList();
}

int Faculty::getSize(){
  advisees.getSize();
}

bool Faculty::contains(int studID){
  if(advisees.find(studID) == -1)
    return false;
  return true;
}

void Faculty::removeAdvisee(int studID){
  advisees.deleteKey(studID);
}

string Faculty::toFacultyString()//for serialization of data to file
{
	string r;
	r += to_string(Person::ID)+";";
	r += Person::name + ";";
  r += Person::level +";";
	r += dept + ";";
	r += advisees.toString()+ ".";

	return r;
}

void Faculty::print(){
  cout << " - Faculty ID is: " << Person::ID << endl;
  cout << " - Faculty name is: " << Person::name << endl;
  cout << " - Faculty level is: " << Person::level << endl;
  cout << " - Faculty department is: " << dept << endl;
}
