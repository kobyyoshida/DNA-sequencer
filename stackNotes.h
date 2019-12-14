//header file

#include <iostream>
#include "stackNotes.cpp"

using namespace std;

class GenStack{
  public:
    GenStack(); // constructor
    GenStack(int maxSize); //overloaded constructor
    ~GenStack(); //destructor

    void push(char d);
    char pop();
    char peek();

    bool isFull();
    bool isEmpty();

    int size;
    int top;

    char *myArray; //pointer because the over loaded constructor is not set to how many elements there will be
                  // pointer is a memory address


}
