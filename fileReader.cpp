//file reader

#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char ** argv){
  string filePath;
  if (argc != 2) { //Checks for valid command line arguments and saves argument to filePath variable
    cerr << "Incorrect number of arguments." << endl;
    return 0;
  }
  else {
    filePath = argv[1];
  }
  fstream in;
  in.open(filePath);

  if(in.is_open()){
    string line;
    while(getline(in,line)){
      cout << line << endl;
    }
    in.close();
  }

  }
