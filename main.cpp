#include <iostream>
#include "grid.h"

using namespace std;

int main(int argc, char** argv)
{
    grid g("test.txt");
    g.createGrid();
    g.printGrid();
}