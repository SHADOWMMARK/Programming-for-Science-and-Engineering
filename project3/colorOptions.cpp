#include <iostream>
#include <string>
#include "colorOptions.h"

using namespace std;
// print Rec/trans/pattern color options and return colorChoice
// return should be 1-5
void colorOptions(string type) {
    bool validInputFound_color = false;
    cout << "1. Red" << endl;
    cout << "2. Green" << endl;
    cout << "3. Blue" << endl;
    cout << "4. Black" << endl;
    cout << "5. White" << endl;
    if (type == "rectangle") {
        cout << "Enter int for rectangle color: ";
    }
    if (type == "transparecy") {
        cout << "Enter int for transparecy color: ";
    }
    if (type == "pattern") {
        cout << "Enter int for pattern color: ";
    }
}