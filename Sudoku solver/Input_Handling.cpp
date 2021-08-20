#include "Input_Handling.h"
#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::endl;
#define EXIT "exit"
#define SOLVE "solve"
#define CHECK "check"
#define NEW "new"
#define INSERT "insert"

/*Initialize Matchfield and Logic instances*/
Input_Handling::Input_Handling(Matchfield matchfield, Logic logic): matchfield(matchfield), logic(logic) {

}

/* Start loop to read user input and execute user commands */
void Input_Handling::startSolver() {
    printInstructions();
    string input = " ";
    cout << "Please insert your command!" << endl;
    getline(cin, input);
    while (1) {
        //Parse input
        switch (resolveOption(input)) {
            case exitField: 
                cout << "Goodbye!" << endl;
                return;
            case solve:
                logic.solve();
                matchfield.printField();
                break;
            case check:
                cout << "Soduko is solveable: " << logic.checkSolvability() << endl;
                break;
            case newField:
                matchfield.reset();
                matchfield.printField();
                break;
            case insert:
                Coordinate coordinate = parseInput(input);
                if (checkInput(coordinate)) {
                    matchfield.setCell(coordinate);
                    matchfield.printField();
                } else {
                    cout << "Invalid input, please try it again!";
                }
                break;
        }
        cout << "Please insert your next command!" << endl;
        getline(cin, input);
    } 

}

/* Print user instructions */
void Input_Handling::printInstructions() {
    cout << "Welcome! Lets solve a soduko!" << endl;
    cout << "You have several options to control this tool:" << endl;
    cout << "Type 'exit' to close this application." << endl;
    cout << "Type 'solve' to solve a configurated soduko field." <<endl;
    cout << "Type 'check' to check solvebility of a configurated soduko field." <<endl;
    cout << "Type 'new' to create a new soduko field." <<endl;
    cout << "Type 'insert <row> <column> <value>' to insert a specific value to a soduko cell. " << endl 
    << "Please be aware, there are only 9 rows and columns and the value needs to be between 0 and 9." <<endl;
}


/* Map user input to an integer for switch case usage 
   0: exit
   1: solve
   2: check
   3: new
   4: insert
   -1: error, invalid input
   Return corresponding int value*/
int Input_Handling::resolveOption(string &option) {
    if (option.find(EXIT) != string::npos) {
        return 0;    
    } else if (option.find(SOLVE) != string::npos) {
        return 1;
    } else if (option.find(CHECK) != string::npos) {
        return 2;
    } else if(option.find(NEW) != string::npos) {
        return 3;
    } else if(option.find(INSERT) != string::npos) {
        return 4;
    }
    return -1;
}

/* Parse user input to a soduko field cell 
   Throws std::out_of_range exception in case of invalid parametters
   Return Coordinate with specified column and row values as well as cell value*/
Coordinate Input_Handling::parseInput(string &input) {
    Coordinate coordinate;
    string delimiter = " ";
    cout << input << endl;
    try {
        coordinate.row = stoi(input.substr(input.find(delimiter), input.find(delimiter) + 1));
        input = input.erase(0, input.find(delimiter) + delimiter.length());
        coordinate.column = stoi(input.substr(input.find(delimiter), input.find(delimiter) + 1));
        input = input.erase(input.find(delimiter) - 1, input.find(delimiter) - 1 + delimiter.length());
        coordinate.value = stoi(input.substr(input.find(delimiter, input.find(delimiter) + 1)));
        coordinate.properties = immutable;
    } catch(std::out_of_range &e) {
        return coordinate;
    }
    return coordinate;
}

/* Check out of range values every attribute of a Coordinate
   Due to a 9x9 field every value needs to be less or eqaul to 9 and greater or equal to 0 
   True if all values are valid */ 
bool Input_Handling::checkInput(Coordinate coordinate) {
    if (coordinate.row > matchfield.getSize() ||coordinate.column > matchfield.getSize() | coordinate.value > matchfield.getSize()) {
        return false;
    }
    return true;
}