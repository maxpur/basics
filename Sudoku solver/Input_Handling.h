#ifndef INPUT_HANDLING_H
#define INPUT_HANDLING_H
#include "Datastructures.h"
#include "Logic.h"
#include "Matchfield.h"
#include <string>
    /* Class to manage user inputs and to map commands to correspondig function calls */
    class Input_Handling {
    private:
        Matchfield &matchfield;
        Logic &logic;
        void printInstructions();
        int resolveOption(std::string &);
        Coordinate parseInput(std::string &);
        bool checkInput(Coordinate coordinate);
    public:
        Input_Handling(Matchfield &matchfield, Logic &logic);
        void startSolver();

    };
#endif