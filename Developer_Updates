#Developer timeline and updates


17/1/2022

Found a website that has some helpful ideas on it. All of the examples are done in python so I am going to work through them and try and understand all the steps they use, so I can try and make it in C++.

The way they do this is by first creating a backtracking program that tries to solve a sudoku grid. With that, it creates a whole soduku with a few numbers which will be the game board. It then takes one number away from the grid and runs it through the program again to see if it still works.

To begin with, since I'm doing a smaller grid, my program will be a bit simpler but will share quite similar functionality.

I have found another website that uses maths to figure out the minimum amount of squares that need to be full in order for it to be solvable. For a 4x4 grid, it needs at least 4, whole 9x9 needs 17

Sudoku ideas: https://www.101computing.net/sudoku-generator-algorithm/

Minimum amount: https://math.stackexchange.com/questions/2170944/sudoku-what-is-the-relationship-between-minimum-number-of-clues-and-order-n

18/1/2022

Using the backtracking algorithm provided by 101computing.net, I have created a random board generator. Mine uses the main functionality of the backtracking, the filling in the board, and applies it to an empty board. To do this I had to first set the board to empty to begin with. I quickly realised that they use a linear way of checking each number so the boards will always look the same. I added in random numbers that randomly sets the order of the numbers that are going to be checked. This creates a unique board each time. I also had to learn how to use copy.deepcopy as I had to make a copy of the original blank board so that I could easily set the current grid back to it, if the program creates a board that doesn't work.

Next I had to remove random numbers from the board that the user will have to fill in. I had to use my prior research of the minimum amount of numbers that have to be there in order for it to be solvable. Now I just had to use random numbers to remove numbers from the grid. I made another copy of the grid and used this to initially remove the numbers. I would remove random numbers from this temporary grid and then run it through the solver to see if it was still solvable. If it is solvable, then I would set the main grid as the same as the temporary grid. If it wasn't solvable, it would run the function again with a different number.

It then prints out the final grid to show the user.

Next I need to convert this into C++.
