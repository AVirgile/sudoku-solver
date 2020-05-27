/*
** This is the file with the main fct of the project
** Made by virgile agnel
** name:
** main
*/

#include "sudoku.h"

static size_t get_data_nb(char *line)
{
    size_t result = 0;
    char *token = my_strtok(line, " \n,");

    for (; token != NULL; token = my_strtok(NULL, " \n,"))
        result++;
    if (result != SIZE_PER_LINE) { 
        my_werror("Error the file must be 9 * 9\n");
        return (-1);
    }
    return (result);
}

static int *load_sudoku_line(char *line)
{
    int *result = NULL;
    char *duplicate = my_strdup(line);
    size_t data_nb = get_data_nb(duplicate);
    char *token = NULL;

    if (data_nb == -1)
        return (NULL);
    result = malloc(sizeof(int) * data_nb);
    if (result == NULL) {
        my_werror("CRITICAL -> mem allocation failed\n");
        return (NULL);
    }
    token = my_strtok(line, " ,\n");
    for (int i = 0; i < data_nb; i++) {
        if (token_is_digit(token) == false)
            return (NULL);
        result[i] = my_atoi(token);
        token = my_strtok(NULL, " ,\n");
    }
    free(duplicate);
    return (result);
}

static size_t get_line_size(char const *filepath)
{
    FILE *fp = fopen(filepath, "r");
    size_t result = 0;
    char *buffer = NULL;
    size_t i = 0;

    for (; getline(&buffer, &i, fp) > 0; result++);
    free(buffer);
    fclose(fp);
    if (result != SIZE_PER_LINE)
        return (-1);
    return (result);
}

static int load_in_memory(char const *filepath, sudoku *stct)
{
    FILE *fp = fopen(filepath, "r");
    char *buffer = NULL;
    size_t j = 0;
    size_t mem_size = get_line_size(filepath);

    if (mem_size == -1) {
        my_werror("Error the file must be 9 * 9 formated\n");
        fclose(fp);
        return (84);
    }
    stct->array = malloc(sizeof(int *) * (mem_size + 1));
    if (stct->array == NULL)
        return (84);
    for (int i = 0; getline(&buffer, &j, fp) > 0; i++) {
        stct->array[i] = load_sudoku_line(buffer);
        if (stct->array[i] == NULL)
           return (84);
        free(buffer);
        buffer = NULL;
    }
    stct->array[mem_size] = NULL;
    free(buffer);
    fclose(fp);
    return (0);
}

int main(int const argc, char const *argv[])
{
    sudoku stct = {0};

    if (argc != 2) {
        my_werror("Error: -> only pass one file as parameter\n");
        return (84);
    }
    if (load_in_memory(argv[1], &stct) == 84)
        return (84);
    for (int i = 0; stct.array[i]; i++) {
        for (int y = 0; y < SIZE_PER_LINE; y++)
            my_printf("%d, ", stct.array[i][y]);
        my_printf("\n");
    }
    free_tab(stct.array);
    return (0);
}
