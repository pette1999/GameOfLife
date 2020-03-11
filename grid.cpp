#include <iostream>
#include "grid.h"

using namespace std;

grid::grid()
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

grid::grid(string filename)
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

grid::~grid()
{
    delete myGrid;
    delete newGrid;
}

void grid::readFile()
{
    inFile.open(fileName);
    getline(inFile,line); //get the file line from the file
    fileRow = stoi(line); //transform the string to int
    getline(inFile,line);
    fileColumn = stoi(line);
}

int grid::getRow()
{
    return fileRow;
}

int grid::getCloumn()
{
    return fileColumn;
}

//Grd part
void grid::createGrid()
{
    readFile();
    myGrid = new char *[fileRow]; //create a 1-D array
    newGrid = new char *[fileRow];

    for (int i = 0; i < fileRow; ++i)
    {
        myGrid[i] = new char[fileColumn]; //for each position in the 1-D array, we create another array in there
    }

    for (int i = 0; i < fileRow; ++i)
    {
        newGrid[i] = new char[fileColumn]; //for each position in the 1-D array, we create another array in there
    }

    //Set default grid
    for (int i = 0; i < fileRow; ++i)
    {
        for (int j = 0; j < fileColumn; ++j)
        {
            myGrid[i][j] = '-';
        }
    }

    for (int i = 0; i < fileRow; ++i)
    {
        for (int j = 0; j < fileColumn; ++j)
        {
            newGrid[i][j] = '-';
        }
    }

    //Set Grid
    //Don't need to read the file again, because I never closed reading the file in readFile()
    for (int i = 0; i < fileRow; ++i)
    {
        getline(inFile, line);
        int lineLength = line.length();
        for (int j = 0; j < fileColumn; ++j)
        {
            myGrid[i][j] = line[j];
        }
    }

    //Set the copy grid
    for (int i = 0; i < fileRow; ++i)
    {
        for (int j = 0; j < fileColumn; ++j)
        {
            newGrid[i][j] = myGrid[i][j];
        }
    }
}

void grid::printGrid()
{
    cout << "My Grid: " << endl;
    //create x-axis scalalr and y-axis scalar
    cout << " ";
    for(int k=0; k<fileColumn; ++k)
    {
        cout << " " << k;
    }
    cout << "\n";
    for (int i = 0; i < fileRow; ++i)
    {
        cout << i << " ";
        for (int j = 0; j < fileColumn; ++j)
        {
            cout << myGrid[i][j] << " ";
        }
        cout << "\n";
    }
}

void grid::printNewGrid()
{
    cout << "My New Grid: " << endl;
    //create x - axis scalalr and y - axis scalar
    cout << " ";
    for (int k = 0; k < fileColumn; ++k)
    {
        cout << " " << k;
    }
    cout << "\n";
    for (int i = 0; i < fileRow; ++i)
    {
        cout << i << " ";
        for (int j = 0; j < fileColumn; ++j)
        {
            cout << newGrid[i][j] << " ";
        }
        cout << "\n";
    }
}

void grid::updateMyGrid(int r, int c, char ch)
{
    myGrid[r][c] = ch;
}

void grid::updateNewGrid(int r, int c, char ch)
{
    newGrid[r][c] = ch;
}

char grid::getValueFromGrid(int r, int c)
{
    return myGrid[r][c];
}

char grid::getValueFromNewGrid(int r, int c)
{
    return newGrid[r][c];
}

char **grid::getMyGrid()
{
    return myGrid;
}

char** grid::getNewGrid()
{
    return newGrid;
}