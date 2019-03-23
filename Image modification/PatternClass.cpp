#include <iostream>
#include <fstream>
#include <string>
#include "Constant.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"
#include "ColorImageClass.h"

using namespace std;
// class Pattern Class function definitions
PatternClass::PatternClass() {
    initializeSuccess = true;
    imagept = 0;
}

PatternClass::~PatternClass() {
    delete[] imagept;
    imagept = 0; //or = nullptr
    // imagept = nullptr;
}

int PatternClass::getWidth() {
    return width_;
}

int PatternClass::getHeight() {
    return height_;
}

ColorClass* PatternClass::getpointer() {
    return imagept;
}

void PatternClass::setPatternColor(int colorChoice) {
    if (colorChoice == COLOR_RED) {
        patternColor.setToRed();
    }
    else if (colorChoice == COLOR_GREEN) {
        patternColor.setToGreen();
    }
    else if (colorChoice == COLOR_BLUE) {
        patternColor.setToBlue();
    }
    else if (colorChoice == COLOR_BLACK) {
        patternColor.setToBlack();
    }
    else if (colorChoice == COLOR_WHITE) {
        patternColor.setToWhite();
    }
}

bool PatternClass::isCorrectlyInitialized(string file_name) {
    // check the load status
    ifstream inFile_;
    inFile_.open(file_name.c_str());
    if (inFile_.fail()) {
        initializeSuccess = false;
        //RESUBMISSION CODE UPDATE
        cout << "File does not exist!" << endl;
        return false;
    }
    inFile_ >> width_;
    if ((inFile_.fail()) || (width_ <= 0)) {
        initializeSuccess = false;
        cout << "The width is not positive integer!" << endl;
        return false;
    }
    else {
        // correct width 
        inFile_ >> height_;
        if ((inFile_.fail()) || (height_ <= 0)) {
            initializeSuccess = false;
            //RESUBMISSION CODE UPDATE
            cout << "The height is not positive integer!" << endl;
            return false;
        }
    }
    // start to read image
    imagept = new ColorClass[width_ * height_];

    int oneDIndex; int temp_status;
    string temp; int elements = 0;

    // read pattern elements
    while (!inFile_.eof()) {
        for (int i = 0; i < height_; i++) {
            for (int j = 0; j < width_; j++) {
                oneDIndex = i * width_ + j;
                inFile_ >> temp_status;
                if (inFile_.fail()) {
                    initializeSuccess = false;
                    cout << "Input should be positive integer! " << endl;
                    cout << "Or total number of 0 and 1 ";
                    cout << "is smaller than pattern size! ";
                    cout << endl;
                    return false;
                }
                else if ((temp_status != 0) && (temp_status != 1)) {
                    initializeSuccess = false;
                    cout << "Input should be 0 or 1!";
                    cout << endl;
                }
                // correct input
                else {
                    // set pattern color to pixel
                    imagept[oneDIndex].setTo(patternColor);
                    imagept[oneDIndex].setIndicatorIndex(temp_status);
                    elements += 1;
                }
            }
        }
        inFile_ >> temp;
        // more other information provided
        if (temp != "") {
            inFile_.close();
            elements += 1;
            initializeSuccess = false;
            //RESUBMISSION CODE UPDATE
            cout << "Total number of 0 and 1 is larger than pattern size! ";
            cout << endl;
            return false;
        }
    }
    /*
    inFile_.close();
    if (elements != width_ * height_) {
        initializeSuccess = false;
        //RESUBMISSION CODE UPDATE
        cout << "Total number of 0 and 1 don't match pattern size! ";
        cout << endl;
        return false;
    }
    */
    return true;
}

ColorClass PatternClass::getPatternColor() {
    return patternColor;
}