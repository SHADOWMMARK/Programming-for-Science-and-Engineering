#include <iostream>
#include <fstream>
#include "Constant.h"
#include "ColorClass.h"

using namespace std;
// class ColorClass function definitions
ColorClass::ColorClass() {
    redAmt = COLOR_MAX; 
    greenAmt = COLOR_MAX; 
    blueAmt = COLOR_MAX;
}
ColorClass::ColorClass(int inRed, int inGreen, int inBlue) {
    // Red assign
    if (inRed > COLOR_MAX) {
        redAmt = COLOR_MAX;
    }
    else if (inRed < COLOR_MIN) {
        redAmt = COLOR_MIN;
    }
    else {
        redAmt = inRed;
    }
    // Green assign
    if (inGreen > COLOR_MAX) {
        greenAmt = COLOR_MAX;
    }
    else if (inGreen < COLOR_MIN) {
        greenAmt = COLOR_MIN;
    }
    else {
        greenAmt = inGreen;
    }
    // Blue assign
    if (inBlue > COLOR_MAX) {
        blueAmt = COLOR_MAX;
    }
    else if (inBlue < COLOR_MIN) {
        blueAmt = COLOR_MIN;
    }
    else {
        blueAmt = inBlue;
    }
}
void ColorClass::setToBlack() {
    redAmt = COLOR_MIN; 
    greenAmt = COLOR_MIN; 
    blueAmt = COLOR_MIN;
}
void ColorClass::setToWhite() {
    redAmt = COLOR_MAX; 
    greenAmt = COLOR_MAX; 
    blueAmt = COLOR_MAX;
}
void ColorClass::setToBlue() {
    redAmt = COLOR_MIN; 
    greenAmt = COLOR_MIN; 
    blueAmt = COLOR_MAX;
}
void ColorClass::setToGreen() {
    redAmt = COLOR_MIN; 
    greenAmt = COLOR_MAX; 
    blueAmt = COLOR_MIN;
}
void ColorClass::setToRed() {
    redAmt = COLOR_MAX; 
    greenAmt = COLOR_MIN; 
    blueAmt = COLOR_MIN;
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
    redAmt = setToSingle(inRed);
    greenAmt = setToSingle(inGreen);
    blueAmt = setToSingle(inBlue);
    // check clipping or not
    if (checkInRange(inRed) && checkInRange(inGreen) \
        && checkInRange(inBlue)) {
        return false;
    }
    return true;
}
bool ColorClass::adjustBrightness(double adjFactor) {
    bool temp_judge;
    temp_judge = setTo(int(adjFactor * redAmt), \
        int(adjFactor * greenAmt), \
        int(adjFactor * blueAmt));
    return temp_judge;
}
void ColorClass::setTo(ColorClass inColor) {
    // set color's component values to the same as those in "inColor"
    redAmt = inColor.redAmt;
    greenAmt = inColor.greenAmt;
    blueAmt = inColor.blueAmt;
}
bool ColorClass::addColor(ColorClass &rhs) {
    bool temp_judge;
    temp_judge = setTo(int(redAmt + rhs.redAmt), \
        int(greenAmt + rhs.greenAmt), \
        int(blueAmt + rhs.blueAmt));
    return temp_judge;
}


bool ColorClass::readPixelFromFile(ifstream &inFile, int colorBound) {
    inFile >> redAmt >> greenAmt >> blueAmt;
    if (inFile.fail()) {
        return false;
    }
    // check wrong input
    if (!checkSingle(redAmt, colorBound)) {
        return false;
    }
    if (!checkSingle(greenAmt, colorBound)) {
        return false;
    }
    if (!checkSingle(blueAmt, colorBound)) {
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
    if (redAmt != colorCompare.redAmt) {
        return false;
    }
    else if (greenAmt != colorCompare.greenAmt) {
        return false;
    }
    else if (blueAmt != colorCompare.blueAmt) {
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
    return redAmt;
}
int ColorClass::getGvalue() {
    return greenAmt;
}
int ColorClass::getBvalue() {
    return blueAmt;
}

bool ColorClass::checkSingle(int val, int bound) {
    if ((val < COLOR_MIN) || (val > bound)) {
        return false;
    }
    return true;
}