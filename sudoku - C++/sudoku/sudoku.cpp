#include <iostream>
#include <vector> //std::vector
#include <algorithm> //std::random_shuffle
#include <time.h> //time(0)
#include <chrono>
#include <thread>

//Change to array, will be a lot easier

void blankGrid(int currList[][9]) {
    for (int i = 0; i < 81; i++) {
        int row = i / 9;
        int col = i % 9;
        currList[row][col] = 0;
    }
}

void readGrid(int currList[][9]) {
    std::cout << "-------------" << std::endl;
    for (int i = 0; i < 9; i++) {
        for (int x = 0; x < 9; x++) {
            if (x == 0){
                std::cout << "|";
            }
            std::cout << currList[i][x];
            if ((x+1) % 3 == 0 && x > 0) {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
        if ((i + 1) % 3 == 0 && i > 0) {
            std::cout << "-------------"<<std::endl;
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

bool solveGrid(int currList[][9]) {
    srand(time(0)); //making it so it is random each time
    std::vector<int> possibles;
    for (int x = 0; x < 81; x++) {
        for (int i = 1; i < 10; i++) {
            possibles.push_back(i);
        }
        std::random_shuffle(possibles.begin(), possibles.end());
        int tempRow = x / 9;
        int tempCol = x % 9;
        std::vector<int> colValues;
        std::vector<int> rowValues;
        for (int y = 0; y < 9; y++) {

            colValues.push_back(currList[tempRow][y]);
        }
        for (int y = 0; y < 9; y++) {
            rowValues.push_back(currList[y][tempCol]);
        }
        if (currList[tempRow][tempCol] == 0) {
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
                                    int squaRow = z / 3 ;
                                    int squaCol = z % 3 ;
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
                        int tempX = 0;
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

void removeNumbers(int currList[][9]) {
    int tempGrid[9][9];
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            tempGrid[x][y] = currList[x][y];
        }
    }
    int randDif = (rand() % 10 + 44);
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
        else{
            i--;
        }
    }
}

int main()
{
    int startGrid[9][9];
    blankGrid(startGrid);
    readGrid(startGrid);
    std::cout << "Loading new grid, please wait..." << std::endl;
    bool solved = solveGrid(startGrid);
    while (solved != true) {
        blankGrid(startGrid);
        solved = solveGrid(startGrid);
    }
    std::cout << "New grid made!"<< std::endl<< std::endl;
    readGrid(startGrid);
    std::cout << std::endl << "Loading sudoko puzzle..." << std::endl;
    removeNumbers(startGrid);
    readGrid(startGrid);
}