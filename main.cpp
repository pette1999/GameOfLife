#include <iostream>
#include "file.h"
#include "grid.h"

using namespace std;

int main(int argc, char** argv)
{
    file f("test.txt");
    f.createGrid();
    f.printGrid();
}