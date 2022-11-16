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
    // ctor
    ColorImageClass();
    // dtor
    ~ColorImageClass();

    // check the status
    bool isValidPpm(string file_name);

     // check the index
    bool isIndexInRange(int RowIndex, int ColIndex);

     // set transparency color in image
    void setTransparency(int colorChoice);

    // add rectangle to image
    void addRectangle(RectangleClass &rec, bool filled);

    // add pattern to image
    void addPattern(PatternClass &pat, int pRowStart, int pColStart);
    
    // add image
    void addImage(ColorImageClass &anoImage, int iRowStart, int iColStart);

    // get methods
    int getWidth();
    int getHeight();
    int getPixel();
    string getType();
    ColorClass* getpointer();
};
#endif
