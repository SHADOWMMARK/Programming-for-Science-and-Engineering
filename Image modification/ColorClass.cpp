#include <iostream>
#include <fstream>
#include "Constant.h"
#include "ColorClass.h"

using namespace std;
// class ColorClass function definitions
ColorClass::ColorClass() {
    amountofRed = COLOR_MAX; 
    amountofGreen = COLOR_MAX; 
    amountofBlue = COLOR_MAX;
}
ColorClass::ColorClass(int inRed, int inGreen, int inBlue) {
    // Red assign
    if (inRed > COLOR_MAX) {
        amountofRed = COLOR_MAX;
    }
    else if (inRed < COLOR_MIN) {
        amountofRed = COLOR_MIN;
    }
    else {
        amountofRed = inRed;
    }
    // Green assign
    if (inGreen > COLOR_MAX) {
        amountofGreen = COLOR_MAX;
    }
    else if (inGreen < COLOR_MIN) {
        amountofGreen = COLOR_MIN;
    }
    else {
        amountofGreen = inGreen;
    }
    // Blue assign
    if (inBlue > COLOR_MAX) {
        amountofBlue = COLOR_MAX;
    }
    else if (inBlue < COLOR_MIN) {
        amountofBlue = COLOR_MIN;
    }
    else {
        amountofBlue = inBlue;
    }
}
void ColorClass::setToBlack() {
    amountofRed = COLOR_MIN; 
    amountofGreen = COLOR_MIN; 
    amountofBlue = COLOR_MIN;
}
void ColorClass::setToWhite() {
    amountofRed = COLOR_MAX; 
    amountofGreen = COLOR_MAX; 
    amountofBlue = COLOR_MAX;
}
void ColorClass::setToBlue() {
    amountofRed = COLOR_MIN; 
    amountofGreen = COLOR_MIN; 
    amountofBlue = COLOR_MAX;
}
void ColorClass::setToGreen() {
    amountofRed = COLOR_MIN; 
    amountofGreen = COLOR_MAX; 
    amountofBlue = COLOR_MIN;
}
void ColorClass::setToRed() {
    amountofRed = COLOR_MAX; 
    amountofGreen = COLOR_MIN; 
    amountofBlue = COLOR_MIN;
}
int ColorClass::setToSingle(int val) {
    int result;
    if (checkInRange(val)) {
        result = val;
    }
    else if (val > COLOR_MAX) {
        result = COLOR_MAX;
    }
    else {
        result = COLOR_MIN;
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
        int(adjFactor * amountofGreen), \
        int(adjFactor * amountofBlue));
    return temp_judge;
}
void ColorClass::setTo(ColorClass inColor) {
    // set color's component values to the same as those in "inColor"
    amountofRed = inColor.amountofRed;
    amountofGreen = inColor.amountofGreen;
    amountofBlue = inColor.amountofBlue;
}
bool ColorClass::addColor(ColorClass &rhs) {
    bool temp_judge;
    temp_judge = setTo(int(amountofRed + rhs.amountofRed), \
        int(amountofGreen + rhs.amountofGreen), \
        int(amountofBlue + rhs.amountofBlue));
    return temp_judge;
}

//RESUBMISSION CODE UPDATE
bool ColorClass::readPixelFromFile(ifstream &inFile, int colorBound) {
    inFile >> amountofRed >> amountofGreen >> amountofBlue;
    if (inFile.fail()) {
        return false;
    }
    // check wrong input
    if (!checkSingle(amountofRed, colorBound)) {
        return false;
    }
    if (!checkSingle(amountofGreen, colorBound)) {
        return false;
    }
    if (!checkSingle(amountofBlue, colorBound)) {
        return false;
    }
    return true;
}

int ColorClass::getIndicatorIndex() {
    return patternIndicatorIndex;
}
void ColorClass::setIndicatorIndex(int index) {
    patternIndicatorIndex = index;
}
bool ColorClass::isSameColor(ColorClass colorCompare) {
    if (amountofRed != colorCompare.amountofRed) {
        return false;
    }
    else if (amountofGreen != colorCompare.amountofGreen) {
        return false;
    }
    else if (amountofBlue != colorCompare.amountofBlue) {
        return false;
    }
    return true;
}

bool ColorClass::checkInRange(int val) {
    if ((val >= COLOR_MIN) && (val <= COLOR_MAX)) {
        return true;
    }
    return false;
}

int ColorClass::getRvalue() {
    return amountofRed;
}
int ColorClass::getGvalue() {
    return amountofGreen;
}
int ColorClass::getBvalue() {
    return amountofBlue;
}

bool ColorClass::checkSingle(int val, int bound) {
    if ((val < COLOR_MIN) || (val > bound)) {
        return false;
    }
    return true;
}