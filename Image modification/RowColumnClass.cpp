#include <iostream>
#include "Constant.h"
#include "RowColumnClass.h"

using namespace std;
// class RowColumnClass function definitions
RowColumnClass::RowColumnClass() {
    // default value
    rowIndex = 0;
    columnIndex = 0;
}
RowColumnClass::RowColumnClass(int inRow, int inCol) {
    rowIndex = inRow;
    columnIndex = inCol;
}
void RowColumnClass::setRowCol(int inRow, int inCol) {
    rowIndex = inRow;
    columnIndex = inCol;
}
void RowColumnClass::setRow(int inRow) {
    rowIndex = inRow;
}
void RowColumnClass::setCol(int inCol) {
    columnIndex = inCol;
}
int RowColumnClass::getRow() {
    return rowIndex;
}
int RowColumnClass::getCol() {
    return columnIndex;
}
