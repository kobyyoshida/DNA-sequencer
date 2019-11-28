#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"
#include "GenLinkedList.h"

using namespace std;

/*
Abby Bechtel and Koby Yoshida
abechtel@chapman.edu and koyoshida@chapman.edu
2312284 and 1023362
*/

class Faculty: public Person
{
  public:
    Faculty(); //constructor
    Faculty(string srlz); //overloaded constructor
    Faculty(int i, string n, string l, string d); //overloaded constructor
    ~Faculty(); //deconstructor

    string getDepartment();
    void setDepartment(string d);
    
    void addAdvisee(int studID);
    GenLinkedList<int> getAdvisees();
    void printAdvisees();
    int getSize();
    void removeAdvisee(int studID);
    bool contains(int studID);
    void print();
    string toFacultyString(); //formats faculty info into a string for serialization

  private:
    string dept;
    GenLinkedList<int> advisees;
    int max;
    int size;
};
#endif
