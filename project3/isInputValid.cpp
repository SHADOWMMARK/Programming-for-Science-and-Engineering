﻿#include <iostream>
#include "isInputValid.h"
using namespace std;

// check whether the choice is valid
// return false if not (bool type)
bool isInputValid(int inputValue, int lower, int upper) {
    if (inputValue < lower) {
        return false;
    }
    if (inputValue > upper) {
        return false;
    }
    return true;
}