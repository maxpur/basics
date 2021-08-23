#ifndef LOGIC_H
#define LOGIC_H
    #include "../libMatchfield/Matchfield.h"
    #include "../libMatchfield/Datastructures.h"
    //Class to maage soduko field logic like check for solvability 
    class Logic {
    private:
        Matchfield &matchfield;
        bool checkRow(int row);
        bool checkColumn(int column);
        bool checkDiagonal();
        bool checkBlock(int row, int column);
        void getNextCoordinates(int &currentRow, int &currentColumn, bool direction);
        int getNextValue(int current);
    public:
        Logic(Matchfield &matchfield);
        bool checkSolvability();
        bool solve();
    };
#endif