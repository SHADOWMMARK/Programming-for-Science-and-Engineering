﻿#include <iostream>
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
    isValid = true;
    imagept = 0;
}

PatternClass::~PatternClass() {
    delete[] imagept;
    imagept = 0; //or = nullptr
    // imagept = nullptr;
}

int PatternClass::getWidth() {
    return width;
}

int PatternClass::getHeight() {
    return height;
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

bool PatternClass::isValidPat(string file_name) {
    // check the load status
    ifstream inFile;
    inFile.open(file_name.c_str());
    if (inFile.fail()) {
        isValid = false;
        cout << "File does not exist!" << endl;
        return false;
    }
    // if no error begin to check the next parameter
    inFile >> width;
    if ((inFile.fail()) || (width <= 0)) {
        isValid = false;
        cout << "The width is not positive integer!" << endl;
        return false;
    }
    else {
        // if no error begin to check the next parameter
        inFile >> height;
        if ((inFile.fail()) || (height <= 0)) {
            isValid = false;
            cout << "The height is not positive integer!" << endl;
            return false;
        }
    }
    // if no error begin to check all the pixels
    // start to read
    imagept = new ColorClass[width * height];

    int oneDIndex; int temp_status;
    string temp; int elements = 0;

    // read pattern elements
    while (!inFile.eof()) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                oneDIndex = i * width + j;
                inFile >> temp_status;
                if (inFile.fail()) {
                    isValid = false;
                    cout << "Input should be positive integer! " << endl;
                    cout << "Or total number of 0 and 1 ";
                    cout << "is smaller than pattern size! ";
                    cout << endl;
                    return false;
                }
                else if ((temp_status != 0) && (temp_status != 1)) {
                    isValid = false;
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
        inFile >> temp;
        // check the pattern size not out of the bound
        if (temp != "") {
            inFile.close();
            elements += 1;
            isValid = false;
            cout << "Total number of 0 and 1 is larger than pattern size! ";
            cout << endl;
            return false;
        }
    }
    return true;
}
// get method to reach pat color
ColorClass PatternClass::getPatternColor() {
    return patternColor;
}