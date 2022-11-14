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
    // constructor
    RectangleClass(int start_row, int start_col, int end_row, int end_col);
    void setRectangleColor(int colorChoice); // choose color
    RowColumnClass getStartPosition(); // get startPosition class
    RowColumnClass getEndPosition(); // get endPosition class
    ColorClass getColor(); // get color
};
#endif
