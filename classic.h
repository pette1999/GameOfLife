#include <iostream>
#include "grid.h"

using namespace std;

class classic
{
public:
    classic();

    void checkNeighnorCount(grid &g, int count, int r, int c);
    void classicMode();

    int neighbor_count;
    int row;
    int column;
    bool done;
};