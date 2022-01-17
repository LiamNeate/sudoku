# Sudoku game
Trying to make a sudoku game in C++

I will simply start by creating an 8 x 8 sudoku game with numbers 1-4

I will randomly generate a new game everytime the user wants to play. The games will always be solveable.

I will create a ascii grid to show the currently found numbers. To put in numbers, the user will have to select the grid using a select system. This will probably be done using letters for each grid that is empty. There will be validation checking on each input. If the input the user does is valid, it will show up on the grid.

There won't be any real time checking to begin with for each number to begin with (so the user can enter a wrong number but the game won't flag it up). This is to make the game more real, however, have been thinking of adding an assist mode later. The game will only say once the game has been completed.

17/1/2022

Found a website that has some helpful ideas on it. All of the examples are done in python so I am going to work through them and try and understand all the steps they use, so I can try and make it in C++.

The way they do this is by first creating a backtracking program that tries to solve a sudoku grid. With that, it creates a whole soduku with a few numbers which will be the game board. It then takes one number away from the grid and runs it through the program again to see if it still works.

To begin with, since I'm doing a smaller grid, my program will be a bit simpler but will share quite similar functionality.

I have found another website that uses maths to figure out the minimum amount of squares that need to be full in order for it to be solvable. For a 4x4 grid, it needs at least 4, whole 9x9 needs 17

Sudoku ideas: https://www.101computing.net/sudoku-generator-algorithm/

Minimum amount: https://math.stackexchange.com/questions/2170944/sudoku-what-is-the-relationship-between-minimum-number-of-clues-and-order-n
