"""
  Rule 1001 - challenge4
  This python function calculates the next iteration of Rule 110
  The function considers indexes outside the bounds of the list to be 0
  Author: Adrian Thomas Capacite
  Date: 19 / 06 / 2022
"""
# For a better visualisation paste code from link https://mcsp.wartburg.edu/zelle/python/graphics.py into an adjacent file named graphics.py
try:
  from graphics import *
except:
  print("Module graphics.py is not installed")
import sys

# Function to calculate next iteration of Rule 110
def rule110(c):
  # convert input string to list of integers then initialise list of new cels with 0s of same length
  cells = [int(x) for x in c]
  new_cells = [0 for i in cells]
  # add 0s to both ends of the list, this is our cells outside of list
  cells.insert(0,0)
  cells.append(0)

  # iterate through each cell of the list excluding the 0s added on both ends
  for i in range(1,len(cells)-1):
    # Compare cells before, on and after index against rule then modify new_cells to reflect rule
    x,y,z = map(int,cells[i-1:i+2])
    # Boolean expression: (X ∧ (Y ⊕ Z)) ∨ ((¬X) ∧ (Y ∨ Z))
    xor = lambda x,y: (y and (not z)) or ((not y) and z)
    new_cells[i-1] = int(((x and (xor(x,y))) or ((not x) and (y or z))))

  # Return string of new cells converted from list of integers
  return "".join(str(i) for i in new_cells)# print(rule110(cells))

# Creates a window to display the rule
def drawCellGrid(cell_grid):
  # Exit function if module graphics is not installed
  if not sys.modules.get('graphics'):
    raise Exception("Module graphics.py is not installed")

  # Get dimensions of cell grid and convert to integers
  row_count = len(cell_grid)
  col_count = len(cell_grid[0])
  for i in range(row_count): cell_grid[i] = [int(x) for x in cell_grid[i]]

  # Initialise graphics window
  win = GraphWin("Rule 110", 800, 800)
  win.setCoords(0,row_count,col_count,0)

  # Draw cells
  for i in range(row_count):
    for j in range(col_count):
      if cell_grid[i][j] == 1:
        cell = Rectangle(Point(j,i), Point(j+1,i+1))
        cell.setFill("black")
        cell.draw(win)

  # Wait for user to close window
  win.getMouse()
  win.close()


if __name__ == "__main__":
  cells = ""
  cell_grid = [""]

  print("Challenge 4: Rule 110")

  # Get row count
  row_count = input("Enter number of rows (default 128): ")
  if row_count == "":
    row_count = 128
  else:
    row_count = int(row_count)

  # Get initial cells
  cell_grid[0] = input("Enter initial cells (blank for default): ")
  if cell_grid[0] == "":
    cell_grid[0] = "00000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000"

  print("\nInitial cells: " + cells)
  print("Number of rows: " + str(row_count))

  # Create cell grid using rule 110
  for i in range(1,row_count): cell_grid.append(rule110(cell_grid[i-1]))

  # Print cell grid
  for i in range(row_count): print(cell_grid[i].replace("1", "█").replace("0", " "))

  # Draw cell grid in turtle, requires graphics module
  try:
    drawCellGrid(cell_grid)
  except Exception as e:
    print(e)
