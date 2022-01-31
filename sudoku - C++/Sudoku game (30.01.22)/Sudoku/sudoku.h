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

#include <iostream> //For taking inputs and doing outputs
#include <vector> //Allows usage of vector types
#include <algorithm> //For randomising the grid
#include <time.h> //For generating new random numbers

/**************************************************/
/*                FUNCTION PROTOTYPES             */
/**************************************************/

/**@brief
*	Sets up the main sudoku variables and calls the functions
*/

void setUp();