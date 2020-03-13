#include <iostream>
#include <time.h>
#include "grid.h"

using namespace std;

grid::grid()
{
    fileName = "";
    //ifstream inFile(fileName);//read the file
    line = "";
    int fileRow = 0;
    int fileCloumn = 0;

    // if (!inFile)
    // {
    //     cout << fileName << " does not exist. " << endl;
    //     exit(1);
    // }
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

void grid::generateRandomGrid(int row, int column, double density)
{
    fileRow = row;
    fileColumn = column;
    srand(time(NULL)); //to reset rand(), to prevent getting the same random number
    // Initialize the grid
    myGrid = new char *[row]; //create a 1-D array
    newGrid = new char *[column];

    for (int i = 0; i < row; ++i)
    {
        myGrid[i] = new char[column]; //for each position in the 1-D array, we create another array in there
    }

    for (int i = 0; i < column; ++i)
    {
        newGrid[i] = new char[column]; //for each position in the 1-D array, we create another array in there
    }

    //Set default grid
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            myGrid[i][j] = '-';
        }
    }

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            newGrid[i][j] = '-';
        }
    }

    // Set the grid
    double r = 0.0;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            r = rand() / (double)RAND_MAX;
            if(r > 0 && r <= density)
            {
                myGrid[i][j] = 'X';
            }
            else
            {
                myGrid[i][j] = '-';
            }
        }
    }

    //Set the copy grid
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            newGrid[i][j] = myGrid[i][j];
        }
    }

    // Check how many X
    int count = 0;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            if(myGrid[i][j] == 'X')
            {
                count++;
            }
        }
    }
    cout << "There are " << count << " Xs." << endl;
    cout << "Density: " << density << endl;
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

void grid::writeNewToFile(string filename, int c)
{
    ofstream fileOut;
    fileOut.open(filename, std::ios_base::app);
    fileOut << "Classic mode: \n\n\n";
    fileOut << "Generation " << c << "\n";
    fileOut << "My New Grid: \n";
    fileOut << " ";
    for (int k = 0; k < fileColumn; ++k)
    {
        fileOut << " " << k;
    }
    fileOut << "\n";
    for (int i = 0; i < fileRow; ++i)
    {
        fileOut << i << " ";
        for (int j = 0; j < fileColumn; ++j)
        {
            fileOut << newGrid[i][j] << " ";
        }
        fileOut << "\n";
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