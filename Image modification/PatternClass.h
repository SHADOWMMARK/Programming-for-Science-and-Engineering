#ifndef _PATTERN_CLASS_H_
#define _PATTERN_CLASS_H_
#include <string>
using namespace std;

//class PatternClass declarations: used to represent the pattern
//RESUBMISSION CODE UPDATE
class PatternClass {
private:
    int width;
    int height;
    bool isValid;
    ColorClass* imagept;
    ColorClass patternColor;
public:
    PatternClass(); // default constructor
    // check the status
    bool isValidPat(string file_name);

    // set color as chosen color
    void setPatternColor(int colorChoice); 

    // get methods to visit attributes
    int getWidth(); // get width value
    int getHeight(); // get height value
    ColorClass* getpointer(); // get pointer
    ~PatternClass(); // destructor
    ColorClass getPatternColor();
};
#endif
