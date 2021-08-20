#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H
enum Cell {
    immutable,
    changeable
};

enum InputOptions {
    exitField,
    solve,
    check,
    newField,
    insert
};

struct Coordinate {
    int row = -1;
    int column = -1;
    int value = 0;
    int properties = changeable;
};
#endif