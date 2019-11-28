#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

using namespace std;

/*
Abby Bechtel and Koby Yoshida
abechtel@chapman.edu and koyoshida@chapman.edu
2312284 and 1023362
*/

class Student : public Person
{
  public:
    Student(); // constructor
    Student(int i, string n, string l, string m, double g, int adID); //overloaded constructor
    Student(string srlz); //overloaded constructor for creating student's from seralized string
    ~Student(); //deconstructor

    void setMajor(string m);
    string getMajor();
    void setGPA(double g);
    double getGPA();
    void setAdvisor(int adID);
    int getAdvisor();
    void print(); //printing student information
    string toStudentString(); //creating the string to print to the file

  private:
    int max;
    int min;

    string major;
    double gpa;
    int advisorID;
};

#endif
