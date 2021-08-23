#ifndef MATCHFIELD_H
#define MATCHFIELD_H
    #include "Datastructures.h"
/* Class to represent and print a soduku field */
    class Matchfield{
    private:
        int size;
        Cell field[9][9];
        void printTopLine();
        void printLine(int index);
        void printInterline();
    public:
        Matchfield(int size);
        void printField();
        void setCell(int row, int column, int value, CellProperties cellproperties);
        Cell& getCell(int x, int y);
        int getSize();
        void reset();
    };
#endif