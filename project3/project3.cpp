﻿#include <iostream>
#include <fstream>
#include <string> 
#include "Constant.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"
#include "ColorImageClass.h"
#include "isInputValid.h"
#include "colorOptions.h"

using namespace std;
/*
    Programmer: Ziyan Wang
    Date: 2022/11/14

    Built an interactive program 
    to modify images in PPM format 
    using dynamic allocation
*/

int main()
{
    string fname;
    ColorImageClass curImg;
    int mainOperation = -1;
    // get the name of the file then store in fname
    cout << "Enter string for PPM image file name to load: ";
    cin >> fname;

    // if input img is not valid then exit the program
    if (!curImg.isValidPpm(fname)) {
        // if input img is invalid
        cout << "Error reading image!" << endl;
        cout << "Program ends!" << endl;
        return 0; 
    }
    // if valid then print menu to start
    while (mainOperation != EXIT_OPTION) {
        // print the main menu and check if it is valid input of the main menu
        bool isValidInput = false;
        cout << "1. Annotate image with rectangle" << endl;
        cout << "2. Annotate image with pattern from file" << endl;
        cout << "3. Insert another image" << endl;
        cout << "4. Write out current image" << endl;
        cout << "5. Exit the program" << endl;
        cout << "Enter int for main menu choice : ";
        while (!isValidInput) {
            cin >> mainOperation;
            if (cin.fail() || (mainOperation > EXIT_OPTION)\
                || (mainOperation < MIN_OPTION)) {
                cin.clear();
                cin.ignore(200, '\n');
                cout << "Please print valid choice number from 1-5!" << endl;
                cout << "Enter int for main menu choice: ";
            } else {
                isValidInput = true;
            }
        }
        // according to differnt mainOperation enter different funcs
        // may print submenus
        if (mainOperation == MIN_OPTION) {
            // rectangle annotate
            int methodChoice;
            int minRow; int minCol;
            int maxRow; int maxCol;
            bool validSetup = false;
            cout << "1. Specify upper left and ";
            cout << "lower right corners of rectangle" << endl;
            cout << "2. Specify upper left corner and ";
            cout << "dimensions of rectangle" << endl;
            cout << "3. Specify extent from center of rectangle";
            cout << endl;
            cout << "Enter int for rectangle specification method: ";
            cin >> methodChoice;
            if (cin.fail() || !isInputValid(methodChoice, \
                MIN_OPTION, CHOICE_MAX_METHOD)) {
                cout << "Please print valid method number from 1-3!";
                cout << endl;
            } else {
                // if method valid
                // start upper left corner position define
                // CHOSEN 1ST given the two points locations
                // or CHOSEN 2ND give the one point and WH
                if (methodChoice != CHOICE_MAX_METHOD) {

                    cout << "Enter upper left corner row and column: ";
                    cin >> minRow;
                    if (cin.fail()) {
                        cout << "Please input valid integers for ";
                        cout << "upper left row position!" << endl;
                    } else {//if valid start row
                        cin >> minCol;
                        if (cin.fail()) 
                        {
                            cout << "Please input valid integers for ";
                            cout << "upper left column position!" << endl;
                        } else {//if valid start column
                            // if give two positions
                            if (methodChoice == REC_TWO_POINTS) {
                                cout << "Enter lower right ";
                                cout << "corner row and column: ";
                            } else {
                                cout << "Enter int for number of rows: ";
                            }
                            cin >> maxRow;
                            if (cin.fail()) {
                                cout << "Please input valid integers ";
                                cout << "for rectangle row value!" << endl;
                            } else {//if valid end row
                                if (methodChoice == REC_POINT_AND_WH) {
                                    cout << "Enter ";
                                    cout << "int for number of columns: ";
                                }
                                cin >> maxCol;
                                if(cin.fail()){
                                    cout << "Please input valid integers ";
                                    cout << "for rectangle column value!";
                                    cout << endl;
                                } else {
                                    //if valid end column
                                    validSetup = true;
                                    // add for method 2
                                    if (methodChoice == REC_POINT_AND_WH) 
                                    {
                                        maxRow += minRow;
                                        maxCol += minCol;
                                        // calculate the bound of
                                        //  the row and col
                                    }
                                }
                            }
                        }
                    }
                } else {// CHOSEN 3RD given the center and extent
                    int centerRow; 
                    int centerCol;
                    int halfRow; 
                    int halfCol;
                    cout << "Enter rectangle center row and column: ";
                    cin >> centerRow;
                    if (cin.fail()) {
                        cout << "Please input valid integers for ";
                        cout << "center row position!" << endl;
                    } else { // to check if the center row valid
                        cin >> centerCol;
                        if (cin.fail()) {
                            cout << "Please input valid integers for ";
                            cout << "center column position!" << endl;
                        } else { // to check if the valid center column 
                            cout << "Enter int for half number of rows: ";
                            cin >> halfRow;
                            if (cin.fail()) {
                                cout << "Please input valid integers ";
                                cout << "for half row extent!" << endl;
                            } else {// to check if the valid half row
                                cout << "Enter int for ";
                                cout << "half number of columns : ";
                                cin >> halfCol;
                                if (cin.fail()) {
                                    cout << "Please input valid integers ";
                                    cout << "for half column extent!";
                                    cout << endl;
                                } else {
                                    // to check if the valid half column
                                    // calculate borders according to 
                                    // received parameters
                                    validSetup = true;
                                    minRow = centerRow - halfRow;
                                    minCol = centerCol - halfCol;
                                    maxRow = centerRow + halfRow;
                                    maxCol = centerCol + halfCol;
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
                if (cin.fail() || !isInputValid(color_rec, MIN_OPTION, \
                    CHOICE_MAX_COLOR)) {
                    cout << "Error in choosing rectangle color!" << endl;
                    cout << "Please choose from 1 to 5!" << endl;
                } else {//if color choice valid
                    RectangleClass Rectangle(minRow, minCol, \
                        maxRow, maxCol);
                    Rectangle.setRectangleColor(color_rec);
                    cout << "1. No" << endl;
                    cout << "2. Yes" << endl;
                    cout << "Enter int for rectangle fill option: ";
                    cin >> fill_;
                    // Use start and end row col parameters to set up
                    if (cin.fail() || !isInputValid(fill_, MIN_OPTION, \
                        CHOICE_MAX_FILLED)) {
                        cout << "Error in choosing Filled status!" << endl;
                        cout << "Please choose from 1 to 2!" << endl;
                    }
                    else {
                        // correct filled status
                        if (fill_ == CHOICE_FIRST_FILLED) {
                            curImg.addRectangle(Rectangle, false);
                        }
                        if (fill_ == CHOICE_MAX_FILLED) {
                            curImg.addRectangle(Rectangle, true);
                        }
                    }
                }
            }
        }

        // check pattern problem
        if (mainOperation == PAT_OPTION) {
            // pattern annotate
            string pname;
            int pcorner_row;
            int pcorner_col;
            int color_pat;
            cout << "Enter string for file name containing pattern: ";
            cin >> pname;
            PatternClass insert_pattern;
            // correct name
            if (insert_pattern.isValidPat(pname)) {
                cout << \
                    "Enter upper left corner of pattern row and column: ";
                cin >> pcorner_row;
                if (cin.fail()) {
                    cout << "Please input valid integers for ";
                    cout << "pattern row position!" << endl;
                } else { //if valid row
                    cin >> pcorner_col;
                    if (cin.fail()) {
                        cout << "Please input valid integers for pattern ";
                        cout << "column position!" << endl;
                    } else { //if valid column
                        colorOptions("pattern");
                        cin >> color_pat;
                        if (cin.fail() || !isInputValid(color_pat, \
                            MIN_OPTION, CHOICE_MAX_COLOR)) {
                            cout << \
                                "Error in choosing pattern color!" << endl;
                            cout << "Please choose from 1 to 5!" << endl;
                        } else {//if valid color
                            insert_pattern.setPatternColor(color_pat);
                            curImg.addPattern(insert_pattern, \
                                pcorner_row, pcorner_col);
                        }
                    }
                }
            } else {
                cout << "Please check this file again!" << endl;
            }
        }
        if (mainOperation == INSERT_OPTION) {
            // first readin another img to be inserted
            string image_name;
            int icorner_row;
            int icorner_col;
            int color_ima;
            cout << "Enter string for file name of PPM image to insert: ";
            cin >> image_name;
            ColorImageClass insert_image;
            if (insert_image.isValidPpm(image_name)) {
                cout << "Enter upper left corner to ";
                cout << "insert image row and column: ";
                cin >> icorner_row;
                if (cin.fail()) {
                    cout << "Please input valid integers for ";
                    cout << "image row position!" << endl;
                } else {//if row valid 
                    cin >> icorner_col;
                    if (cin.fail()) {
                        cout << "Please input valid integers for ";
                        cout << "image column position!" << endl;
                    } else {//if column valid 
                        colorOptions("transparecy");
                        cin >> color_ima;
                        if (cin.fail() || !isInputValid(color_ima, \
                            MIN_OPTION, CHOICE_MAX_COLOR)) {
                            cout << "Error in choosing image ";
                            cout << "transparecy color!" << endl;
                            cout << "Please choose from 1 to 5!" << endl;
                        } else {// if color valid
                            // add another image to image here
                            curImg.addImage(insert_image, \
                                icorner_row, icorner_col);
                        }
                    }
                }
            } else {
                cout << "Please check this file again!" << endl;
            }
        }

        // no need to check input correct here
        if (mainOperation == OUTPUT_OPTION) {
            string outString;
            cout << "Enter string for PPM file name to output: ";
            cin >> outString;
            // write out current PPM file here
            ofstream outFile;
            outFile.open(outString.c_str());
            if (outFile.fail()) {
                cout << "Fail to write the file!" << endl;
            } else {
                // write header with four parameters
                outFile << curImg.getType() << " ";
                outFile << curImg.getWidth() << " ";
                outFile << curImg.getHeight() << " ";
                outFile << curImg.getPixel() << " ";
                // write pixel values with the RGB values 
                // in pointed ColorClass
                for (int i = 0; i < (curImg.getWidth() \
                    * curImg.getHeight()); i++) {
                    outFile << (curImg.getpointer() + i)->getRvalue();
                    outFile << " ";
                    outFile << (curImg.getpointer() + i)->getGvalue();
                    outFile << " ";
                    outFile << (curImg.getpointer() + i)->getBvalue();
                    outFile << " ";
                }
            }
            outFile.close();
        }       
        // release the cin
        cin.clear();
        cin.ignore(200, '\n');
    }
    // if mainOperation == 5 , then exit
    cout << "Thank you for using this program";
    return 0;
}
