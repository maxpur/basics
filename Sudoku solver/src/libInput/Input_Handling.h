#ifndef INPUT_HANDLING_H
#define INPUT_HANDLING_H
#include "../libMatchfield/Datastructures.h"
#include "../libMatchfield/Matchfield.h"
#include "../libLogic/Logic.h"
#include <string>
    /* Class to manage user inputs and to map commands to correspondig function calls */
    class Input_Handling {
    private:
        Matchfield &matchfield;
        Logic &logic;
        void printInstructions();
        int resolveOption(std::string &);
        DataPair parseInput(std::string &);
        bool checkInput(DataPair dataPair);
        void printHelpInstruction();

    public:
        Input_Handling(Matchfield &matchfield, Logic &logic);
        void startSolver();

    };
#endif