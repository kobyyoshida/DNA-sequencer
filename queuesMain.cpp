#include "GenQueue.h"
#include <iostream>

using namespace std;

int main(int argc, char ** argv){
  GenQueue q(10);

  q.insert('r');
  q.insert('e');
  q.insert('p');

  cout<< "peek " << q.peek() << endl;
  cout << "remove " << q.remove() << endl;


  q.insert('b');
  q.insert('p');
  q.insert('d');

  while (!q.isEmpty())
    cout << "remove " << q.remove() << endl;
  return 0;
}
