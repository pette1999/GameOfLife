#include <iostream>
#include <fstream>

using namespace std;

class grid
{
public:
    grid();
    grid(string filename);
    ~grid();

    //File reading part
    void readFile();
    void printFile();
    int getRow();
    int getCloumn();

    //Grid part
    void createGrid();
    void printGrid(char **grid);
    void printNewGrid(char **grid);
    char** getMyGrid();
    char** getNewGrid();

    ifstream inFile;
    string line;
    string fileName;
    int fileRow;
    int fileColumn;
    char **myGrid;
    char **newGrid; //a copy grid
};