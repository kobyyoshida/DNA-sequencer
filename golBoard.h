//golBoard.h
#ifndef GOLBOARD_H
#define GOLBOARD_H
#include <iostream>

class Board{
  public:
    Board();
    ~Board();
    int rows;
    int columns;

    char* grid = new char[rows];
    char* grid2;

    void gameBoard(int rows,int columns);
    void copyGrid(char *grid,char *grid2, int rows, int columns);
    void setRandomDensity(char grid, float density, int rows, int columns);


  private:

};
#endif
