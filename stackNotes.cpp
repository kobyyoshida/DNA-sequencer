//#include "stackNotes.h"
#include <iostream>

using namespace std;

GenStack::GenStack()
{
  myArray = new char [128];
  size = 128;
  top = -1;
}

GenStack::GenStack(int maxSize){
  myArray = new char[maxSize];
  size = maxSize;
  top = -1;
}

GenStack::~GenStack(){
  delete myArray;
}

void GenStack::push(char d){
  //need to check error/boundary
  myArray[++top] = d;
}

char GenStack::pop(){
  //error checking, make sure its not empty
  if(top<0){
    throw std::runtime_error("Stack is empty.");
    return '/0';
  }
  else{
    return myArray[top--];
  }
}

char GenStack::peek(){
  //check if empty
  return myArray[top];
}

bool GenStack::isFull(){
  return (top == size-1);
}

bool GenStack::isEmpty()
{
  return (top == -1);
}
