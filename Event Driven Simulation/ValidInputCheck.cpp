#include "pch.h"
#include <iostream>
using namespace std;
#include "ValidInputCheck.h"

void ValidInputCheck(double &parameter, int lowerBound) {
    bool validInputSeed = false;
    while (!validInputSeed){
        cin >> parameter;
        if (cin.fail() || (lowerBound > parameter)) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "Try again - enter a valid value: ";
        }
        else {
            validInputSeed = true;
        }
    }
}