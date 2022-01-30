#include "sudoku.h"
int main()
{
    setUp();
}

void setUp() {
    int playerGrid[9][9];
    blankGrid(playerGrid);
    std::cout << "Loading new grid, please wait..." << std::endl;
    bool solved = solveGrid(playerGrid);
    while (solved != true) {
        blankGrid(playerGrid);
        solved = solveGrid(playerGrid);
    }
    std::cout << "New grid made!" << std::endl << std::endl;
    int startGrid[9][9];
    duplicateGrid(playerGrid, startGrid);
    std::cout << std::endl << "Loading sudoko puzzle..." << std::endl;
    removeNumbers(playerGrid);
    readGrid(playerGrid);
    int resetGrid[9][9];
    duplicateGrid(playerGrid, resetGrid);
    play(playerGrid, startGrid, resetGrid);
}

void blankGrid(int currList[][9]) {
    for (int i = 0; i < 81; i++) {
        int row = i / 9;
        int col = i % 9;
        currList[row][col] = 0;
    }
}

bool solveGrid(int currList[][9]) {
    srand(time(0)); //making it so it is random each time
    std::vector<int> possibles;
    for (int x = 0; x < 81; x++) {
        int tempRow = x / 9;
        int tempCol = x % 9;
        if (currList[tempRow][tempCol] == 0) {
            std::vector<int> colValues;
            std::vector<int> rowValues;
            for (int y = 0; y < 9; y++) {

                colValues.push_back(currList[tempRow][y]);
                rowValues.push_back(currList[y][tempCol]);
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
                                    square[squaRow][squaCol] = currList[squaRow][squaCol];
                                }
                            }
                            else if (tempCol < 6) {
                                for (int z = 0; z < 9; z++) {
                                    int squaRow = z / 3;
                                    int squaCol = z % 3;
                                    square[squaRow][squaCol] = currList[squaRow][squaCol + 3];
                                }
                            }
                            else {
                                for (int z = 0; z < 9; z++) {
                                    int squaRow = z / 3;
                                    int squaCol = z % 3;
                                    square[squaRow][squaCol] = currList[squaRow][squaCol + 6];
                                }
                            }
                        }
                        else if (tempRow < 6) {
                            if (tempCol < 3) {
                                for (int z = 0; z < 9; z++) {
                                    int squaRow = z / 3;
                                    int squaCol = z % 3;
                                    square[squaRow][squaCol] = currList[squaRow + 3][squaCol];
                                }
                            }
                            else if (tempCol < 6) {
                                for (int z = 0; z < 9; z++) {
                                    int squaRow = z / 3;
                                    int squaCol = z % 3;
                                    square[squaRow][squaCol] = currList[squaRow + 3][squaCol + 3];
                                }
                            }
                            else {
                                for (int z = 0; z < 9; z++) {
                                    int squaRow = z / 3;
                                    int squaCol = z % 3;
                                    square[squaRow][squaCol] = currList[squaRow + 3][squaCol + 6];
                                }
                            }
                        }
                        else {
                            if (tempCol < 3) {
                                for (int z = 0; z < 9; z++) {
                                    int squaRow = z / 3;
                                    int squaCol = z % 3;
                                    square[squaRow][squaCol] = currList[squaRow + 6][squaCol];
                                }
                            }
                            else if (tempCol < 6) {
                                for (int z = 0; z < 9; z++) {
                                    int squaRow = z / 3;
                                    int squaCol = z % 3;
                                    square[squaRow][squaCol] = currList[squaRow + 6][squaCol + 3];
                                }
                            }
                            else {
                                for (int z = 0; z < 9; z++) {
                                    int squaRow = z / 3;
                                    int squaCol = z % 3;
                                    square[squaRow][squaCol] = currList[squaRow + 6][squaCol + 6];
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
                            currList[tempRow][tempCol] = value;
                            if (checkGrid(currList) == true) {
                                return true;
                            }
                            else {
                                if (solveGrid(currList) == true) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
            break;
        }
    }
}

bool checkGrid(int currList[][9]) {
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            if (currList[x][y] == 0) {
                return false;
            }
        }
    }
    return true;
}

void duplicateGrid(int ogGrid[][9], int newGrid[][9]) {
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            newGrid[x][y] = ogGrid[x][y];
        }
    }
}

void removeNumbers(int currList[][9]) {
    int tempGrid[9][9];
    duplicateGrid(currList, tempGrid);
    int randDif = (rand() % 10 + 35);
    for (int i = 0; i < randDif; i++) {
        int randVal = (rand() % 81);
        int randRow = randVal / 9;
        int randCol = randVal % 9;
        if (currList[randRow][randCol] != 0) {
            tempGrid[randRow][randCol] = 0;
            if (solveGrid(tempGrid) == true) {
                currList[randRow][randCol] = 0;
            }
            else {
                i--;
            }
            for (int x = 0; x < 9; x++) {
                for (int y = 0; y < 9; y++) {
                    tempGrid[x][y] = currList[x][y];
                }
            }
        }
        else {
            i--;
        }
    }
}

void readGrid(int currList[][9]) {
    std::cout << "-------------" << std::endl;
    for (int i = 0; i < 9; i++) {
        for (int x = 0; x < 9; x++) {
            if (x == 0) {
                std::cout << "|";
            }
            std::cout << currList[i][x];
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

void play(int playerGrid[][9], int startGrid[][9], int resetGrid[][9]) {
    int xCoord; int yCoord;  int ansNumber;
    std::cout << "Enter the x co-ord of the square you would like to answer (top to bottom is 1 - 9): ";
    std::cin >> xCoord;
    std::cout << "Select the y co-ord of the square you would like to answer (left to right is 1 - 9): ";
    std::cin >> yCoord;
    if (1 > xCoord > 9 || 1 > yCoord > 9) {
        std::cout << "Invalid coords!" << std::endl;
        play(playerGrid, startGrid, resetGrid);
    }
    else if (playerGrid[(xCoord - 1)][(yCoord - 1)] != 0) {
        std::cout << "That number already has a number in it!" << std::endl;
        play(playerGrid, startGrid, resetGrid);
    }
    else {
        std::cout << "Enter the number you think it is: ";
        std::cin >> ansNumber;
        if (ansNumber > 9 || ansNumber < 1) {
            std::cout << "The number must be between 1 and 9!" << std::endl;
            play(playerGrid, startGrid, resetGrid);
        }
        playerGrid[(xCoord - 1)][(yCoord - 1)] = ansNumber;
        readGrid(playerGrid);
        if (checkGrid(playerGrid)) {
            if (checkGridCorr(startGrid, playerGrid)) {
                std::cout << "Well done! You completed the grid! Restarting the program" << std::endl;
                setUp();
            }
            else {
                std::cout << "Unfortuntely, you have made an error in the grid! Reseting the grid..." << std::endl;
                readGrid(resetGrid);
                play(resetGrid, startGrid, resetGrid);
            }
        }
        else {
            play(playerGrid, startGrid, resetGrid);
        }
    }
}

bool checkGridCorr(int startGrid[][9], int playerGrid[][9]) {
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            if (playerGrid[x][y] != startGrid[x][y]){
                return false;
            }
        }
    }
    return true;
}