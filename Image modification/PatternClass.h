#ifndef _PATTERN_CLASS_H_
#define _PATTERN_CLASS_H_
#include <string>
using namespace std;

//class PatternClass declarations: used to represent the pattern
//RESUBMISSION CODE UPDATE
class PatternClass {
private:
    int width_;
    int height_;
    bool initializeSuccess;
    ColorClass* imagept;
    ColorClass patternColor;
public:
    PatternClass(); // default constructor
    // check the status
    bool isCorrectlyInitialized(string file_name);
    void setPatternColor(int colorChoice); // set color in image
    int getWidth(); // get width value
    int getHeight(); // get height value
    ColorClass* getpointer(); // get pointer
    ~PatternClass(); // destructor
    ColorClass getPatternColor();
};
#endif
