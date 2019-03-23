#include <iostream>
#include <fstream>
#include <string> 
#include "Constant.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"
#include "ColorImageClass.h"
#include "mainMenuOption.h"
#include "isCinValid.h"
#include "colorOptions.h"

using namespace std;
// Programmer: Mengyao Huang
// Date: 2018/11/04
// Purpose: develop classes to modify images in PPM format 
// using dynamic allocation

int main()
{
    string fname;
    ColorImageClass BaseImage;
    // get the name of the file stored in fname somehow
    cout << "Enter string for PPM image file name to load: ";
    cin >> fname;
    if (BaseImage.isCorrectlyInitialized(fname)) {
        int operation = 0; //set a default value to start operations
        while (operation != CHOICE_MAX) {
            operation = mainMenuOption(); // make sure the operation is correct
            if (operation == CHOICE_MIN) {
                // rectangle annotate
                int methodChoice;
                int start_row; int start_col;
                int end_row; int end_col;
                bool validSetup = false;
                cout << "1. Specify upper left and ";
                cout << "lower right corners of rectangle" << endl;
                cout << "2. Specify upper left corner and ";
                cout << "dimensions of rectangle" << endl;
                cout << "3. Specify extent from center of rectangle";
                cout << endl;
                cout << "Enter int for rectangle specification method: ";
                cin >> methodChoice;
                if (cin.fail() || !isCinValid(methodChoice, \
                    CHOICE_MIN, CHOICE_MAX_METHOD)) {
                    cout << "Please print valid method number from 1-3!";
                    cout << endl;
                }
                // correct method
                else {
                    // start upper left corner position define
                    if (methodChoice != CHOICE_MAX_METHOD) {
                        // give two positions
                        cout << "Enter upper left corner row and column: ";
                        cin >> start_row;
                        if (cin.fail()) {
                            cout << "Please input valid integers for ";
                            cout << "upper left row position!" << endl;
                        }
                        // valid start row
                        else {
                            cin >> start_col;
                            if (cin.fail()) {
                                cout << "Please input valid integers for ";
                                cout << "upper left column position!" << endl;
                            }
                            // valid start column
                            else {
                                if (methodChoice == CHOICE_FIRST_METHOD) {
                                    cout << "Enter lower right ";
                                    cout << "corner row and column: ";
                                }
                                else {
                                    cout << "Enter int for number of rows: ";
                                }
                                cin >> end_row;
                                if (cin.fail()) {
                                    cout << "Please input valid integers ";
                                    cout << "for rectangle row value!" << endl;
                                }
                                // valid end row
                                else {
                                    if (methodChoice == CHOICE_SECOND_METHOD) {
                                        cout << "Enter ";
                                        cout << "int for number of columns: ";
                                    }
                                    cin >> end_col;
                                    if (cin.fail()) {
                                        cout << "Please input valid integers ";
                                        cout << "for rectangle column value!";
                                        cout << endl;
                                    }
                                    // valid end column
                                    else {
                                        validSetup = true;
                                        // add for method 2
                                        if (methodChoice == \
                                            CHOICE_SECOND_METHOD) {
                                            end_row = end_row + start_row;
                                            end_col = end_col + start_col;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else {
                        // methodChoice 3
                        // give center and extent
                        int center_row; int center_col;
                        int half_row; int half_col;
                        cout << "Enter rectangle center row and column: ";
                        cin >> center_row;
                        if (cin.fail()) {
                            cout << "Please input valid integers for ";
                            cout << "center row position!" << endl;
                        }
                        // valid center row
                        else {
                            cin >> center_col;
                            if (cin.fail()) {
                                cout << "Please input valid integers for ";
                                cout << "center column position!" << endl;
                            }
                            // valid center column
                            else {
                                cout << "Enter int for half number of rows: ";
                                cin >> half_row;
                                if (cin.fail()) {
                                    cout << "Please input valid integers ";
                                    cout << "for half row extent!" << endl;
                                }
                                // valid half row
                                else {
                                    cout << "Enter int for ";
                                    cout << "half number of columns : ";
                                    cin >> half_col;
                                    if (cin.fail()) {
                                        cout << "Please input valid integers ";
                                        cout << "for half column extent!";
                                        cout << endl;
                                    }
                                    // valid half column
                                    else {
                                        validSetup = true;
                                        start_row = center_row - half_row;
                                        start_col = center_col - half_col;
                                        end_row = center_row + half_row;
                                        end_col = center_col + half_col;
                                    }
                                }
                            }
                        }
                    }
                }
                if (validSetup == true) {
                    // set up rectangle here
                    // choose color and fill options
                    int color_rec;
                    int fill_;
                    colorOptions("rectangle");
                    cin >> color_rec;
                    if (cin.fail() || !isCinValid(color_rec, CHOICE_MIN, \
                        CHOICE_MAX_COLOR)) {
                        cout << "Error in choosing rectangle color!" << endl;
                        cout << "Please choose from 1 to 5!" << endl;
                    }
                    // correct color choice
                    else {
                        RectangleClass Rectangle(start_row, start_col, \
                            end_row, end_col);
                        Rectangle.setRectangleColor(color_rec);
                        cout << "1. No" << endl;
                        cout << "2. Yes" << endl;
                        cout << "Enter int for rectangle fill option: ";
                        cin >> fill_;
                        // Use start and end row col parameters to set up
                        if (cin.fail() || !isCinValid(fill_, CHOICE_MIN, \
                            CHOICE_MAX_FILLED)) {
                            cout << "Error in choosing Filled status!" << endl;
                            cout << "Please choose from 1 to 2!" << endl;
                        }
                        else {
                            // correct filled status
                            if (fill_ == CHOICE_FIRST_FILLED) {
                                BaseImage.addRectangle(Rectangle, false);
                            }
                            if (fill_ == CHOICE_MAX_FILLED) {
                                BaseImage.addRectangle(Rectangle, true);
                            }
                        }
                    }
                }
            }

            // check pattern problem
            if (operation == MAIN_SECOND) {
                // pattern annotate
                string pname;
                int pcorner_row;
                int pcorner_col;
                int color_pat;
                cout << "Enter string for file name containing pattern: ";
                cin >> pname;
                PatternClass insert_pattern;
                // correct name
                if (insert_pattern.isCorrectlyInitialized(pname)) {
                    cout << \
                        "Enter upper left corner of pattern row and column: ";
                    cin >> pcorner_row;
                    if (cin.fail()) {
                        cout << "Please input valid integers for ";
                        cout << "pattern row position!" << endl;
                    }
                    // valid row
                    else {
                        cin >> pcorner_col;
                        if (cin.fail()) {
                            cout << "Please input valid integers for pattern ";
                            cout << "column position!" << endl;
                        }
                        // valid column
                        else {
                            colorOptions("pattern");
                            cin >> color_pat;
                            if (cin.fail() || !isCinValid(color_pat, \
                                CHOICE_MIN, CHOICE_MAX_COLOR)) {
                                cout << \
                                    "Error in choosing pattern color!" << endl;
                                cout << "Please choose from 1 to 5!" << endl;
                            }
                            // correct color
                            else {
                                insert_pattern.setPatternColor(color_pat);
                                BaseImage.addPattern(insert_pattern, \
                                    pcorner_row, pcorner_col);
                            }
                        }
                    }
                }
                else {
                    cout << "Please check this file again!" << endl;
                }
            }

            // check insert image problem
            if (operation == MAIN_THIRD) {
                // insert another image
                string image_name;
                int icorner_row;
                int icorner_col;
                int color_ima;
                cout << "Enter string for file name of PPM image to insert: ";
                cin >> image_name;
                ColorImageClass insert_image;
                if (insert_image.isCorrectlyInitialized(image_name)) {
                    cout << "Enter upper left corner to ";
                    cout << "insert image row and column: ";
                    cin >> icorner_row;
                    if (cin.fail()) {
                        cout << "Please input valid integers for ";
                        cout << "image row position!" << endl;
                    }
                    // valid row
                    else {
                        cin >> icorner_col;
                        if (cin.fail()) {
                            cout << "Please input valid integers for ";
                            cout << "image column position!" << endl;
                        }
                        // valid column
                        else {
                            colorOptions("transparecy");
                            cin >> color_ima;
                            if (cin.fail() || !isCinValid(color_ima, \
                                CHOICE_MIN, CHOICE_MAX_COLOR)) {
                                cout << "Error in choosing image ";
                                cout << "transparecy color!" << endl;
                                cout << "Please choose from 1 to 5!" << endl;
                            }
                            // valid color
                            else {
                                // add another image to image here
                                BaseImage.addImage(insert_image, \
                                    icorner_row, icorner_col);
                            }
                        }
                    }
                }
                else {
                    cout << "Please check this file again!" << endl;
                }
            }

            // no need to check input correct here
            if (operation == MAIN_FOURTH) {
                string outString;
                cout << "Enter string for PPM file name to output: ";
                cin >> outString;
                // write out current PPM file here
                ofstream outFile_;
                outFile_.open(outString.c_str());
                if (outFile_.fail()) {
                    cout << "Fail to write the file!" << endl;
                }
                else {
                    // write header
                    outFile_ << BaseImage.getType() << " ";
                    outFile_ << BaseImage.getWidth() << " ";
                    outFile_ << BaseImage.getHeight() << " ";
                    outFile_ << BaseImage.getPixel() << " ";
                    // write pixel values from pointer
                    for (int i = 0; i < (BaseImage.getWidth() \
                        * BaseImage.getHeight()); i++) {
                        outFile_ << (BaseImage.getpointer() + i)->getRvalue();
                        outFile_ << " ";
                        outFile_ << (BaseImage.getpointer() + i)->getGvalue();
                        outFile_ << " ";
                        outFile_ << (BaseImage.getpointer() + i)->getBvalue();
                        outFile_ << " ";
                    }
                }
                outFile_.close();
            }

            cin.clear();
            cin.ignore(200, '\n');
        }
        // operation = 5 then exit
        cout << "Thank you for using this program";
    }
    else {
        cout << "Error reading image!" << endl;
        cout << "Program ends!" << endl;
    }
    return 0;
}
