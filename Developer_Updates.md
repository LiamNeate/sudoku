# Developer timeline and updates


## 17/01/2022

Found a website that has some helpful ideas on it. All the examples are done in python so I am going to work through them and try and understand all the steps they use, so I can try and make it in C++.

The way they do this is by first creating a backtracking program that tries to solve a sudoku grid. With that, it creates a whole sudoku with a few numbers which will be the game board. It then takes one number away from the grid and runs it through the program again to see if it still works.

To begin with, since I'm doing a smaller grid, my program will be a bit simpler but will share quite similar functionality.

I have found another website that uses maths to figure out the minimum number of squares that need to be full in order for it to be solvable. For a 4x4 grid, it needs at least 4, whole 9x9 needs 17

**Sudoku ideas:** https://www.101computing.net/sudoku-generator-algorithm/

**Minimum amount:** https://math.stackexchange.com/questions/2170944/sudoku-what-is-the-relationship-between-minimum-number-of-clues-and-order-n

## 18/01/2022

Using the backtracking algorithm provided by 101computing.net, I have created a random board generator. Mine uses the main functionality of the backtracking, the filling in the board, and applies it to an empty board. To do this I had to first set the board to empty to begin with. I quickly realised that they use a linear way of checking each number so the boards will always look the same. I added in random numbers that randomly sets the order of the numbers that are going to be checked. This creates a unique board each time. I also had to learn how to use copy.deepcopy as I had to make a copy of the original blank board so that I could easily set the current grid back to it, if the program creates a board that doesn't work.

Next, I had to remove random numbers from the board that the user will have to fill in. I had to use my prior research of the minimum number of numbers that have to be there in order for it to be solvable. Now I just had to use random numbers to remove numbers from the grid. I made another copy of the grid and used this to initially remove the numbers. I would remove random numbers from this temporary grid and then run it through the solver to see if it was still solvable. If it is solvable, then I would set the main grid as the same as the temporary grid. If it wasn't solvable, it would run the function again with a different number.

It then prints out the final grid to show the user.

Next, I need to convert this into C++.

## 20/01/2022

I have now converted the python program successfully into C++. It was a lot harder than I had first anticipated and required me to learn a few new tools I had not yet come across such as `std::find` and `std::vector<int>::iterator`. I learned these thanks to websites such as stackoverflow.com and cplusplus.com. Overall, I am happy with how the C++ turned out, however, the only problem is that it takes quite a while to load even the original grid without the numbers removed. Then it takes even longer to remove the numbers because of all the checks and backtracking that does. I will have to try and optimise it next.

Once I have optimisation down, I need to start making the system for playing. I have got the board generated now I need to allow simple user inputs to play the game. I will start off with a simple text enter in the terminal, but I will then hopefully look into GUI's that I could utilise. I doubt adding user input will take me long so I should have this uploaded soon.

## 21/01/2022

I tried multiple different attempts to shorten the load times such as changing the sorting algorithm, minimising function calls and inline functions, but I could not get the grid creation time to be lower enough. I instead decided to leave it for now and comeback later as this did not directly affect its functionality. 

However, in good news, I have made the game playable at a very basic level. The grid is (eventually) printed out to the console and allows the user to play. It works by asking the user to input an x and y grid coordinate. It then checks if this coordinate is empty and, if it's empty, asks the user to input what they think the number is. The program has basic input validation, making sure the numbers are not more than single digits, but will need to come back and add more validation as the program crashes if a letter is accidentally put in instead. The program also detects once the user has fully filled the board in and then tells them if it is correct or not. If it is correct, it says well done and generates a new grid. If it is incorrect, it informs the user and resets the grid back to before the user entered anything.

Going forward, I want to add a menu for the user and the option to either play another grid or not. I also want to add an optional feature that will let the user know if a number is wrong as soon as they input it. I was also thinking maybe a hint function as well and a difficulty option that will be in the menu. For now, I have made good progress today and hope to start adding these features in the next few days.

## 30/01/2022

In this update, I have done 2 main things; generated doxygen documentation and created a class type.

The doxygen documentation is a HTML document that details what each part of the code does (there is a shortcut to it in this versions folder). It does this by looking for comments that use their syntax. Each comment has different types such as `@retval` which describes a return value, and `\param` which describes one of the function parameters. This generated documentation gives a easy to understand summary of how everything works and what each part does. It still has a bit of way to go however as the main doxygen page needs more information. More updates to come.

Adding a class type was a game changer for the program as, not only did it make the code easier to follow, but it also optimised the code fully and now there is virtually not waiting. The class is used for creating and using grids, hence the class name of `class Grid`. It creates each grid and defines each of the functions as well. This removes the need for so many variables to be passed. The grids consist of user grid, completed grid and temporary grid. Each of these are individual instances of grid so that they can ach individually be changed without calling them all. The main benefit is for the temporary grids as they are now getting destroyed each time after use, freeing up memory.

Now the code has become more efficient, I am going to focus on making a menu and even trying to add a database connection (it will become apparent soon as to why I am doing this).
