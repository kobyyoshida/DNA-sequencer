//golchecking.h

#ifndef GOLCHECKING_H
#define GOLCHECKING_H

#include <iostream>
#include <cstdlib>


class Checking{

  public:
    Checking();
    ~Checking();

    int classicCheckNeighbors();
    int donutCheckNeighbors();
    int mirrorCheckNeighbors();
    void cellTransform();

    int activeNeighbors;
    int aliveCells;
    char grid;
    char grid2;
  private:

};

#endif
