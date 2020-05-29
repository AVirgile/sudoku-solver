/*
** This is the file that contains the solve fct
** Made by virgile agnel
** name:
** solve
*/

#include "sudoku.h"

static int try_value(sudoku *stct, int const i, int const j, int start)
{
    for (int num = start; num < 10; num++) {
        stct->array[i][j] = num;
        if (check_horizontal((int const **) stct->array, i, j) == false
        && check_vertical((int const **) stct->array, i, j) == false
        && check_box((int const **) stct->array, i, j) == false) {
            stct->stack[stct->index].value = num;
            stct->stack[stct->index].i = i;
            stct->stack[stct->index].j = j;
            stct->index++;
            return (0);
        }
    }
    stct->array[i][j] = 0;
    return (-1);
}

int solve_grid(sudoku *stct)
{
    stct->stack = malloc(sizeof(simulate) * (SIZE_PER_LINE * SIZE_PER_LINE));
    if (stct->stack == NULL) {
        my_werror("Error while allocating memory in the heap\n");
        return (84);
    }
    for (int i = 0; stct->array[i]; i++) {
        for (int j = 0; j < SIZE_PER_LINE; j++) {
            if (stct->array[i][j] == BLANK) {
                if (try_value(stct, i, j, 1) == -1) {
                    while (TRUE) {
                        stct->array[i][j] = 0;
                        stct->stack[stct->index].i = 0;
                        stct->stack[stct->index].j = 0;
                        stct->stack[stct->index].value = 0;
                        stct->index--;
                        i = stct->stack[stct->index].i;
                        j = stct->stack[stct->index].j;
                        if (try_value(stct, i, j, stct->stack[stct->index].value + 1) == 0)
                            break;
                    }
                }
            }
        }
    }
    free(stct->stack);
    return (0);
}