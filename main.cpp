#include <iostream>
#include "classic.h"

using namespace std;

int main(int argc, char** argv)
{
    grid g("test.txt");
    g.createGrid();

    char **grid = g.getMyGrid();
    char **newGrid = g.getNewGrid();

    g.printGrid(grid);
    g.printNewGrid(newGrid);

    classic c;
    c.classicMode(grid, newGrid, g.getRow(), g.getCloumn());
}