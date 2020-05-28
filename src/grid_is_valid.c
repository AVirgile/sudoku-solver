/*
** This is the file that check the grid to see if it is valid or not
** Made by virgile agnel
** name:
** grid_is_valid
*/

#include "sudoku.h"

static bool check_horizontal(int const **grid, int const i, int const j)
{
    for (int tmp = 0; tmp < SIZE_PER_LINE; tmp++) {
        if ((grid[i][tmp] == grid[i][j]) && (tmp != j))
            return (true);
    }
    return (false);
}

static bool check_vertical(int const **grid, int const i, int const j)
{
    for (int v = 0; grid[v]; v++) {
        if ((grid[i][j] == grid[v][j]) && (v != i))
            return (true);
    }
    return (false);
}

static bool check_box(int const **grid, int const i, int const j)
{
    int l = i;
    int c = j;

    if ((j - 2) % 3 == 0) 
        c = j - 2;
    if ((j - 1) % 3 == 0) 
        c = j - 1;
    if ((i - 2) % 3 == 0) 
        l = i - 2;
    if ((i - 1) % 3 == 0) 
        l = i - 1;
    for (int x = l; x < (SIZE_PER_BOX + l); x++) {
        for (int y = c; y < (SIZE_PER_BOX + c); y++) {
            if ((grid[x][y] == grid[i][j]) && (x != i && y != j))
                return (true);
        }
    }
    return (false);
}

bool grid_is_valid(int const **grid)
{
    for (int i = 0; grid[i]; i++) {
        for (int j = 0; j < SIZE_PER_LINE; j++) {
            if (grid[i][j] != 0) {
                if (check_horizontal(grid, i, j) == true) {
                    my_werror("Error the grid is not valid horizontaly\n");
                    return (false);
                }
                if (check_vertical(grid, i, j) == true) {
                    my_werror("Error the grid is not valid verticaly\n");
                    return (false);
                }
                if (check_box(grid, i, j) == true) {
                    my_werror("Error the grid is not valid in one box\n");
                    return (false);
                }
            }
        }
    }
    return (true);
}