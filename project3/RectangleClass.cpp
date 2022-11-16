#include <iostream>
#include <string>
#include "Constant.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"

using namespace std;
// ctor that takes four parameters
RectangleClass::RectangleClass(int start_row, int start_col, \
    int end_row, int end_col) {
    startPosition.setRowCol(start_row, start_col);
    endPosition.setRowCol(end_row, end_col);
}

// set the Rec according to different color choice
void RectangleClass::setRectangleColor(int colorChoice) {
    if (colorChoice == COLOR_RED) {
        color_rec.setToRed();
    } else if (colorChoice == COLOR_GREEN) {
        color_rec.setToGreen();
    } else if (colorChoice == COLOR_BLUE) {
        color_rec.setToBlue();
    } else if (colorChoice == COLOR_BLACK) {
        color_rec.setToBlack();
    } else if (colorChoice == COLOR_WHITE) {
        color_rec.setToWhite();
    }
}

// get methods to reach rectangle class attributes
RowColumnClass RectangleClass::getStartPosition() {
    return startPosition;
}
RowColumnClass RectangleClass::getEndPosition() {
    return endPosition;
}
ColorClass RectangleClass::getColor() {
    return color_rec;
}
