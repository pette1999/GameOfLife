#include <iostream>
#include "classic.h"

using namespace std;

classic::classic()
{
    neighbor_count = 0;
    done = false;
}

void classic::checkNeighnorCount(grid &g, int count, int r, int c)
{
    //A location that has one or fewer neighbors will be empty in the next generation
    if(count < 2)
    {
        g.updateNewGrid(r, c, '-');
    }
    //A location with two neighbors remains stable
    else if(count == 2)
    {
        g.updateNewGrid(r, c, g.getMyGrid()[r][c]);
    }
    //A location with three neighbors will contain a cell in the next generation
    else if(count == 3)
    {
        g.updateNewGrid(r, c, 'X');
    }
    //A location with four or more neighbors will be empty in the next generation
    else if(count > 3)
    {
        g.updateNewGrid(r, c, '-');
    }
}

void classic::classicMode()
{
    grid g("test.txt");
    g.createGrid();

    g.printGrid();
    g.printNewGrid();

    row = g.getRow();
    column = g.getCloumn();

    while(true)
    {
        int change_count = 0;

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < column; ++j)
            {
                neighbor_count = 0; //reset the neighbor count
                //To check corner, only needs to check three neighbors
                if ((i == 0 && j == 0))
                {
                    if (g.getValueFromGrid(0, j + 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(1, 0) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(1, j + 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    checkNeighnorCount(g, neighbor_count, i, j);
                    //check if chenged
                    if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                    {
                        change_count++; 
                    }
                    cout << "1: " << neighbor_count << endl;
                }
                else if (i == 0 && j == column - 1)
                {
                    if (g.getValueFromGrid(0, j - 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(1, j - 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(1, j) == 'X')
                    {
                        neighbor_count++;
                    }
                    checkNeighnorCount(g, neighbor_count, i, j);
                    //check if chenged
                    if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                    {
                        change_count++;
                    }
                    cout << "2: " << neighbor_count << endl;
                }
                else if (i == row - 1 && j == 0)
                {
                    if (g.getValueFromGrid(i - 1, j) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i - 1, j + 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i, j + 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    checkNeighnorCount(g, neighbor_count, i, j);
                    //check if chenged
                    if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                    {
                        change_count++;
                    }
                    cout << "3: " << neighbor_count << endl;
                }
                else if (i == row - 1 && j == column - 1)
                {
                    if (g.getValueFromGrid(i, j - 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i - 1, j) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i - 1, j - 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    checkNeighnorCount(g, neighbor_count, i, j);
                    //check if chenged
                    if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                    {
                        change_count++;
                    }
                    cout << "4: " << neighbor_count << endl;
                }
                //Check the 4 borders
                else if (i == 0 && j != 0 && j != column - 1)
                {
                    if (g.getValueFromGrid(i, j - 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i, j + 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i + 1, j - 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i + 1, j) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i + 1, j + 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    checkNeighnorCount(g, neighbor_count, i, j);
                    //check if chenged
                    if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                    {
                        change_count++;
                    }
                    cout << "First row: " << neighbor_count << endl;
                }
                else if (i == row - 1 && j != 0 && j != column - 1)
                {
                    if (g.getValueFromGrid(i, j - 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i, j + 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i - 1, j - 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i - 1, j) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i - 1, j + 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    checkNeighnorCount(g, neighbor_count, i, j);
                    //check if chenged
                    if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                    {
                        change_count++;
                    }
                    cout << "Last row: " << neighbor_count << endl;
                }
                else if (j == 0 && i != 0 && i != row - 1)
                {
                    if (g.getValueFromGrid(i - 1, j) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i + 1, j) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i - 1, j + 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i, j + 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i + 1, j + 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    checkNeighnorCount(g, neighbor_count, i, j);
                    //check if chenged
                    if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                    {
                        change_count++;
                    }
                    cout << "First column: " << neighbor_count << endl;
                }
                else if (j == column - 1 && i != 0 && i != row - 1)
                {
                    if (g.getValueFromGrid(i - 1, j) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i + 1, j) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i - 1, j - 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i, j - 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i + 1, j - 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    checkNeighnorCount(g, neighbor_count, i, j);
                    //check if chenged
                    if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                    {
                        change_count++;
                    }
                    cout << "Last column: " << neighbor_count << endl;
                }
                //The rest
                else if (i > 0 && i < row - 1 && j > 0 && j < column - 1)
                {
                    if (g.getValueFromGrid(i - 1, j - 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i - 1, j) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i - 1, j + 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i, j - 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i, j + 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i + 1, j - 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i + 1, j) == 'X')
                    {
                        neighbor_count++;
                    }
                    if (g.getValueFromGrid(i + 1, j + 1) == 'X')
                    {
                        neighbor_count++;
                    }
                    checkNeighnorCount(g, neighbor_count, i, j);
                    //check if chenged
                    if (g.getValueFromGrid(i, j) != g.getValueFromNewGrid(i, j))
                    {
                        change_count++;
                    }
                    cout << "Last column: " << neighbor_count << endl;
                }
            }
        }
        g.printNewGrid();

        // Cover the old grid with new grid
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < column; ++j)
            {
                g.updateMyGrid(i, j, g.getValueFromNewGrid(i, j));
            }
        }

        // If the different with the last one is 0, then break the loop, we found the final stage
        if(change_count == 0)
        {
            break;
        }
    }
}