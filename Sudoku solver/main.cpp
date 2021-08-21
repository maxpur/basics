#include "Input_Handling.h"
#include "Matchfield.h"
#include "Logic.h"
#include "Datastructures.h"
#include <iostream>

int main() {
    Matchfield matchfield(9);
    Logic logic(matchfield);
    Input_Handling inputHandling(matchfield, logic);
    inputHandling.startSolver();
    return 0;
}