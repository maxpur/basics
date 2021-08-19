#include "Matchfield.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

/* Initialize data fields with default value 0 */
Matchfield::Matchfield(int size) :size(size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            field[i][j] = 0;
        }
    }
}

/* Print soduku field seperated by '|' and '-' */
void Matchfield::printField() {
    printTopLine();
    for (int i = 0; i < size; i ++) {
        printLine(i);
        printTopLine();
        //Insert separators for each 3x3 block
        if ((i + 1) % 3 == 0 && i < size -1) {
            cout << endl;
            printTopLine();
        }
    }
}

/* Print top line of each line */
void Matchfield::printTopLine() {
    for (int i = 0; i < size * 2 + 5; i++) {
        cout << "-";
    }
    cout << endl;
}

/* Print line specified by index and seperate each value by '|' */
void Matchfield::printLine(int index) {
    string line = "|";
    for (int j = 0; j < size; j++) {
        if (field[index][j] == 0) {
            line += " |";
        } else {
            line += std::to_string(field[index][j]) + "|";
        }
        //Insert separators for each 3x3 block
        if ((j + 1) % 3 == 0 && j < size -1) {
            line += " |";
        }
    }
    cout << line << endl;
}

/* Set data field to given value specified by its x and y coordinates */
void Matchfield::setField(int x, int y, int value) {
    field[x][y] = value;
}

/* Get value of a data cell specified by its x and y coordinates */
int Matchfield::getField(int x, int y) {
    return field[x][y];
}