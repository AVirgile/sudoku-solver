/*
** EPITECH PROJECT, 2019
** my_libC
** File description:
** my_libC
*/

#include "../../include/libc.h"

int my_isdigit(int c)
{
    if ((char) c >= '0' && (char) c <= '9')
        return (1);
    return (0);
}