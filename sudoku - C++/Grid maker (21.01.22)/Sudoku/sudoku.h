#include <iostream>
#include <vector> //std::vector
#include <algorithm> //std::random_shuffle
#include <time.h> //time(0)
#include <chrono>
#include <thread>

void blankGrid(int currList[][9]);
void readGrid(int currList[][9]);
bool checkGrid(int currList[][9]);
bool solveGrid(int currList[][9]);
void duplicateGrid(int ogGrid[][9], int newGrid[][9]);
void removeNumbers(int currList[][9]);
bool checkGridCorr(int startGrid[][9], int playerGrid[][9]);
void play(int playerGrid[][9], int startGrid[][9], int resetGrid[][9]);
void setUp();