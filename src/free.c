/*
** free allocated memory
** Made by virgile agnel
** name
** free
*/

#include "sudoku.h"

void free_tab(int **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
