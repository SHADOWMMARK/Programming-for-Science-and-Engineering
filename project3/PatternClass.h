#ifndef _PATTERN_CLASS_H_
#define _PATTERN_CLASS_H_
#include <string>
using namespace std;

//this class to represent pattern
class PatternClass {
private:
    int width;
    int height;
    bool isValid;
    ColorClass* imagept;
    ColorClass patternColor;
public:
    PatternClass();
    // check if valid
    bool isValidPat(string file_name);

    // set color as chosen
    void setPatternColor(int colorChoice); 

    // get methods to visit attributes
    int getWidth();
    int getHeight();
    ColorClass* getpointer(); // get pointer
    ColorClass getPatternColor();
    
    ~PatternClass(); // dtor
    
};
#endif
