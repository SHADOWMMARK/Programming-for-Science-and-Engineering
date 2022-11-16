#ifndef _COLOR_CLASS_H_
#define _COLOR_CLASSS_H_
#include <string>
using namespace std;

//class ColorClass declarations:contains information describing a color
class ColorClass {
private:
    int redAmt;
    int greenAmt;
    int blueAmt;
    
    int patternIndicatorIndex;
public:
    // ctors, second is ctor using the input RGB
    ColorClass(); 
    ColorClass(int inRed, int inGreen, int inBlue); 

    // 6 different set methods
    void setToRed();
    void setToGreen();
    void setToBlue(); 
    void setToBlack(); 
    void setToWhite();
    void setTo(ColorClass inColor);

    // set pixel's index to be 0/1 in pattern
    void setIndicatorIndex(int index);
    
    // read RGB values from File
    bool readPixelFromFile(ifstream &inFile, int colorBound);
    bool checkInRange(int val); // check whether the value is valid
    int getIndicatorIndex(); // get pixel's 0/1 index
    bool setTo(int inRed, int inGreen, int inBlue); // set to provided values 
    bool adjustBrightness(double adjFactor); // perform brightness adjustment
    bool addColor(ColorClass &rhs); // add the color from input parameter
    bool isSameColor(ColorClass colorCompare); // compare color to another
    bool checkSingle(int val, int bound); // check RGB valid or not
    int setToSingle(int val); // set the value to each color
    
    int getRvalue(); 
    int getGvalue(); 
    int getBvalue(); 
};
#endif
