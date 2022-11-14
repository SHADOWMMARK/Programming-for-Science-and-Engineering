#ifndef _COLORCLASS_H_
#define _COLORCLASSS_H_
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
    ColorClass(); // default constructor
    ColorClass(int inRed, int inGreen, int inBlue); // initialize values
    void setToBlack(); // set to indicated color black
    void setToRed(); // set to indicated color read
    void setToGreen(); // set to indicated color green
    void setToBlue(); // set to indicated color blue
    void setToWhite(); // set to indicated color white
    void setTo(ColorClass inColor); // set to the same color
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
