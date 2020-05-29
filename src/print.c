/*
** This is the file that print the grid
** Made by virgile agnel
** name:
** main
*/

#include "sudoku.h"

void print_grid(int const **grid)
{
    for (int f = 0; f < (SIZE_PER_LINE * 2) + 1; f++) {
        my_printf("_");
        }
    my_printf("\n");
    for (int i = 0; grid[i]; i++) {
        for (int j = 0; j < SIZE_PER_LINE; j++) {
            my_printf("%d", grid[i][j]);
            if (j + 1 != SIZE_PER_LINE)
                my_printf(" ");
            if ((j + 1) % 3 == 0)
                my_printf("|");
        }
        my_printf("\n");
        if ((i + 1) % 3 == 0) {
            for (int f = 0; f < (SIZE_PER_LINE * 2) + 1; f++) {
                my_printf("_");
            }
            my_printf("|\n");
        }
    }
}