#ifndef _ROWCOLUMN_CLASS_H_
#define _ROWCOLUMN_CLASS_H_

//class RowColClass declarations
class RowColumnClass {
private:
    int rowIndex;
    int columnIndex;
public:
    RowColumnClass(); // default constructor
    RowColumnClass(int inRow, int inCol); // initial values
    void setRowCol(int inRow, int inCol); // set to provided values
    void setRow(int inRow); // set Row to provided values 
    void setCol(int inCol); // set Col to provided values
    int getRow(); // return Row values
    int getCol(); // return Col values
};
#endif
