# sudoku-solver

This program solve sudoku puzzle by using recursive backtracking algorithm but this is an iterative version :)

## how to run it

1. make sure to put your sudoku in a file that match this example bellow:

```
0, 7, 2, 0, 0, 4, 9, 0, 0
3, 0, 4, 0, 8, 9, 1, 0, 0
8, 1, 9, 0, 0, 6, 2, 5, 4
7, 0, 1, 0, 0, 0, 0, 9, 5
9, 0, 0, 0, 0, 2, 0, 7, 0
0, 0, 0, 8, 0, 7, 0, 1, 2
4, 0, 5, 0, 0, 1, 6, 2, 0
2, 3, 7, 0, 0, 0, 5, 0, 1
0, 0, 0, 0, 2, 5, 7, 0, 0
```
where the grid is 9 * 9 long and that the puzzle is valid otherwise the program will exit with a specific message
relative to your error

then compile using the following command
```
make
```

2. execute the program

to run the program use the command bellow:
```
./solve $1
```
where $1 is the path to the previous file where you put your sudoku

you can find premade sudoku to test the program in the directory **sudoku**

When the program finish you will have the answer show in the stdout of your terminal
