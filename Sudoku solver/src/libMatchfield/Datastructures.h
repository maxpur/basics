#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H
enum CellProperties {
    immutable,
    changeable
};

struct Cell {
    int value = 0;
    int properties = changeable;
};

struct DataPair {
    Cell cell;
    int row;
    int column;
};
#endif