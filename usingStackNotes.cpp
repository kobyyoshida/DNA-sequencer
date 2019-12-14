#include <iostream>
#include "GenStack.h"

using namespace std;

int main (int argc, char **argv){
  GenStack myStack (10);

  myStack.push('R');
  myStack.push('E');
  myStack.push('N');
  myStack.push('E');

  cout << "popping : " << mystack.pop() << endl;
  cout << "peeking : " << myStack.peek() << endl;

  myStack.push('F');
  cout << "now peeking : " << myStack.peek() << endl;

  while(!myStack.isEmpty()){
    cout << "popping :" << myStack.pop() << endl;
  }
  return 0;
}
