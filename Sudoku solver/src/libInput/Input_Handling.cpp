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
#define PRINT "print"
#define HELP "help"

enum InputOptions {
    exitField,
    solve,
    check,
    newField,
    insert,
    print, 
    help
};

/*Initialize Matchfield and Logic instances*/
Input_Handling::Input_Handling(Matchfield &matchfield, Logic &logic):matchfield(matchfield),logic(logic) {

}

/* Start loop to read user input and execute user commands */
void Input_Handling::startSolver() {
    printInstructions();
    string input = " ";
    cout << "Please insert your command!" << endl;
    getline(cin, input);
    DataPair dataPair;
    while (1) {
        //Parse input
        switch (resolveOption(input)) {
            case exitField: 
                cout << "Goodbye!" << endl;
                return;
            case solve:
                logic.solve();
                break;
            case check:
                cout << "Soduko is solveable: " << logic.checkSolvability() << endl;
                break;
            case newField:
                matchfield.reset();
                break;
            case insert:
                dataPair = parseInput(input);
                if (checkInput(dataPair)) {
                    if (dataPair.cell.value != 0) {
                        matchfield.setCell(dataPair.row, dataPair.column, dataPair.cell.value, immutable);
                    } else {
                        matchfield.setCell(dataPair.row, dataPair.column, dataPair.cell.value, changeable);

                    }
                } else {
                    cout << "Invalid input, please try it again!";
                }
                break;
            case print:
                matchfield.printField();
                break;
            case help:
                printHelpInstruction();
                break;
            default: 
                cout << "No matching command found." << endl;
        }
        cout << "Please insert your next command!" << endl;
        getline(cin, input);
    } 

}

/* Print user instructions */
void Input_Handling::printInstructions() {
    cout << "Welcome! Lets solve a soduko!" << endl;
    cout << "You have several options to control this tool." << endl;
    cout << "If you dont know how to use this tool type 'help'." << endl;
}

void Input_Handling::printHelpInstruction() {
    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "exit                                   Close application" << endl;
    cout << "solve                                  Solve defined soduko field" << endl;
    cout << "check                                  Check for solvability (1: solvable)" << endl;
    cout << "new                                    Reset soduko field" << endl;
    cout << "insert <row,column,value> <...>        Insert multiple input cells" << endl;
    cout << "print                                  Print current soduko field" << endl;
    cout << "Please be aware, there are only 9 rows and columns and the value needs to be between 0 and 9." <<endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;
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
    } else if(option.find(PRINT) != string::npos) {
        return 5;
    } else if(option.find(HELP) != string::npos) {
        return 6;
    }
    return -1;
}

/* Parse user input to a soduko field cell 
   Throws std::out_of_range exception in case of invalid parametters
   Return Coordinate with specified column and row values as well as cell value*/
DataPair Input_Handling::parseInput(string &input) {
    DataPair dataPair;
    string delimiter = " ";
    cout << input << endl;
    try {
        dataPair.row = stoi(input.substr(input.find(delimiter), input.find(delimiter) + 1));
        input = input.erase(0, input.find(delimiter) + delimiter.length());
        dataPair.column = stoi(input.substr(input.find(delimiter), input.find(delimiter) + 1));
        input = input.erase(input.find(delimiter) - 1, input.find(delimiter) - 1 + delimiter.length());
        dataPair.cell.value = stoi(input.substr(input.find(delimiter, input.find(delimiter) + 1)));
        dataPair.cell.properties = immutable;
    } catch(std::out_of_range &e) {
        return dataPair;
    }
    return dataPair;
}

/* Check out of range values every attribute of a Coordinate
   Due to a 9x9 field every value needs to be less or eqaul to 9 and greater or equal to 0 
   True if all values are valid */ 
bool Input_Handling::checkInput(DataPair dataPair) {
    if (dataPair.row > matchfield.getSize() ||dataPair.column > matchfield.getSize() | dataPair.cell.value > matchfield.getSize()) {
        return false;
    }
    return true;
}