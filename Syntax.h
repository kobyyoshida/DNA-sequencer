//koby yoshida
#ifndef SYNTAXFUNCTIONS_H
#define SYNTAXFUNCTIONS_H
#include <iostream>
#include <fstream>

#include "syntaxGenStack.h"

using namespace std;

//template <class T>

class Syntax{
  public:
    //Syntax checker;
    Syntax();
    //Syntax(int n);
    ~Syntax();

    int currentLine = 0;

    //bool isEmpty();
    //bool isFull();
    char pop();

    bool checking(ifstream& file, syntaxGenStack<char>& stack);

  private:
    int size = 128;
    int top = -1;
    bool end;
};
#endif
