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

typedef struct sudoku_s {
    int **array;
} sudoku;

bool token_is_digit(char const *token);
void free_tab(int **array);

#endif /* !SUDOKU_H */
