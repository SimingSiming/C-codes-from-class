// utility.cpp
#include <iostream> 
#include <cmath>
#include "utility.h"
using namespace std;

// IN THIS FILE, define any of your OWN functions you may need to 
// solve the problems.    
bool approxEqual(double a, double b, double tolerance){
    if (abs(a - b) < tolerance){
        return true;
    }
    else {
        return false;
    }
}

// You will need to include the function prototype in "utility.h" and
// then be sure to  #include "utility.h" in the file where you use
// these functions

