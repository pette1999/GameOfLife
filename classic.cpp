#include <iostream>
#include "classic.h"

using namespace std;

classic::classic()
{
    neighbor_count = 0;
}

void classic::checkNeighnorCount(int count, char** grid, char** newGrid, int r, int c)
{
    //A location that has one or fewer neighbors will be empty in the next generation
    if(count < 2)
    {
        newGrid[r][c] = '-';
    }
    //A location with two neighbors remains stable
    else if(count == 2)
    {
        newGrid[r][c] = grid[r][c];
    }
    //A location with three neighbors will contain a cell in the next generation
    else if(count == 3)
    {
        newGrid[r][c] = 'X';
    }
    //A location with four or more neighbors will be empty in the next generation
    else
    {
        newGrid[r][c] = '-';
    }
}

void classic::classicMode(char **grid, char **newGrid, int row, int column)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            neighbor_count = 0; //reset the neighbor count
            //To check corner, only needs to check three neighbors
            if((i == 0 && j == 0))
            {
                if(grid[0][j+1] == 'X')
                {
                    neighbor_count++;
                }
                if(grid[1][0] == 'X')
                {
                    neighbor_count++;
                }
                if(grid[1][j+1] == 'X')
                {
                    neighbor_count++;
                }
                checkNeighnorCount(neighbor_count, grid, newGrid, i, j);
                g.printNewGrid(newGrid);
                cout << "1: " << neighbor_count << endl;
            }
            else if(i == 0 && j == column-1)
            {
                if (grid[0][j-1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[1][j-1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[1][j] == 'X')
                {
                    neighbor_count++;
                }
                checkNeighnorCount(neighbor_count, grid, newGrid, i, j);
                g.printNewGrid(newGrid);
                cout << "2: " << neighbor_count << endl;
            }
            else if(i == row-1 && j == 0)
            {
                if (grid[i-1][j] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i-1][j+1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i][j+1] == 'X')
                {
                    neighbor_count++;
                }
                checkNeighnorCount(neighbor_count, grid, newGrid, i, j);
                g.printNewGrid(newGrid);
                cout << "3: " << neighbor_count << endl;
            }
            else if (i == row - 1 && j == column - 1)
            {
                if (grid[i][j-1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i-1][j] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i-1][j-1] == 'X')
                {
                    neighbor_count++;
                }
                checkNeighnorCount(neighbor_count, grid, newGrid, i, j);
                g.printNewGrid(newGrid);
                cout << "4: " << neighbor_count << endl;
            }
            //Check the 4 borders
            else if(i == 0 && j != 0 && j != column-1)
            {
                if (grid[i][j - 1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i][j + 1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i + 1][j - 1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i + 1][j] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i + 1][j + 1] == 'X')
                {
                    neighbor_count++;
                }
                checkNeighnorCount(neighbor_count, grid, newGrid, i, j);
                g.printNewGrid(newGrid);
                cout << "First row: " << neighbor_count << endl;
            }
            else if (i == row - 1 && j != 0 && j != column - 1)
            {
                if (grid[i][j - 1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i][j + 1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i - 1][j - 1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i - 1][j] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i - 1][j + 1] == 'X')
                {
                    neighbor_count++;
                }
                checkNeighnorCount(neighbor_count, grid, newGrid, i, j);
                g.printNewGrid(newGrid);
                cout << "Last row: " << neighbor_count << endl;
            }
            else if (j == 0 && i != 0 && i != row - 1)
            {
                if (grid[i - 1][j] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i + 1][j] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i - 1][j + 1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i][j + 1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i + 1][j + 1] == 'X')
                {
                    neighbor_count++;
                }
                checkNeighnorCount(neighbor_count, grid, newGrid, i, j);
                g.printNewGrid(newGrid);
                cout << "First column: " << neighbor_count << endl;
            }
            else if (j == column - 1 && i != 0 && i != row - 1)
            {
                if (grid[i - 1][j] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i + 1][j] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i - 1][j - 1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i][j - 1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i + 1][j - 1] == 'X')
                {
                    neighbor_count++;
                }
                checkNeighnorCount(neighbor_count, grid, newGrid, i, j);
                g.printNewGrid(newGrid);
                cout << "Last column: " << neighbor_count << endl;
            }
            //The rest
            else if (i > 0 && i < row - 1 && j > 0 && j < column - 1)
            {
                if (grid[i - 1][j - 1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i - 1][j] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i - 1][j + 1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i][j - 1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i][j + 1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i + 1][j - 1] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i + 1][j] == 'X')
                {
                    neighbor_count++;
                }
                if (grid[i + 1][j + 1] == 'X')
                {
                    neighbor_count++;
                }
                checkNeighnorCount(neighbor_count, grid, newGrid, i, j);
                g.printNewGrid(newGrid);
                cout << "Last column: " << neighbor_count << endl;
            }
        }
    }
}