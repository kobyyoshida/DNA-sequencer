#include <iostream>
#include "golBoard.h"

using namespace std;

//char* x[n];

Board::Board(){
  rows = 10;
  columns = 10;
}

Board::~Board(){

  /*for(int i = 0; i < columns; i++) {
    delete grid[i]*;
  }
  delete grid;
*/
}

//use this to create a game board object
void Board::gameBoard(int rows, int columns){//there is a density variable here, but it is not implemented in the body of the function
  rows = 10;
  columns = 10;
  grid = new char*[rows];
  for(int i = 0; i < rows;i++){
    grid[i] = new char[columns];
    for(int j= 0; j < columns;j++){
      grid[j] = '-';
    }
  };
    //return grid;


  /*
  void cleanGrid(){
    for(int i = 0; i < grid.size();i++){
      for(int j= 0; i < grid.size();j++){
        grid[i][j] = '-';
      }
    }
  };
*/
  void Board::copyGrid(char *grid,char *grid2, int rows, int columns){

    for(int i=0; i<rows;i++){
      grid2*[i] = grid*[i];
      for(int j=0; j<columns;j++){
        grid2*[j] = grid*[j];
      }
    }
  };

  void Board::setRandomDensity(char grid, float density, int rows, int columns){
  //Populate grid randomly
  srand(time(NULL)); //random seeded with time
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      double num = double(rand() % 100)/100; //random double from 0 - 1
      if(num > density)
      {
        grid[i][j] = '-';
      }
      else if(num <= density)
      {
        grid[i][j] = 'X';
      }
    }
  }
};
