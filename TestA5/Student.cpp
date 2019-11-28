#include "Student.h"
#include <iostream>

using namespace std;

/*
Abby Bechtel and Koby Yoshida
abechtel@chapman.edu and koyoshida@chapman.edu
2312284 and 1023362
*/

Student::Student()
{ //constructor
}

Student::Student(int i, string n, string l, string m, double g, int adID)
{ //overloaded constructor
  Person::ID = i;
  Person::name = n;
  Person::level = l;

  major = m;
  gpa = g;
  advisorID = adID;
}

Student::~Student()
{ //deconstructor
}

Student::Student(string srlz) //creates a student from seralized string from file
{
  int c = 0; // line counter

  string n;
  string i;
  string l;
  string m;
  string g;
  string adID;

  while (srlz[c]!=';'){ //reading through file to find student id
    i +=srlz[c];
    c++;
  }

  Person::ID = stoi(i);
  c++;

  while (srlz[c]!=';'){ //reading through file to find student name
      n +=srlz[c];
      c++;
  }

  Person::name = n;
  c++;

  while (srlz[c]!=';'){//reading through file to find student level
    l +=srlz[c];
    c++;
  }

  Person::level = l;

  while (srlz[c]!=';'){ //reading through file to find student major
    m +=srlz[c];
    c++;
  }

  major = m;
  c++;

  while (srlz[c]!=';'){ //reading through file to find student gpa
    g += srlz[c];
    c++;
  }

  gpa = stod(g);

  while (srlz[c]!=';'){ //reading through file to find student advisor
    adID += srlz[c];
    c++;
  }

  advisorID = stoi(adID);
  c++;
}

void Student::setGPA(double g){
  gpa = g;
}

double Student::getGPA(){
  return gpa;
}

void Student::setAdvisor(int adID){
  advisorID = adID;
}

int Student::getAdvisor(){
  return advisorID;
}

void Student::setMajor(string m){
  major = m;
}
string Student::getMajor(){
  return major;
}

void Student::print(){
  cout << " - Student ID is: " << Person::ID << endl;
  cout << " - Student name is: " << Person::name << endl;
  cout << " - Student level is: " << Person::level << endl;
  cout << " - Student major is: " << major << endl;
  cout << " - Student GPA is: " << gpa << endl;
  cout << " - Student adviser's ID is: " << advisorID << endl;
}

string Student::toStudentString()
{
	string r;
	r += to_string(Person::ID)+";";
	r += Person::name + ";";
	r += Person::level +";";
	r += major + ";";
	r += to_string(gpa) + ";";
	r += to_string(advisorID) + ".";
	return r;
}
