#ifndef MATCHFIELD_H
#define MATCHFIELD_H
/* Class to represent and print a soduku field */
    class Matchfield{
    private:
        int size;
        int field[9][9];
        void printTopLine();
        void printLine(int index);
    public:
        Matchfield(int size);
        void printField();
        void setField(int x, int y, int value);
        int getField(int x, int y);
    };
#endif