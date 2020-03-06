#include <iostream>
#include <fstream>

using namespace std;

class file 
{
public:
    file();
    file(string filename);

    void readFile();
    void printFile();
    int getRow();
    int getCloumn();

    ifstream inFile;
    string line;
    string fileName;
    int fileRow;
    int fileColumn;
};