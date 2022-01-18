#Sudoku Random Game Generator - Liam Neate - With code from Backtracking Algorithm - Sudoku Solver - www.101computing.net/backtracking-algorithm-sudoku-solver/
from random import shuffle
from random import randint
from copy import deepcopy
#importing random to enter random numbers as solutions

#initialise empty 9 by 9 grid
grid = []
grid.append([0, 0, 0, 0, 0, 0, 0, 0, 0])
grid.append([0, 0, 0, 0, 0, 0, 0, 0, 0])
grid.append([0, 0, 0, 0, 0, 0, 0, 0, 0])
grid.append([0, 0, 0, 0, 0, 0, 0, 0, 0])
grid.append([0, 0, 0, 0, 0, 0, 0, 0, 0])
grid.append([0, 0, 0, 0, 0, 0, 0, 0, 0])
grid.append([0, 0, 0, 0, 0, 0, 0, 0, 0])
grid.append([0, 0, 0, 0, 0, 0, 0, 0, 0])
grid.append([0, 0, 0, 0, 0, 0, 0, 0, 0])
#Using deepcopy to create a copy that won't be changed once the other is
gridOG = deepcopy(grid)

#A function to check if the grid is full
def checkGrid(grid):
  for row in range(0,9):
      for col in range(0,9):
        if grid[row][col]==0:
          return False
    #Simple check using for and if's to check none of the squares equal 0

  #We have a complete grid!  
  return True 

#A backtracking/recursive function to check all possible combinations of numbers until a
#solution is found
def solveGrid(grid):
  #Find next empty cell
  for i in range(0,81):
    possibles = list(range(1,10))
    shuffle(possibles)
    row=i//9
    col=i%9
    #These are used to assure that each grid is checked.
    if grid[row][col]==0:
    #If found an empty square
      for value in possibles:
        #Check that this value has not already be used on this row
        if not(value in grid[row]):
          #print("Check")
          #Check that this value has not already be used on this column
          if not value in (grid[0][col],grid[1][col],grid[2][col],grid[3][col],grid[4][col],grid[5][col],grid[6][col],grid[7][col],grid[8][col]):
            #Identify which of the 9 squares we are working on
            square=[]
            if row<3:
              if col<3:
                square=[grid[i][0:3] for i in range(0,3)]
              elif col<6:
                square=[grid[i][3:6] for i in range(0,3)]
              else:  
                square=[grid[i][6:9] for i in range(0,3)]
            elif row<6:
              if col<3:
                square=[grid[i][0:3] for i in range(3,6)]
              elif col<6:
                square=[grid[i][3:6] for i in range(3,6)]
              else:  
                square=[grid[i][6:9] for i in range(3,6)]
            else:
              if col<3:
                square=[grid[i][0:3] for i in range(6,9)]
              elif col<6:
                square=[grid[i][3:6] for i in range(6,9)]
              else:  
                square=[grid[i][6:9] for i in range(6,9)]
            #Check that this value has not already be used on this 3x3 square
            if not value in (square[0] + square[1] + square[2]):
              grid[row][col]=value
              if checkGrid(grid):
                return True
              else:
                if solveGrid(grid):
                  return True
      break

def removeNumbers(grid, tempGrid):
    for i in range (0, randint(54, 64)):
        randVal = randint(0,80)
        randRow = randVal //9
        randCol = randVal % 9
        #Setting tempGrid to the current grid so it can make sure that it works with all
        #the numbers specified missing
        tempGrid = deepcopy(grid)
        tempGrid[randRow][randCol] = 0
        if (solveGrid(tempGrid) == True):
            grid[randRow][randCol]=0
        else:
            pass
    return True

#Doing the first grid create
solved = solveGrid(grid)
#Checking if it worked, if not, set grid back to 0's and try again until it works
while solved != True:
    grid = deepcopy(gridOG)
    solved = solveGrid(grid)
print("New grid generated!")
#Creating another copy of the grid so one can be tested to see 
tempGrid = deepcopy(grid)
removeNumbers(grid, tempGrid)
for x in grid:
    print(x)

#Change the solve grid to be used to see if a number that is passed through can work.
