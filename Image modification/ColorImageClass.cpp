#include <iostream>
#include <string>
#include <fstream>
#include "Constant.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"
#include "ColorImageClass.h"

using namespace std;
// class ColorImageClass function definitions
ColorImageClass::ColorImageClass() {
    isValid = true;
    imagept = 0;
}
ColorImageClass::~ColorImageClass() {
    delete[] imagept;
    imagept = 0; //or = nullptr
    // imagept = nullptr;
}

/*
    check the input ppm file valid or not
    the ppm file should:
    magic Number == P3;
    width height positive;
    pixel between 0 and 255
*/
bool ColorImageClass::isValidPpm(string file_name) {
    // check the load status
    ifstream inFile_;
    inFile_.open(file_name.c_str());
    
    if (inFile_.fail()) {
        isValid = false;
        cout << "File does not exist!" << endl;
        return false;
    }
    // correct open
    inFile_ >> image_type;
    if ((inFile_.fail()) || (image_type != "P3")) {
        isValid = false;
        cout << "The type of PPM file is not P3!" << endl;
        return false;
    }

    inFile_ >> width_;
    
    if ((inFile_.fail()) || (width_ <= 0)) {
        isValid = false;
        cout << "The width is not positive integer!" << endl;
        return false;
    }
    else {
        // correct width 
        inFile_ >> height_;
        if ((inFile_.fail()) || (height_ <= 0)) {
            isValid = false;
            cout << "The height is not positive integer!" << endl;
            return false;
        }
    }

    inFile_ >> pixel_;
    if ((inFile_.fail()) || (pixel_ < COLOR_MIN) || (pixel_ > COLOR_MAX)) {
        isValid = false;
        
        cout << "Max number of RGB values is not in valid range! " << endl;
        return false;
    }
    // correct pixel
    else {
        imagept = new ColorClass[width_ * height_];
        // if header is correct then continue
        int oneDIndex;
        string temp; int elements = 0;
        while (!inFile_.eof()) {
            for (int i = 0; i < height_; i++) {
                for (int j = 0; j < width_; j++) {
                    oneDIndex = i * width_ + j;
                    // read elements
                    
                    if (imagept[oneDIndex].readPixelFromFile(inFile_, \
                        pixel_)) {
                        // correct input
                        elements += 3;
                    }
                    else {
                        isValid = false;
                        inFile_.close();
                        
                        cout << "RGB values are not valid input! ";
                        cout << endl;
                        cout << "Or Total number of RGB values doesn't ";
                        cout << "match image size! ";
                        cout << endl;
                        return false;
                    }
                }
            }
            inFile_ >> temp;
            // more other information provided
            if (temp != "") {
                inFile_.close();
                elements += 1;
                isValid = false;
                cout << "Total number of RGB values doesn't match image size!";
                cout << endl;
                return false;
            }
        }
        return true;
    }
}

void ColorImageClass::setTransparency(int colorChoice) {
    if (colorChoice == COLOR_RED) {
        transparency.setToRed();
    }
    else if (colorChoice == COLOR_GREEN) {
        transparency.setToGreen();
    }
    else if (colorChoice == COLOR_BLUE) {
        transparency.setToBlue();
    }
    else if (colorChoice == COLOR_BLACK) {
        transparency.setToBlack();
    }
    else if (colorChoice == COLOR_WHITE) {
        transparency.setToWhite();
    }
}


void ColorImageClass::addRectangle(RectangleClass &rec, bool filled) {
    // add Rectangle to image
    int oneDIndex_image;
    int start_row_; int end_row_;
    int start_col_; int end_col_;
    start_row_ = rec.getStartPosition().getRow();
    end_row_ = rec.getEndPosition().getRow();
    start_col_ = rec.getStartPosition().getCol();
    end_col_ = rec.getEndPosition().getCol();
    // consider bound limitations
    if (filled == true) {
        for (int i = (start_row_ - 1); i < end_row_; i++) {
            for (int j = (start_col_ - 1); j < end_col_; j++) {
                oneDIndex_image = i * width_ + j;
                // set rectangle color to pixel
                
                if (isIndexInRange(i,j)) {
                    imagept[oneDIndex_image].setTo(rec.getColor());
                }
            }
        }
    }
    if (filled == false) {
        // not filled rectangle
        // set color to upper and lower row
        for (int j = (start_col_ - 1); j < end_col_; j++) {
            oneDIndex_image = (start_row_ - 1) * width_ + j;
            
            if (isIndexInRange(start_row_-1, j)) {
                imagept[oneDIndex_image].setTo(rec.getColor());
            }

            oneDIndex_image = (end_row_ - 1) * width_ + j;
            if (isIndexInRange(end_row_-1, j)) {
                imagept[oneDIndex_image].setTo(rec.getColor());
            }
        }
        // set color to left and right col
        for (int i = (start_row_ - 1); i < end_row_; i++) {
            oneDIndex_image = i * width_ + (start_col_ - 1);
            
            if (isIndexInRange(i, start_col_-1)) {
                imagept[oneDIndex_image].setTo(rec.getColor());
            }

            oneDIndex_image = i * width_ + (end_col_ - 1);
            if (isIndexInRange(i, end_col_ - 1)) {
                imagept[oneDIndex_image].setTo(rec.getColor());
            }
        }
    }
}


void ColorImageClass::addPattern(PatternClass &pat, \
    int pRowStart, int pColStart) {
    // this color image pat's pixels have notation
    int oneDIndex_pat;
    int oneDIndex_image;
    for (int i = 0; i < pat.getHeight(); i++) {
        for (int j = 0; j < pat.getWidth(); j++) {
            // check pixels'notation before setting
            oneDIndex_pat = i * pat.getWidth() + j;
            if ((pat.getpointer() + oneDIndex_pat)->getIndicatorIndex() == 1) {
                // replace color when notation is 1
                // set rectangle color to pixel
                oneDIndex_image = (pRowStart + i - 1) \
                    * width_ + (pColStart + j - 1);
                
                if (isIndexInRange(pRowStart + i-1, pColStart+j-1)) {
                    imagept[oneDIndex_image].setTo(pat.getPatternColor());
                }
            }
        }
    }
}


void ColorImageClass::addImage(ColorImageClass &anoImage,\
    int iRowStart, int iColStart) {
    // this color image has transparency color
    int oneDIndex_anoImage;
    int oneDIndex_image;
    for (int i = 0; i < anoImage.height_; i++) {
        for (int j = 0; j < anoImage.width_; j++) {
            // check pixels'comparison result before setting
            oneDIndex_anoImage = i * anoImage.width_ + j;
            if (!(anoImage.getpointer() \
                + oneDIndex_anoImage)->isSameColor(anoImage.transparency)) {
                // replace color if they are different from transparency
                oneDIndex_image = (iRowStart + i - 1) * width_ \
                    + (iColStart + j - 1);
                // check whether the index is valid
                
                if (isIndexInRange(iRowStart+i-1, iColStart+j-1)) {
                    imagept[oneDIndex_image].setTo(*(anoImage.getpointer() \
                        + oneDIndex_anoImage));
                }
            }
        }
    }
}


bool ColorImageClass::isIndexInRange(int RowIndex, int ColIndex) {
    if ((RowIndex >= 0) && (RowIndex < height_)) {
        if ((ColIndex >= 0) && (ColIndex < width_)) {
            return true;
        }
    }
    return false;
}


ColorClass* ColorImageClass::getpointer() {
    return imagept;
}
int ColorImageClass::getWidth() {
    return width_;
}
int ColorImageClass::getHeight() {
    return height_;
}
int ColorImageClass::getPixel() {
    return pixel_;
}
string ColorImageClass::getType() {
    return image_type;
}
