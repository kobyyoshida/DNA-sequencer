//Koby Yoshida
#include <iostream>
#include <fstream>
#include "Syntax.h"
#include "syntaxGenStack.h"

using namespace std;

int main(int argc, char **argv){

  string filePath;
  if (argc != 2) { //Checks for valid command line arguments and saves argument to filePath variable
    cerr << "Incorrect number of arguments." << endl;
    return 0;
  }
  else {
    filePath = argv[1];
  }
  //beginning of file input
  ifstream in;
  in.open(filePath);
  if(!in){
    cerr << "File not found." << endl;
  }
  //1. create stack holding chars/strings
  syntaxGenStack<char> stack(100);
  Syntax checker;
  //syntaxGenStack stack = syntaxGenStack();
  //2. take file input analyzed as a command line argument
  //done above
  //3. check syntax
  bool check = checker.checking(in, stack);
  if(check){
    cout << "Found no errors. " << endl;
  }
  in.close();

  char answer;
  //this part checks if you want to run another file
  cout << "Would you like to run another file? (Enter 'y' or 'n') " << endl;
  if(answer == 'y'){
    cout << "Enter the name of your file. ";
    cin >> filePath;
  }
  else if (answer = 'n'){
    return 0;
  }
  else{
    cout << "Invalid entry. "<< endl;
    return 0;
  }
  //4. report if the syntax is okay or if an error has occurred
  //done in checking
  //5. report the problem if there is one
  //done in checking
}
