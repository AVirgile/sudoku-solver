/*
** The main Header file For the project
** Made by virgile agnel
** name:
** sudoku
*/

#ifndef sudoku_h
#define sudoku_h

#include "libc.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define SIZE_PER_LINE (9)
#define SIZE_PER_BOX (3)
#define BLANK (0)
#define TRUE (1)

typedef struct simulate_s {
    int i;
    int j;
    int value;
} simulate;

typedef struct sudoku_s {
    int **array;
    unsigned int index;
    simulate *stack;
} sudoku;

bool token_is_digit(char const *token);
void free_tab(int **array);
bool grid_is_valid(int const **grid);
int solve_grid(sudoku *stct);
bool check_horizontal(int const **grid, int const i, int const j);
bool check_vertical(int const **grid, int const i, int const j);
bool check_box(int const **grid, int const i, int const j);
void print_grid(int const **grid);

#endif /* !SUDOKU_H */
