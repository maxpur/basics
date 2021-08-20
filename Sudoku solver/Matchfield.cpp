#include "Matchfield.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

/*  Initialize data fields with default value 0 */
Matchfield::Matchfield(int size) :size(size) {

}

/*  Print soduku field seperated by '|' and '-' */
void Matchfield::printField() {
    printTopLine();
    for (int i = 0; i < size; i ++) {
        printLine(i);
        if (i < size - 1){
            printInterline();
        } else {
            printTopLine();
        }
        //Insert separators for each 3x3 block
        if ((i + 1) % 3 == 0 && i < size -1) {
            cout << "|";
            for (int i = 0; i < size * 3; i++) {
                cout << " ";
            }
            cout << "|" << endl;
            printInterline();
        }
    }
}

/*  Print top line of top and bottom line */
void Matchfield::printTopLine() {
    for (int i = 0; i < size * 3 + 2; i++) {
        cout << "-";
    }
    cout << endl;
}

/*  Print lines between top and bottom with whitespace between every 3x3 block */
void  Matchfield::printInterline() {
    string line = "-------";
    string space = "    ";
    cout << line << space << line << space << line << endl;
}

/*  Print line specified by index and seperate each value by '|' */
void Matchfield::printLine(int index) {
    string line = "|";
    for (int j = 0; j < size; j++) {
        if (field[index][j].value == 0) {
            line += " |";
        } else {
            line += std::to_string(field[index][j].value) + "|";
        }
        //Insert separators for each 3x3 block
        if ((j + 1) % 3 == 0 && j < size -1) {
            line += "    |";
        }
    }
    cout << line << endl;
}

/*  Set data field to given value specified by its x and y coordinates */
void Matchfield::setCell(Coordinate coordinate) {
    field[coordinate.row][coordinate.column].value = coordinate.value;
    field[coordinate.row][coordinate.column].properties = coordinate.properties;
}

/*  Get value of a data cell specified by its x and y coordinates 
    Return value of the specified cell */
int Matchfield::getCell(int x, int y) {
    return field[x][y].value;
}

/*  Get dimonsion of this soduko matchfield 
    Return size of the soduko field */
int Matchfield::getSize() {
    return size;
}

/*  Delete value of every cell */
void Matchfield::reset() {
    for (int row = 0; row < size; row++) {
        for (int column = 0; column < size; column++) {
            field[row][column].value = 0;
        } 
    }
}