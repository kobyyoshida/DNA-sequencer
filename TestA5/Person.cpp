#include "Person.h"

using namespace std;

/*
Abby Bechtel and Koby Yoshida
abechtel@chapman.edu and koyoshida@chapman.edu
2312284 and 1023362
*/

Person::Person(){  //constructor
}

Person::~Person(){
}

void Person::setID(int i){
  Person::ID = i;
}

int Person::getID(){
  return Person::ID;
}

void Person::setName(string n){
  Person::name = n;
}

string Person::getName(){
  return Person::name;
}

string Person::getLevel(){
  return Person::level;
}

void Person::setLevel(string l){
  Person::level = l;
}

bool Person::operator<(const Person& p){
  return this->ID < p.ID;
}

bool Person::operator>(const Person& p){
  return this->ID > p.ID;
}

bool Person::operator==(const Person& p){
	return this->ID == p.ID;
}


bool Person::operator!=(const Person& p){
  return !(this->ID == p.ID);
}

bool Person::operator!=(const long int p)
{
  return !(this->ID == p);
}
