/*
** Check if token is valid
** made by virgile agnel
** name
** token_is_digit
*/

#include "sudoku.h"

bool token_is_digit(char const *token)
{
    if (my_strlen(token) != 1) {
        my_werror("Error in parsing: Only a single digit allowed by index\n");
        return (false);
    }
    if (token[0] >= '0' && token[0] <= '9')
        return (true);
    my_werror("Error in parsing, Only a single digit allowed by index\n");
    return (false);
}
