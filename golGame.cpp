#include <iostream>
#include <time.h>
#include "golGame.h"

using namespace std;

int main(int argc, char ** argv){

  int horizontalCells;
  int verticalCells;
  string outputType;
  int inputType;
  int pauseType;
  int gameMode;
  float density;
  int aliveCells;

  int generation = 0;


  //all these ask the user how they would like the game to
  cout << "If you would like to provide a map for the file enter '1'" << endl;
  cout << "If you would like to enter a random assignment?" << endl;
  cin >> inputType;
  cout << "If you would like to output to a console enter '1'" << endl;
  cout << "If you would like to output to a file enter '2'" << endl;
  cin >> outputType;
  cout << "What kind of boundary mode would you like to run in? " << endl;
  cout << "Enter '1' for classic mode" << endl;
  cout << "Enter '2' for donut mode" << endl;
  cout << "Enter '3' for mirror mode" << endl;
  cin >> gameMode;
  cout << "If you would like a brief pause between generations, enter '1'" << endl;
  cout << "If you would like to press enter between generations, enter '2'" << endl;
  cout << "If you would like to output everything to a file, enter '3'" << endl;
  cin >> pauseType;



  if(inputType == 1){
    //needs filepath io
    string filePath;
    ifstream inputfile;
    cout << "Please enter the name of the file. " << endl;
    cin >> filePath;
    inputfile.open(filePath);

    if(!inputfile){//if the file does not exist
      cerr << "Could not find file. " << endl;
      return 0;
    }
    else{//if the file does exist
      cout << "Opened file " << filePath << endl;
      //read in the height and width
      string heightStr; //Arbitrary strings because getline requires an std::string for second arg
      string widthStr;
      getline(filePath,heightStr);//error checks
      getline(filePath,widthStr);
      try
      {
        rows = stoi(heightStr); //convert string variables to ints
        columns = stoi(widthStr);
      }
      catch(const std::invalid_argument& ia)
      {
        cerr << "ERROR in file. Invalid argument. \n" << endl;
        exit(EXIT_FAILURE);
      }
      //genGrid(); //Empty grid is generated with given dimensions
      //setGrid(filePath);
      filePath.close();
    }

    }


  else if(inputType == 2){
    cout <<"How many horizontal cells would you like? " << endl;
    cin >> horizontalCells;
    cout <<"How many vertical cells would you like? " << endl;
    cin >> verticalCells;
    cout << "How dense would you like the game board to be? (0-.99)" << endl;
    cin >> density;

  }


  golBoard grid = new *gameBoard(horizontalCells,verticalCells);
  golBoard grid2 = new *gameBoard(horizontalCells,verticalCells);

  if(gameMode == 1){
    while(aliveCells > 0){
      if(inputType == 1){

      }

      if(inputType == 2){
        grid.setRandomDensity(density);
      }

      grid2.copyGrid(grid,grid2,horizontalCells,verticalCells);
      grid2.classicCheckNeighbors(grid,grid2);
      grid.cellTransform(grid);
      cout << "Generation : " << generation << endl;
      generation++;
      cout << grid << endl;
      if (pauseType == 1){
        usleep(100000);
      }
      else if (pauseType == 2){
        cout << "'Enter' to continue" << endl;
        cin.ignore();
      }
      else if (pauseType == 3){
        ofstream out;
        out.open(outputFile);
        if(!out){
          exit(EXIT_FAILURE);
        }
      }
      //activeNeighbors = 0;
    }
  }
  if(gameMode == 2){
    while(aliveCells > 0){
      if(inputType == 2){
        grid.setRandomDensity(density);
      }
      grid2.copyGrid(grid,grid2,horizontalCells,verticalCells);
      grid2.classicCheckNeighbors(grid,grid2);
      grid.cellTransform(grid);
      cout << grid << endl;
      if (pauseType == 1){
        usleep(100000);
      }
      else if (pauseType == 2){
        cout << "'Enter' to continue" << endl;
        cin.ignore();
      }
      else if (pauseType == 3){
        ofstream out;
        out.open(outputFile);
        if(!out){
          exit(EXIT_FAILURE);
        }
      }
      //activeNeighbors = 0;
  }
  if(gameMode == 3){
    while(aliveCells > 0){
      grid2.copyGrid(grid,grid2,horizontalCells,verticalCells);
      grid2.mirrorCheckNeighbors(grid,grid2);
      grid.cellTransform(grid);
      cout << grid << endl;
      if (pauseType == 1){
        usleep(100000);
      }
      else if (pauseType == 2){
        cout << "'Enter' to continue" << endl;
        cin.ignore();
      }
      else if (pauseType == 3){
        ofstream out;
        out.open(outputFile);
        if(!out){
          exit(EXIT_FAILURE);
        }
      }
      //activeNeighbors = 0;
  }
}
