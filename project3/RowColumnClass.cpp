#include <iostream>
#include "Constant.h"
#include "RowColumnClass.h"

using namespace std;
// class RowColumnClass functions
// ctors
RowColumnClass::RowColumnClass() {
    // default value
    rowIdx = 0;
    colIdx = 0;
}
RowColumnClass::RowColumnClass(int inRow, int inCol) {
    rowIdx = inRow;
    colIdx = inCol;
}

// set methods
void RowColumnClass::setRowCol(int inRow, int inCol) {
    rowIdx = inRow;
    colIdx = inCol;
}
void RowColumnClass::setRow(int inRow) {
    rowIdx = inRow;
}
void RowColumnClass::setCol(int inCol) {
    colIdx = inCol;
}

// get methods
int RowColumnClass::getRow() {
    return rowIdx;
}
int RowColumnClass::getCol() {
    return colIdx;
}
