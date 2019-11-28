//header file
#ifndef GOLGAME_H
#define GOLGAME_F
#include <iostream>
#include <cstdlib>
#include <fstream>


class Game{
  public:
    Game(); //constructor
    ~Game();//destructor


    int horizontalCells;
    int verticalCells;
    string outputType;
    int inputType;
    int pauseType;
    int gameMode;
    float density;

    string outputType;
    string inputType;




};
#endif
