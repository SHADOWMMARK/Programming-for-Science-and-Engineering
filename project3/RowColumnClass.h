#ifndef _ROWCOLUMN_CLASS_H_
#define _ROWCOLUMN_CLASS_H_

//class RowColClass declarations
class RowColumnClass {
private:
    int rowIdx;
    int colIdx;
public:
    RowColumnClass(); // default constructor
    RowColumnClass(int inRow, int inCol); // initial values
    void setRowCol(int inRow, int inCol); // set to input values
    void setRow(int inRow); // set Row to input values 
    void setCol(int inCol); // set Col to input values
    int getRow(); // return Row
    int getCol(); // return Col
};
#endif
