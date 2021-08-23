#include "../libInput/Input_Handling.h"
#include "../libMatchfield/Matchfield.h"
#include "../libLogic/Logic.h"
#include "../libMatchfield/Datastructures.h"
#include <iostream>

int main() {
    Matchfield matchfield(9);
    Logic logic(matchfield);
    Input_Handling inputHandling(matchfield, logic);
    inputHandling.startSolver();
    return 0;
}