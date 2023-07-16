#include "grid.hpp"
#include "globals.hpp"

void allocate_grid()
{
    grid = new char *[dimension];
    for (int i = 0; i < dimension; i++)
    {
        grid[i] = new char[dimension];
    }
}
