#ifndef _RECTANGLE_CLASS_H_
#define _RECTANGLE_CLASS_H_
#include <string>
using namespace std;

//class Rectangle declarations:contains the rectangle needed
class RectangleClass {
private:
    RowColumnClass startPosition;
    RowColumnClass endPosition;
    ColorClass color_rec;
public:
    //ctor
    RectangleClass(int start_row, int start_col, int end_row, int end_col);
    // choose color to set the recColor
    void setRectangleColor(int colorChoice);
    // get methods
    RowColumnClass getStartPosition();
    RowColumnClass getEndPosition();
    ColorClass getColor();
};
#endif
