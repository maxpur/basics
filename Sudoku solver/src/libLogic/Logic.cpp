#include "Logic.h"
#include <iostream>
using namespace std;
Logic::Logic(Matchfield &matchfield):matchfield(matchfield) {

}
/*  Solve the defined soduko field
    true if its solveable   */
bool Logic::solve() {
    //Initialize start point
    int row = 0;
    int column = 0;
    //true: end is reached
    bool end = false;
    //true: forward, false: backward
    bool direction = true;
    //As long as end or start point is not reached try to increase cell values
    while (!end) {
        Cell &cell = matchfield.getCell(row, column);
        //If cell ist marked as immutable, values cannot be changed, determine next row and column pair
        if (cell.properties == immutable) {
            getNextCoordinates(row, column, direction);
            continue;
        } else {
            cell.value = getNextValue(cell.value);
            //if next value leads to unsolveable soduko, try to increase the value of the current cell
            // as long as no overflow occurs
            while (!checkSolvability() && cell.value != 0) {
                cell.value = getNextValue(cell.value);
            }
            //Check if overflow happend and modify direction depending on it
            if (cell.value == 0) {
                direction = false;
            } else {
                direction = true;
            }
            //Determine next row and column pair
            getNextCoordinates(row, column, direction);
            //Check if prcocessing can be stopped
            if (row == -1 && column == -1) {
                end = true;
            }
        }
    }
    matchfield.printField();
    return checkSolvability();
}

/*  Calculate next sudoko cell that will be processed
    direction true: try to increase your current column
    direction false: try to decrese your current column
    currentRow = -1 && currentColumn == -1: End or start 
    point is reached, processing needs to be cancelled */
void Logic::getNextCoordinates(int &currentRow, int &currentColumn, bool direction) {
    //Increase
    if (direction) {
        if (currentColumn < 8) {
            currentColumn++;
        } else if (currentRow < 8 && currentColumn == 8) {
            currentRow++;
            currentColumn = 0;
        } else if (currentRow == 8 && currentColumn == 8) {
            currentRow = -1;
            currentColumn = -1;
        }
    } else {
        //Decrease
        if (currentColumn > 0) {
            currentColumn--;
        } else if (currentRow > 0 && currentColumn == 0) {
            currentRow--;
            currentColumn = 8;
        } else if (currentColumn == 0 && currentRow == 0) {
            currentRow = -1;
            currentColumn = -1;
        }
    }
}

/*  Calculate next possible value of a soduko cell
    return 0: overflow, step back and try to increase a predecessor
    return 1-9: valid value */
int Logic::getNextValue(int current) {
    if (current < 9) {
        return ++current;
    } else {
        return 0;
    }
}

/*  Check if every value between 1 and 9 occurs at most one time
    Conditions need to be valid in every 3x3 block, every row, every column and both diagonal directions
    true if every value occurs at most one time */
bool Logic::checkSolvability() {
    //Check rows
    for (int row = 0; row < matchfield.getSize(); row++) {
        if (!checkRow(row)) {
            return false;
        }
    }
    //Check columns
    for (int column = 0; column < matchfield.getSize(); column++) {
        if (!checkColumn(column)) {
            return false;
        }
    }
    //Check 3x3 bocks
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            if (!checkBlock(row * 3, column * 3)) {
                return false;
            }
        }
    }
    //Check diagonal directions
    return checkDiagonal();
}


/*  Check if every value occurs at most one time in every row
    true if every value occurs at most one time  */
bool Logic::checkRow(int row) {
    //Initialize array
    int line[10] = {0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < sizeof(line) / sizeof(line[0]); i++) {
        line[i] = 0;
    }
    //Determine multiplicity of each number
    for (int x = 0; x < matchfield.getSize(); x++) {
        line[matchfield.getCell(row, x).value]++;
    }
    //Check if each number appears at once
    for (int i = 0; i < sizeof(line) / sizeof(line[0]); i++) {
        if (line[i] > 1 && i != 0) {
            return false;
        }
    }
    return true;
}

/*  Check if every value occurs at most one time in every column
    true if every value occurs at most one time  */
bool Logic::checkColumn(int column) {
    //Initialize array
    int line[10] = {0,0,0,0,0,0,0,0,0,0};
    //Determine multiplicity of each number
    for (int y = 0; y < matchfield.getSize(); y++) {
        line[matchfield.getCell(y, column).value]++;
    }
    //Check if each number appears at once
    for (int i = 0; i < sizeof(line) / sizeof(line[0]); i++) {
        if (line[i] > 1 && i != 0) {
            return false;
        }
    }
    return true;
}

/*  Check if every value between 1 and 9 occurs at most one time in both diagonal directions
    true if every value occurs at most one time     */
bool Logic::checkDiagonal() {
    //Initialize array
    int line[10] = {0,0,0,0,0,0,0,0,0,0};
    //Determine multiplicity of each number
    for (int i = 0; i < matchfield.getSize(); i++) {
        line[matchfield.getCell(i, i).value]++;
    }
    //Check if each number appears at once
    for (int i = 0; i < sizeof(line) / sizeof(line[0]); i++) {
        if (line[i] > 1 && i != 0) {
            return false;
        }
    }
    //Initialize array 
    for (int i = 0; i < sizeof(line)/sizeof(line[0]); i++) {
        line[i] = 0;
    }
    //Determine multiplicity of each number
    for (int y = 0; y < matchfield.getSize(); y++) {
        line[matchfield.getCell(y, matchfield.getSize() - y).value]++;
    }
    //Check if each number appears at once
    for (int i = 0; i < sizeof(line) / sizeof(line[0]); i++) {
        if (line[i] > 1 && i != 0) {
            return false;
        }
    }
    return true;
}

/*  Check if every values occurs at most one time in every 3x3 block 
    row and column describe the start index of a 3x3 block
    true if every value occurs at most one time  */
bool Logic::checkBlock(int row, int column) {
    int line[10] = {0,0,0,0,0,0,0,0,0,0};
    //Count multiplicity of every value
    for (int i = row; i < row + 3; i++) {
        for (int j = column; j < column + 3; j++) {
            line[matchfield.getCell(i,j).value]++;
        }
    }
    //Check if at least one value has a multiplicity greater than 1
    for (int i = 0; i < sizeof(line) / sizeof(line[0]); i++) {
        if (i != 0 && line[i] > 1) {
            return false;
        }
    }
    return true;
}