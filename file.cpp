#include <iostream>
#include "file.h"

using namespace std;

file::file()
{
    fileName = "test.txt";
    ifstream inFile(fileName);//read the file
    line = "";
    int fileRow = 0;
    int fileCloumn = 0;

    if (!inFile)
    {
        cout << fileName << " does not exist. " << endl;
        exit(1);
    }
}

file::file(string filename)
{
    fileName = filename;
    ifstream inFile(fileName); //read the file
    line = "";
    int fileRow = 0;
    int fileCloumn = 0;

    if (!inFile)
    {
        cout << fileName << " does not exist. " << endl;
        exit(1);
    }
}

void file::readFile()
{
    inFile.open(fileName);
    getline(inFile,line); //get the file line from the file
    fileRow = stoi(line); //transform the string to int
    getline(inFile,line);
    fileColumn = stoi(line);
    inFile.close();

    cout << "Row: " << fileRow << endl;
    cout << "Column: " << fileColumn << endl;
}

void file::printFile()
{
    inFile.open(fileName);
    cout << "File: " << endl;
    while (getline(inFile, line)) //while there is a line in the file
    {
        cout << line << endl;
    }
    inFile.close();
}

int file::getRow()
{
    return fileRow;
}

int file::getCloumn()
{
    return fileColumn;
}