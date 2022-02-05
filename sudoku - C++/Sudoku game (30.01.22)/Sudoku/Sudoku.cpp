/** \file sudoku.h
 */
#include "sudoku.h"

//! The class used for creating grids
/*!
    This class has a variety of attributes both public and private. 
    These are all used to create the final grid, as well a the initial, and any temporary grids that are needed.
    It has a constructor as well as a destructor.
*/

class Grid {
    public:
        //! The class constructor.
        /*!
            The constructor is used to intialise the private values. It sets solved to false, and sets the playerGrid to all 0's (a blank grid).
        */
        Grid();
        //! The class destructor.
        /*!
            The destructor automatically is activated once the class is destroyed. It sets the playerGrid to be empty as to empty the current values from memory.
        */
        ~Grid();
        //! Takes the current playerGrid and fills the grid in with a solvable puzzle.
        /*!
            @retval TRUE   The grid is solved.
            @retval FALSE  The grid is unsolvable and hence, unsolved.
        */
        bool solveGrid();
        //! Removes random numbers from the grid.
        /*!
            Starts by generating a random number which is used to know how many numbers to remove.
            Creates a for loop using that number, where it removes a number from the temporary grid, and runs it through solveGrid().
            If the grid is solvable, it removes that number from playerGrid (and tempGrid) and runs again.
            If the grid is not solvable, it does not set the playerGrid, and instead, adds another loop to the for loop and runs again.
            \param tempGrid Another instance of Grid taken as an argument, which is used as a temporary version of the current grid.
            \sa solveGrid()
        */
        void removeNumbers(Grid tempGrid);
        //! Displays the current grid. 
        /*!
            Displays each line of the grid out to the user. Creates an ASCII grid to separate the sections to make it easier/nicer to read.
        */
        void readGrid();
        //! Checks if the grid is full or not.
        /*!
            Reads in each line of the grid and checks if any zeros are in there. If there is a zero, then the grid is not full. If there are no zeros, then the grid is full.
            @retval TRUE   The grid is full; contains no zeros.
            @retval FALSE  The grid is not full; contains zeros.
        */
        bool checkGrid();
        //! Duplicates the current grid to the otherGrid instance.
        /*!
            Reads in each line of the current playerGrid, and sets the otherGrid playerGrid to be the same. 
            \param tempGrid Another instance of Grid taken as an argument, which will copy playerGrid from the initial instance.
        */
        void dupeGrid(Grid otherGrid);
        //! Using the grids, starts the game and allows the user to play
        /*!
            To allow the user to play, it takes in two inputs for the x and y co-ordinate for the space on the grid they would like to fill.
            These are checked for validity and if the space is empty.
            Once validated, asks the user what number they think goes there.
            Checks that input then adds it to the grid and displays the new grid using readGrid().
            Runs checkGrid() to see if the grid is full.
            If checkGrid() returns false, it recalls itself to restart the function.
            If checkGrid() returns true, it will then compare the updated playerGrid to the fullGrid playerGrid.
            If they are the same, tells the user the grid is correct.
            Otherwise, tell the user it is incorrect and restarts the function with the copyGrid playerGrid as the playerGrid
            \param fullGrid Another instance of Grid taken as an argument; contains the completed grid to check against.
            \param copyGrid Another instance of Grid taken as an argument; contains a copy of the player grid in case it needs to be reset.
            \sa readGrid(), checkGrid()
        */
        void play(Grid fullGrid, Grid copyGrid);
        //! Checks the user filled in grid against the correctly completed grid.
        /*!
            Reads each line of the users playerGrid and compares to each line of the corrGrid playerGrid.
            \param corrGrid The correctly filled in grid.
            @retval TRUE   The user has completed the grid correctly.
            @retval FALSE  The user has incorrectly filled the grid.
            \sa play()
        */
        bool checkGridCorr(Grid corrGrid);
    private:
        //! The private variable for storing the grid.
        /*!
            Stores the player grid in a 2D integer array. Can be shown to the user in the readGrid() function
            \sa readGrid()
        */
        int playerGrid[9][9];
        //! The private variable for if the grid is initally solved or not.
        /*!
            Is a bool type that stores if the grid gets completed or not when it is initially filled with values.
            Is looped until true in setUp() so that a correct grid will always be generated.
            @retval TRUE    The grid is completed.
            @retval FALSE   The current grid cannot be completed.
            \sa setUp()
        */
        bool solved;
};

int main()
{
    setUp();
}

Grid::Grid() {
    for (int i = 0; i < 81; i++) {
        int row = i / 9;
        int col = i % 9;
        playerGrid[row][col] = 0;
    }
    solved = false;
}

Grid::~Grid() {
    for (int i = 0; i < 81; i++) {
        int row = i / 9;
        int col = i % 9;
        playerGrid[row][col] = 0;
    }
}

bool Grid::solveGrid() {
    std::vector<int> possibles;
    for (int x = 0; x < 81; x++) {
        int tempRow = x / 9;
        int tempCol = x % 9;
        if (playerGrid[tempRow][tempCol] == 0) {
            std::vector<int> colValues;
            std::vector<int> rowValues;
            for (int y = 0; y < 9; y++) {

                colValues.push_back(playerGrid[tempRow][y]);
                rowValues.push_back(playerGrid[y][tempCol]);
            }
            for (int i = 1; i < 10; i++) {
                possibles.push_back(i);
            }
            std::random_shuffle(possibles.begin(), possibles.end());
            for (auto value : possibles) {
                std::vector<int>::iterator found;
                found = std::find(colValues.begin(), colValues.end(), value);
                if (found == colValues.end()) {
                    found = std::find(rowValues.begin(), rowValues.end(), value);
                    if (found == rowValues.end()) {
                        int square[3][3];
                        if (tempRow < 3) {
                            if (tempCol < 3) {
                                for (int z = 0; z < 9; z++) {
                                    int squaRow = z / 3;
                                    int squaCol = z % 3;
                                    square[squaRow][squaCol] = playerGrid[squaRow][squaCol];
                                }
                            }
                            else if (tempCol < 6) {
                                for (int z = 0; z < 9; z++) {
                                    int squaRow = z / 3;
                                    int squaCol = z % 3;
                                    square[squaRow][squaCol] = playerGrid[squaRow][squaCol + 3];
                                }
                            }
                            else {
                                for (int z = 0; z < 9; z++) {
                                    int squaRow = z / 3;
                                    int squaCol = z % 3;
                                    square[squaRow][squaCol] = playerGrid[squaRow][squaCol + 6];
                                }
                            }
                        }
                        else if (tempRow < 6) {
                            if (tempCol < 3) {
                                for (int z = 0; z < 9; z++) {
                                    int squaRow = z / 3;
                                    int squaCol = z % 3;
                                    square[squaRow][squaCol] = playerGrid[squaRow + 3][squaCol];
                                }
                            }
                            else if (tempCol < 6) {
                                for (int z = 0; z < 9; z++) {
                                    int squaRow = z / 3;
                                    int squaCol = z % 3;
                                    square[squaRow][squaCol] = playerGrid[squaRow + 3][squaCol + 3];
                                }
                            }
                            else {
                                for (int z = 0; z < 9; z++) {
                                    int squaRow = z / 3;
                                    int squaCol = z % 3;
                                    square[squaRow][squaCol] = playerGrid[squaRow + 3][squaCol + 6];
                                }
                            }
                        }
                        else {
                            if (tempCol < 3) {
                                for (int z = 0; z < 9; z++) {
                                    int squaRow = z / 3;
                                    int squaCol = z % 3;
                                    square[squaRow][squaCol] = playerGrid[squaRow + 6][squaCol];
                                }
                            }
                            else if (tempCol < 6) {
                                for (int z = 0; z < 9; z++) {
                                    int squaRow = z / 3;
                                    int squaCol = z % 3;
                                    square[squaRow][squaCol] = playerGrid[squaRow + 6][squaCol + 3];
                                }
                            }
                            else {
                                for (int z = 0; z < 9; z++) {
                                    int squaRow = z / 3;
                                    int squaCol = z % 3;
                                    square[squaRow][squaCol] = playerGrid[squaRow + 6][squaCol + 6];
                                }
                            }
                        }
                        std::vector<int> gridValues;
                        for (int y = 0; y < 3; y++) {
                            for (int h = 0; h < 3; h++) {
                                gridValues.push_back(square[h][y]);
                            }
                        }
                        found = std::find(gridValues.begin(), gridValues.end(), value);
                        if (found == gridValues.end()) {
                            playerGrid[tempRow][tempCol] = value;
                            if (checkGrid()) {
                                return true;
                            }
                            else {
                                if (solveGrid()) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
            return false;
        }
    }
}

void Grid::dupeGrid(Grid otherGrid) {
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            playerGrid[x][y] = otherGrid.playerGrid[x][y];
        }
    }
}

bool Grid::checkGrid() {
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            if (playerGrid[x][y] == 0) {
                return false;
            }
        }
    }
    return true;
}

void Grid::removeNumbers(Grid tempGrid) {
    int randDif = (rand() % 10 + 35);
    for (int i = 0; i < randDif; i++) {
        int randVal = (rand() % 81);
        int randRow = randVal / 9;
        int randCol = randVal % 9;
        if (playerGrid[randRow][randCol] != 0) {
            tempGrid.playerGrid[randRow][randCol] = 0;
            if (tempGrid.solveGrid()) {
                playerGrid[randRow][randCol] = 0;
            }
            else {
                i--;
            }
            for (int x = 0; x < 9; x++) {
                for (int y = 0; y < 9; y++) {
                    tempGrid.playerGrid[x][y] = playerGrid[x][y];
                }
            }
        }
        else {
            i--;
        }
    }
}

void Grid::readGrid() {
    std::cout << "-------------" << std::endl;
    for (int i = 0; i < 9; i++) {
        for (int x = 0; x < 9; x++) {
            if (x == 0) {
                std::cout << "|";
            }
            std::cout << playerGrid[i][x];
            if (x > 0 && (x + 1) % 3 == 0) {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
        if (i > 0 && (i + 1) % 3 == 0) {
            std::cout << "-------------" << std::endl;
        }
    }
}

void Grid::play(Grid fullGrid, Grid copyGrid) {
    int xCoord; int yCoord;  int ansNumber;
    std::cout << "Enter the x co-ord of the square you would like to answer (top to bottom is 1 - 9): ";
    std::cin >> xCoord;
    std::cout << "Select the y co-ord of the square you would like to answer (left to right is 1 - 9): ";
    std::cin >> yCoord;
    if (1 > xCoord > 9 || 1 > yCoord > 9) {
        std::cout << "Invalid coords!" << std::endl;
        play(fullGrid, copyGrid);
    }
    else if (playerGrid[(xCoord - 1)][(yCoord - 1)] != 0) {
        std::cout << "That number already has a number in it!" << std::endl;
        play(fullGrid, copyGrid);
    }
    else {
        std::cout << "Enter the number you think it is: ";
        std::cin >> ansNumber;
        if (ansNumber > 9 || ansNumber < 1) {
            std::cout << "The number must be between 1 and 9!" << std::endl;
            play(fullGrid, copyGrid);
        }
        playerGrid[(xCoord - 1)][(yCoord - 1)] = ansNumber;
        readGrid();
        if (checkGrid()) {
            if (checkGridCorr(fullGrid)) {
                std::cout << "Well done! You completed the grid! Restarting the program" << std::endl;
                setUp();
            }
            else {
                std::cout << "Unfortuntely, you have made an error in the grid! Reseting the grid..." << std::endl;
                copyGrid.readGrid();
                play(fullGrid, copyGrid);
            }
        }
        else {
            play(fullGrid, copyGrid);
        }
    }
}

bool Grid::checkGridCorr(Grid corrGrid) {
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            if (playerGrid[x][y] != corrGrid.playerGrid[x][y]){
                return false;
            }
        }
    }
    return true;
}

void setUp() {
    srand(time(NULL)); //making it so it is random each time
    Grid completeGrid;
    std::cout << "Loading new grid, please wait..." << std::endl;
    bool solved = completeGrid.solveGrid();
    while (solved != true) {
        (&completeGrid)->~Grid();
        new (&completeGrid) Grid();
        completeGrid.readGrid();
        solved = completeGrid.solveGrid();
    }
    completeGrid.readGrid();
    std::cout << std::endl << "New grid made!" << std::endl;
    Grid playerGrid;
    Grid tempGrid;
    playerGrid.dupeGrid(completeGrid);
    tempGrid.dupeGrid(completeGrid);
    std::cout << std::endl << "Loading sudoko puzzle..." << std::endl;
    playerGrid.removeNumbers(tempGrid);
    playerGrid.readGrid();
    playerGrid.play(completeGrid, playerGrid);
}