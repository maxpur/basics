#ifndef MATCHFIELD_H
#define MATCHFIELD_H
    #include "Datastructures.h"
/* Class to represent and print a soduku field */
    class Matchfield{
    private:
        int size;
        Coordinate field[9][9];
        void printTopLine();
        void printLine(int index);
        void printInterline();
    public:
        Matchfield(int size);
        void printField();
        void setCell(Coordinate);
        int getCell(int x, int y);
        int getSize();
        void reset();
    };
#endif