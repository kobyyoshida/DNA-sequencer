#include <iostream>
#include "golchecking.h"

using namespace std;

int aliveCells;
int activeNeighbors;

Checking::golchecking(){
  activeNeighbors = 0;
}

Checking::~golchecking(){

}


int Checking::classicCheckNeighbors(golBoard& grid, golBoard& grid2){

  //int rows;
  //int columns;
  //char cellNextGeneration;
  //char** grid = new char*[row];
  //char** grid2 = new char*[row];

  //this is all for the classic game mode for now i think
  for(int i = 0; i < rows;i++){
    for(int j= 0; j < columns;j++){

      //these if statments check the neighboring cells of each individual cells for classic mode
      //this section of the if statements will check the upper left cell and its neighbors
      if(i==0 && j==0){
        if(grid2[i][j+1]=='X'){
          activeNeighbors++;
        }
        if(grid2[i+1][j]=='X'){
          activeNeighbors++;
        }
        if(grid2[i+1][j+1]=='X'){
          activeNeighbors++;
        }

      }
      //this section of if statements is for the leftside border of the grid
      if(j==0&&i!=0){
        if(grid2[i][j+1]=='X'){//directly right
          activeNeighbors++;
        }
        if(grid2[i+1][j+1]=='X'){//lower right
          activeNeighbors++;
        }
        if(grid2[i-1][j+1]=='X'){//upper right
          activeNeighbors++;
        }
        //grid2[i][j].cellTransform();
      }
      //this section of if statments is for the upper boundary
      if (i==0&&(j!=0&&j!=columns)){
        if(grid2[i][j-1]=='X'){//directly left
          activeNeighbors++;
        }
        if(grid2[i+1][j-1]=='X'){//lower left
          activeNeighbors++;
        }
        if(grid2[i+1][j]=='X'){//below
          activeNeighbors++;
        }
        if(grid2[i+1][j+1]=='X'){//lower right
          activeNeighbors++;
        }
        if(grid2[i][j+1]=='X'){//directly right
          activeNeighbors++;
        }
      }
      //this section of if statements is for the rightside boundary
      if(j==columns&&(i!=rows&&i!=0)){
        if(grid2[i][j-1]=='X'){//directly left
          activeNeighbors++;
        }
        if(grid2[i-1][j-1]=='X'){//upper left
          activeNeighbors++;
        }
        if(grid2[i+1][j-1]=='X'){//lower left
          activeNeighbors++;
        }
        if(grid2[i-1][j]=='X'){//directly above
          activeNeighbors++;
        }
        if(grid2[i+1][j]=='X'){//directly below
          activeNeighbors++;
        }
      }
      //this section of if statements is for the lower boundary
      if(i==rows&&j!=columns){
        if(grid2[i-1][j-1]=='X'){//upper left
          activeNeighbors++;
        }
        if(grid2[i-1][j]=='X'){//dirctly above
          activeNeighbors++;
        }
        if(grid2[i-1][j+1]=='X'){//upper right
          activeNeighbors++;
        }
        if(grid2[i][j+1]=='X'){//directly right
          activeNeighbors++;
        }
        if(grid2[i][j-1]=='X'){//directly left
          activeNeighbors++;
        }
      }

      else{
        if(grid2[i-1][j-1]=='X'){//upper left
          activeNeighbors++;
        }
        if(grid2[i-1][j]=='X'){//directly up
          activeNeighbors++;
        }
        if(grid2[i-1][j+1]=='X'){//upper right
          activeNeighbors++;
        }
        if(grid2[i][j-1]=='X'){//directly left
          activeNeighbors++;
        }
        if(grid2[i][j+1]=='X'){//directly right
          activeNeighbors++;
        }
        if(grid2[i+1][j]=='X'){//directly down
          activeNeighbors++;
        }
        if(grid2[i+1][j-1]=='X'){//lower left
          activeNeighbors++;
        }
        if(grid2[i][j+1]=='X'){//lower right
          activeNeighbors++;
        }
      }
    }//for loop end
  }//for loop end
    return activeNeighbors;
}

int Checking::donutCheckNeighbors(golBoard grid, golBoard grid2){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){

        if(grid2[(i-1) % rows][(j-1) % columns]=='X'){//upper left
          activeNeighbors++;
        }
        if(grid2[(i-1)%rows][j%columns]=='X'){//directly up
          activeNeighbors++;
        }
        if(grid2[(i-1)%rows][(j+1)%columns]=='X'){//upper right
          activeNeighbors++;
        }
        if(grid2[i%rows][(j-1)%columns]=='X'){//directly left
          activeNeighbors++;
        }
        if(grid2[i%rows][(j+1)%columns]=='X'){//directly right
          activeNeighbors++;
        }
        if(grid2[(i+1)%rows][j%columns]=='X'){//directly down
          activeNeighbors++;
        }
        if(grid2[(i+1)%rows][(j-1)%columns]=='X'){//lower left
          activeNeighbors++;
        }
        if(grid2[i%rows][(j+1)%columns]=='X'){//lower right
          activeNeighbors++;
        }
      }
    }
    return activeNeighbors;
  }




int Checking::mirrorCheckNeighbors(golBoard grid, golBoard grid2){
  for(int i = 0; i < rows;i++){
    for(int j= 0; j < columns;j++){
      if(i==0&&j==0){//top left corner
        if(grid2[i][j]=='X'){//cell itself
          activeNeighbors+=3;
        }
        if(grid2[i][j+1]=='X'){//directly right
          activeNeighbors+=2;
        }
        if(grid2[i+1][j+1]=='X'){//diagonal down/right
          activeNeighbors++;
        }
        if(grid2[i+1][j]=='X'){//directly down
          activeNeighbors+=2;
        }
      }
      if(i==rows&&j==0){//bottom left corner
        if(grid2[i][j]=='X'){//cell itself
          activeNeighbors+=3;
        }
        if(grid2[i][j+1]=='X'){//directly right
          activeNeighbors+=2;
        }
        if(grid2[i-1][j+1]=='X'){//diagonal up/right
          activeNeighbors++;
        }
        if(grid2[i-1][j]=='X'){//directly up
          activeNeighbors+=2;
        }
      }
      if(i==0&&j==columns){//top right corner
        if(grid2[i][j]=='X'){//cell itself
          activeNeighbors+=3;
        }
        if(grid2[i][j-1]=='X'){//directly left
          activeNeighbors+=2;
        }
        if(grid2[i+1][j-1]=='X'){//diagonal down/left
          activeNeighbors++;
        }
        if(grid2[i+1][j]=='X'){//directly down
          activeNeighbors+=2;
        }
      }
      if(i==rows&&j==columns){//lower right corner
        if(grid2[i][j]=='X'){//cell itself
          activeNeighbors+=3;
        }
        if(grid2[i][j-1]=='X'){//directly left
          activeNeighbors+=2;
        }
        if(grid2[i-1][j-1]=='X'){//diagonal up/left
          activeNeighbors++;
        }
        if(grid2[i-1][j]=='X'){//directly up
          activeNeighbors+=2;
        }
      }

      //beginning of borders not corners

      if(j==0 && i!=0 && i!=rows){//left border
        if(grid2[i][j]=='X'){//cell itself
          activeNeighbors++;
        }
        if(grid2[i+1][j]=='X'){//directly down
          activeNeighbors+=2;
        }
        if(grid2[i-1][j]=='X'){//directly up
          activeNeighbors+=2;
        }
        if(grid2[i+1][j+1]=='X'){//diagonal down/right
          activeNeighbors++;
        }
        if(grid2[i][j+1]=='X'){//directly right
          activeNeighbors++;
        }
        if(grid2[i-1][j+1]=='X'){//diagonal up/right
          activeNeighbors++;
        }
      }
      if(i==0&&(j!=columns&&j!=0)){//top border
        if(grid2[i][j]=='X'){//cell itself
          activeNeighbors++;
        }
        if(grid2[i+1][j]=='X'){//directly down
          activeNeighbors++;
        }
        if(grid2[i][j-1]=='X'){//directly left
          activeNeighbors+=2;
        }
        if(grid2[i+1][j+1]=='X'){//diagonal down/right
          activeNeighbors++;
        }
        if(grid2[i][j+1]=='X'){//directly right
          activeNeighbors+=2;
        }
        if(grid2[i-1][j-1]=='X'){//diagonal down/left
          activeNeighbors++;
        }
      }

      if(j==columns && i!=0 && i!=rows){//rightside border
        if(grid2[i][j]=='X'){//cell itself
          activeNeighbors++;
        }
        if(grid2[i+1][j]=='X'){//directly down
          activeNeighbors+=2;
          }
        if(grid2[i-1][j]=='X'){//directly up
          activeNeighbors+=2;
        }
        if(grid2[i-1][j-1]=='X'){//diagonal up left
          activeNeighbors++;
        }
        if(grid2[i][j-1]=='X'){ //directly left
          activeNeighbors++;
        }
        if(grid2[i+1][j-1]=='X'){// diagonal down left
          activeNeighbors++;
          }
        }
      else{//any cell not on the edge
        if(grid2[i-1][j-1]=='X'){//upper left
          activeNeighbors++;
        }
        if(grid2[i-1][j]=='X'){//directly up
          activeNeighbors++;
        }
        if(grid2[i-1][j+1]=='X'){//upper right
          activeNeighbors++;
        }
        if(grid2[i][j-1]=='X'){//directly left
          activeNeighbors++;
        }
        if(grid2[i][j+1]=='X'){//directly right
          activeNeighbors++;
        }
        if(grid2[i+1][j]=='X'){//directly down
          activeNeighbors++;
        }
        if(grid2[i+1][j-1]=='X'){//lower left
          activeNeighbors++;
        }
        if(grid2[i][j+1]=='X'){//lower right
          activeNeighbors++;
        }
      }
      return activeNeighbors;

      }
    }


}


      //here, putting the if statements for if the cell will be alive in the next game board
      //these if statements need to go in some kind of loop while iterating through every cell of the game board

      void Checking::cellTransform(golBoard grid,golBoard grid2){
      if(activeNeighbors >= 4){//follows the rules of the game and updates the cell per generation
        grid[i][j] = '-';
        activeNeighbors = 0; //reset to 0 so that when we call the function in the checking loop it will automatically reset
        //aliveCells--;
      }
      else if(activeNeighbors == 1 || activeNeighbors == 0){
        grid[i][j] = '-';
        activeNeighbors = 0;
        //aliveCells--;
      }/*
      else if (activeNeighbors == 2){
        //stays the same
        grid[i][j] = grid2[i][j];
      }*/
      else if(activeNeighbors == 3){
        grid[i][j] = 'X';
        activeNeighbors = 0;
        //aliveCells++;

      }
    }
