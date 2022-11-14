#ifndef _COLOR_IMAGE_CLASS_H_
#define _COLOR_IMAGE_CLASS_H_
#include <string>

using namespace std;

//class ColorImageClass declarations: used to represent a small image
class ColorImageClass {
private:
    string image_type;
    int width_;
    int height_;
    int pixel_;
    bool isValid;
    ColorClass* imagept;
    ColorClass transparency;
public:
    ColorImageClass(); // default constructor
    // check the status
    bool isValidPpm(string file_name);
    bool isIndexInRange(int RowIndex, int ColIndex); // check index
    void setTransparency(int colorChoice); // set transparency color in image
    // add rectangle to image
    void addRectangle(RectangleClass &rec, bool filled);
    // add pattern to image
    void addPattern(PatternClass &pat, int pRowStart, int pColStart);
    // add image
    void addImage(ColorImageClass &anoImage, int iRowStart, int iColStart);
    int getWidth(); // get width value
    int getHeight(); // get height value
    int getPixel(); // get pixel value
    string getType(); // get type value
    ColorClass* getpointer(); // get pointer
    ~ColorImageClass(); // destructor
};
#endif
