/*
** EPITECH PROJECT, 2019
** my_libC
** File description:
** my_libC
*/

#include "../../include/libc.h"

int my_iscntrl(int c)
{
    if ((char) c <= 31 || (char) c == 127)
        return (1);
    return (0);
}