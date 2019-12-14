#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

/*
Abby Bechtel and Koby Yoshida
abechtel@chapman.edu and koyoshida@chapman.edu
2312284 and 1023362
*/

class Person{
  public:
    Person(); //constructor
    virtual ~Person() = 0; //pure virtual deconstructor

    string getName();
    int getID();
    string getLevel();
    void setLevel(string l);
    void setName(string n);
    void setID(int i);

    bool operator<(const Person &p);
    bool operator>(const Person &p);
    bool operator==(const Person &p);
    bool operator!=(const Person &p);
    bool operator!=(const long int p);

    protected:
      string name;
      int ID;
      string level;
};

#endif
