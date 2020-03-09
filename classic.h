#include <iostream>
#include "grid.h"

using namespace std;

class classic
{
public:
    classic();

    void checkNeighnorCount(int count,char** grid, char** newGrid, int r, int c);
    void classicMode(char** grid, char** newGrid, int row, int column);

    int neighbor_count;
    grid g;
};