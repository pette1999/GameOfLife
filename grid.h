#include <iostream>
#include <fstream>

using namespace std;

class grid
{
public:
    grid();
    grid(string filename);

    //File reading part
    void readFile();
    void printFile();
    int getRow();
    int getCloumn();

    //Grid part
    void createGrid();
    void printGrid();

    ifstream inFile;
    string line;
    string fileName;
    int fileRow;
    int fileColumn;
    char **myGrid;
};