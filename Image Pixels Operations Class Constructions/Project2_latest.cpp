#include <pch.h>
#include <iostream>
using namespace std;
// Programmer: Mengyao Huang
// Date: 2018/10/08
// Purpose: develop simple classes to represent and utilize colors and images

const int COLORMAX = 1000; // default max num for color
const int COLORMIN = 0; // default min num for color
const int DEFAULT_LOC = -99999; // default location for row and col
const int ARRAY_ROW = 10; // default array row bound
const int ARRAY_COL = 18; // default arrary col bond

//class ColorClass declarations:contains information describing a color
class ColorClass {
    private:
        int amountofRed;
        int amountofGreen;
        int amountofBlue;
        // check whether setTo values are valid in range
        bool checkInRange(int val);
        // call this function to set the value to each color
        int setToSingle(int val);

    public:
        ColorClass(); // default constructor
        // allow initial values to be initialized
        ColorClass(int inRed, int inGreen, int inBlue);
        void printComponentValues(); // print the component color values
        void setToBlack(); // set to indicated color black
        void setToRed(); // set to indicated color read
        void setToGreen(); // set to indicated color green
        void setToBlue(); // set to indicated color blue
        void setToWhite(); // set to indicated color white
        // set the color object's RGB values to the provided values
        bool setTo(int inRed, int inGreen, int inBlue);
        // perform a simplified brightness adjustment by adjustment factor
        bool adjustBrightness(double adjFactor);
        // set the color to the same as those in input parameters
        bool setTo(ColorClass &inColor);
        bool addColor(ColorClass &rhs); // add the color from input parameter
        // subract the color from input parameter
        bool subtractColor(ColorClass &rhs);
};

//class RowColClass declarations: 
//used to identify a specific pixel within an image
class RowColumnClass {
    private:
        int rowIndex;
        int columnIndex;
    public:
        RowColumnClass(); // default constructor
        // set the row and column values to the corresponding input valus
        RowColumnClass(int inRow, int inCol);
        // set attributes Row and Col to provided values
        void setRowCol(int inRow, int inCol);
        void setRow(int inRow); // set Row to provided values 
        void setCol(int inCol); // set Col to provided values
        int getRow(); // return Row values
        int getCol(); // return Col values
        // add provided values to corresponding Row & Col values
        void addRowColTo(RowColumnClass &inRowCol);
        // print the attributes in specific format
        void printRowCol();
};

//class ColorImageClass declarations: used to represent a small image
class ColorImageClass {
    private:
        ColorClass Array[ARRAY_ROW][ARRAY_COL];
        // check whether input values are in range
        bool checkValid(int val, int bound);
    public:
        ColorImageClass(); // default constructor
        // initialize all images pixels to the color provided
        void initializeTo(ColorClass &inColor);
        // add the image provided to the object
        bool addImageTo(ColorImageClass &rhsImg);
        // get the sum of input images and assign
        bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd[]); 
        // set specific pixel to the color in input parameters
        bool setColorAtLocation(RowColumnClass &inRowCol, \
                                ColorClass &inColor);
        // the parameter is assigned to the color of that pixel
        bool getColorAtLocation(RowColumnClass &inRowCol, \
                                ColorClass &outColor);
        void printImage(); // print the contents to the screen
};

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else 
int main() {
    ColorClass testColor;
    RowColumnClass testRowCol;
    RowColumnClass testRowColOther(111, 222);
    ColorImageClass testImage;
    ColorImageClass testImages[3];

    //Test some basic ColorClass operations...
    cout << "Initial: ";
    testColor.printComponentValues();
    cout << endl;
    testColor.setToBlack();cout << "Black: ";
    testColor.printComponentValues();
    cout << endl;
    testColor.setToGreen();
    cout << "Green: ";
    testColor.printComponentValues();cout << endl;
    testColor.adjustBrightness(0.5);
    cout << "Dimmer Green: ";
    testColor.printComponentValues();
    cout << endl;
    //Test some basic RowColumnClass operations...
    cout << "Want defaults: ";
    testRowCol.printRowCol();
    cout << endl;
    testRowCol.setRowCol(2, 8);
    cout << "Want 2,8: ";
    testRowCol.printRowCol();
    cout << endl;
    cout << "Want 111, 222: ";
    testRowColOther.printRowCol();
    cout << endl;
    testRowColOther.setRowCol(4, 2);
    testRowCol.addRowColTo(testRowColOther);
    cout << "Want 6,10: ";
    testRowCol.printRowCol();
    cout << endl;
    //Test some basic ColorImageClass operations...
    testColor.setToRed();
    testImage.initializeTo(testColor);
    testRowCol.setRowCol(555, 5);
    cout << "Want: Color at [555,5]: Invalid Index!" << endl;
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor)) {
        testColor.printComponentValues();
    }
    else {
        cout << "Invalid Index!";
    }
    cout << endl;
    testRowCol.setRow(4);
    cout << "Want: Color at [4,5]: R: 1000 G: 0 B: 0" << endl;
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor)) {
        testColor.printComponentValues();
    }
    else {
        cout << "Invalid Index!";
    }
    cout << endl;
    //Set up an array of images of different colors
    testColor.setToRed();
    testColor.adjustBrightness(0.25);
    testImages[0].initializeTo(testColor);
    testColor.setToBlue();
    testColor.adjustBrightness(0.75);
    testImages[1].initializeTo(testColor);
    testColor.setToGreen();
    testImages[2].initializeTo(testColor);
    //Modify a few individual pixel colors
    testRowCol.setRowCol(4, 2);
    testColor.setToWhite();
    testImages[1].setColorAtLocation(testRowCol, testColor);
    testRowCol.setRowCol(2, 4);
    testColor.setToBlack();
    testImages[2].setColorAtLocation(testRowCol, testColor);
    //Add up all images in testImages array and assign result
    //to the testImage image
    testImage.addImages(3, testImages);
    //Check some certain values
    cout << "Added values:" << endl;
    for (int colInd = 0; colInd < 8; colInd += 2) {
        testRowCol.setRowCol(4, colInd);
        cout << "Color at ";
        testRowCol.printRowCol();
        cout << ": ";
        if (testImage.getColorAtLocation(testRowCol, testColor)) {
            testColor.printComponentValues();
        }
        else {
            cout << "Invalid Index!";
        }
        cout << endl;
    }
    for (int rowInd = 0; rowInd < 8; rowInd += 2) {
        testRowCol.setRowCol(rowInd, 4);
        cout << "Color at ";
        testRowCol.printRowCol();
        cout << ": ";
        if (testImage.getColorAtLocation(testRowCol, testColor)) {
            testColor.printComponentValues();
        }
        else {
            cout << "Invalid Index!";
        }
        cout << endl;
    }
    cout << "Printing entire test image:" << endl;
    testImage.printImage();
    return 0;
}
#endif

// class ColorClass function definitions
ColorClass::ColorClass() {
    amountofRed = COLORMAX; amountofGreen = COLORMAX; amountofBlue = COLORMAX;
}
ColorClass::ColorClass(int inRed, int inGreen, int inBlue) {
    // Red assign
    if (inRed > COLORMAX) {
        amountofRed = COLORMAX;
    }
    else if (inRed < COLORMIN) {
        amountofRed = COLORMIN;
    }
    else {
        amountofRed = inRed;
    }
    // Green assign
    if (inGreen > COLORMAX) {
        amountofGreen = COLORMAX;
    }
    else if (inGreen < COLORMIN) {
        amountofGreen = COLORMIN;
    }
    else {
        amountofGreen = inGreen;
    }
    // Blue assign
    if (inBlue > COLORMAX) {
        amountofBlue = COLORMAX;
    }
    else if (inBlue < COLORMIN) {
        amountofBlue = COLORMIN;
    }
    else {
        amountofBlue = inBlue;
    }
}
void ColorClass::setToBlack() {
    amountofRed = COLORMIN; amountofGreen = COLORMIN; amountofBlue = COLORMIN;
}
void ColorClass::setToWhite() {
    amountofRed = COLORMAX; amountofGreen = COLORMAX; amountofBlue = COLORMAX;
}
void ColorClass::setToBlue() {
    amountofRed = COLORMIN; amountofGreen = COLORMIN; amountofBlue = COLORMAX;
}
void ColorClass::setToGreen() {
    amountofRed = COLORMIN; amountofGreen = COLORMAX; amountofBlue = COLORMIN;
}
void ColorClass::setToRed() {
    amountofRed = COLORMAX; amountofGreen = COLORMIN; amountofBlue = COLORMIN;
}
bool ColorClass::checkInRange(int val) {
    if ((val > COLORMAX) || (val < COLORMIN)) {
        return false;
    }
    return true;
}
int ColorClass::setToSingle(int val) {
    int result;
    if (checkInRange(val)) {
        result = val;
    }
    else if (val > COLORMAX) {
        result = COLORMAX;
    }
    else {
        result = COLORMIN;
    }
    return result;
}
bool ColorClass::setTo(int inRed, int inGreen, int inBlue) {
    // set value
    amountofRed = setToSingle(inRed);
    amountofGreen = setToSingle(inGreen);
    amountofBlue = setToSingle(inBlue);
    // check clipping or not
    if (checkInRange(inRed) && checkInRange(inGreen) \
        && checkInRange(inBlue)) {
        return false;
    }
    return true;
}
bool ColorClass::adjustBrightness(double adjFactor) {
    bool temp_judge;
    temp_judge = setTo(int(adjFactor * amountofRed), \
                       int(adjFactor * amountofGreen),\
                       int(adjFactor * amountofBlue));
    return temp_judge;
}
bool ColorClass::setTo(ColorClass &inColor) {
    // set color's component values to the same as those in "inColor"
    amountofRed = inColor.amountofRed;
    amountofGreen = inColor.amountofGreen;
    amountofBlue = inColor.amountofBlue;
    return 0;
}
bool ColorClass::addColor(ColorClass &rhs) {
    bool temp_judge;
    temp_judge = setTo(int(amountofRed + rhs.amountofRed), \
                       int(amountofGreen + rhs.amountofGreen), \
                       int(amountofBlue + rhs.amountofBlue));
    return temp_judge;
}
bool ColorClass::subtractColor(ColorClass &rhs) {
    bool temp_judge;
    temp_judge = setTo(int(amountofRed - rhs.amountofRed), \
                       int(amountofGreen - rhs.amountofGreen),\
                       int(amountofBlue - rhs.amountofBlue));
    return temp_judge;
}
void ColorClass::printComponentValues() {
    cout << "R: " << amountofRed << " G: " << \
        amountofGreen << " B: " << amountofBlue;
}

// class RowColumnClass function definitions
RowColumnClass::RowColumnClass() {
    rowIndex = DEFAULT_LOC;
    columnIndex = DEFAULT_LOC;
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
void RowColumnClass::addRowColTo(RowColumnClass &inRowCol) {
    rowIndex = rowIndex + inRowCol.rowIndex;
    columnIndex = columnIndex + inRowCol.columnIndex;
}
void RowColumnClass::printRowCol() {
    cout << "[" << rowIndex << "," << columnIndex << "]";
}

// class ColorImageClass function definitions
ColorImageClass::ColorImageClass() {
    int i; int j;
    // set all pixels in the image to full black
    for (i = 0; i < ARRAY_ROW; i++) {
        for (j = 0; j < ARRAY_COL; j++)
        {
            Array[i][j].setToBlack();
        }
    }
}
// set all pixels to the color provided
void ColorImageClass::initializeTo(ColorClass &inColor) {
    int i; int j;
    for (i = 0; i < ARRAY_ROW; i++) {
        for (j = 0; j < ARRAY_COL; j++)
        {
            Array[i][j].setTo(inColor);
        }
    }
}
// each pixel in the image will be added by pixel in corresponding location
// return true if clip needs
bool ColorImageClass::addImageTo(ColorImageClass &rhsImg) {
    int i; int j;
    int check = 0; // set temp initial value to check
    for (i = 0; i < ARRAY_ROW; i++) {
        for (j = 0; j < ARRAY_COL; j++)
        {
            check = check + Array[i][j].addColor(rhsImg.Array[i][j]);
        }
    }
    // check clipping status
    // some addColor function will return 1 if clipping needs -- check added
    if (check > 0) {
        return true;
    }
    return false;
}
// each pixel in image will be set to sum of pixels in corresponding location
// return true if clip needs
bool ColorImageClass::addImages(int numImgsToAdd, \
                                ColorImageClass imagesToAdd[]) {
    // type of array imagesToAdd is ColorImageClass
    int i;
    int check1 = 0; // set temp initial value to check
    // use initializerBlack to initialize 
    ColorClass initializerBlack;
    initializerBlack.setToBlack();
    initializeTo(initializerBlack);

    for (i = 0; i < numImgsToAdd; i++) {
        check1 = check1 + addImageTo(imagesToAdd[i]);
    }
    if (check1 > 0) {
        return true;
    }
    return false;
}
bool ColorImageClass::checkValid(int val, int bound) {
    // check the range of index
    if ((val < 0) || (val > (bound - 1))) {
        return false;
    }
    return true;
}
// set the pixel at location to the color specified via the inColor parameter
// return true if the location is valid here
bool ColorImageClass::setColorAtLocation(RowColumnClass &inRowCol, \
                                         ColorClass &inColor) {
    // check valid or not first before assigning
    if (checkValid(inRowCol.getRow(), ARRAY_ROW) && \
        checkValid(inRowCol.getCol(), ARRAY_COL)) {
        Array[inRowCol.getRow()][inRowCol.getCol()].setTo(inColor);
        return true;
    }
    else {
        return false;
    }
}
// set the "outColor" parameter to the color of image pixel at that location
// return true if the location is valid here
bool ColorImageClass::getColorAtLocation(RowColumnClass &inRowCol,\
                                         ColorClass &outColor) {
    if (checkValid(inRowCol.getRow(), ARRAY_ROW) && \
        checkValid(inRowCol.getCol(), ARRAY_COL)) {
        outColor.setTo(Array[inRowCol.getRow()][inRowCol.getCol()]);
        return true;
    }
    else {
        return false;
    }
}
void ColorImageClass::printImage() {
    int i; int j;
    for (i = 0; i < ARRAY_ROW; i++) {
        for (j = 0; j < ARRAY_COL; j++) {
            Array[i][j].printComponentValues();
            if (j < (ARRAY_COL - 1)) {
                cout << "--";
            }
        }
        cout << endl;
    }
}