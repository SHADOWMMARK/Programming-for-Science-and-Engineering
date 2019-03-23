#include <iostream>
#include "mainMenuOption.h"
using namespace std;

// print main menu and return input choice
// return should be 1-5
int mainMenuOption() {
    int choice;
    bool validInputFound = false;
    cout << "1. Annotate image with rectangle" << endl;
    cout << "2. Annotate image with pattern from file" << endl;
    cout << "3. Insert another image" << endl;
    cout << "4. Write out current image" << endl;
    cout << "5. Exit the program" << endl;
    cout << "Enter int for main menu choice : ";
    while (!validInputFound) {
        cin >> choice;
        if (cin.fail() || (choice > 5) || (choice < 1)) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "Please print valid choice number from 1-5!" << endl;
            cout << "Enter int for main menu choice: ";
        }
        else {
            validInputFound = true;
        }
    }
    return choice;
}