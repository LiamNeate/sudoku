/*! \mainpage Sudoku game documentation
 *
 * \section intro_sec Introduction
 *
 * This is the documentation to go along with my sudoku project.
 *
 * \subsection about About the program
 *
 * The sudoku game is a basic 9x9 grid the generates a random sudoku grid everytime. Each one should be spmewhat unique as all of the numbers are randomly generated on creation while also being solvable.
 * 
 * More details to come...
 */

/*! \file sudoku.h
	\brief The sudoku header file
*/

/*! \file Sudoku.cpp
	\brief The main sudoku file
*/

/* Sudoku Game
* SUDOKU_H_FILE
* Author : Liam Neate
--------------------------------------------------*/
/**************************************************/
/*                    DEPENDENCIES                */
/**************************************************/

#include <iostream>
#include <vector> //std::vector
#include <algorithm> //std::random_shuffle
#include <time.h> //time(0)
#include <chrono>
#include <thread>

/**************************************************/
/*                FUNCTION PROTOTYPES             */
/**************************************************/

/**@brief
*	Sets up the main sudoku variables and calls the functions
*/

void setUp();

/**@brief
*	Sets the grid to the initial state; blank.
*/

void blankGrid(int currList[][9]);

/**@brief
*	Generates the random completed sudoku grid
*
*@retval TRUE The grid is solved
*@retval FALSE The grid is unsolvable and hence, unsolved
*
*@param[out] currList
*	The current sudoku grid
*/

bool solveGrid(int currList[][9]);

/**@brief
*	Checks if the grid has any empty spaces
* 
*@retval TRUE The grid is complete with no empty squares
*@retval FALSE The grid is incomplete with empty squars
*
*@param[out] currList
*	The current sudoku grid
*/


bool checkGrid(int currList[][9]);

/**@brief
* Duplicates the current grid
*
*@param[out] currList
*	The current sudoku grid
*/

void duplicateGrid(int ogGrid[][9], int newGrid[][9]);

/**@brief
* Removes a random amount of numbers from the grid
*
*@param[out] currList
*	The current sudoku grid
*/

void removeNumbers(int currList[][9]);

/**@brief
* Displays the current state of the grid
* 
*@param[out] currList
*	The current sudoku grid
*/

void readGrid(int currList[][9]);

/**@brief
*	Initialises the playable game once everythin has been created
*
*@param[out] currList
*	The current sudoku grid
*
*@param[out] startGrid
*	The initial, solved grid
*
*@param[out] resetGrid
*	A copy of the inital state of the grid, used if the user has to reset the grid
*/

void play(int playerGrid[][9], int startGrid[][9], int resetGrid[][9]);

/**@brief
*	Checks that the player completed grid is the same as the solved grid
*
*@retval TRUE The grid is completed corerctly
*@retval FALSE The grid is completed incorrectly
*
*@param[out] currList
*	The current sudoku grid
*/

bool checkGridCorr(int startGrid[][9], int playerGrid[][9]);