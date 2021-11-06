// Place your member function and program function definitions here:
//  1. The 2 Constructors
//  2. Member function getAString
//  3. Member function cleanUp
//  4. Member function countLetters 
//  5. Program function compareCounts
// See lab description for details
//

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "headers.h"

AString::AString(){
    StringValue = "";
} 

AString::AString(string value){
    StringValue = value;
}

void AString::getAString(){
    cout << "Enter string value: ";
    getline(cin, StringValue);
}

void AString::cleanUp(){
    string clean = "";
    for (char i:StringValue){
        if (isalpha(i)){
            clean += i;
        }
    }
    
    string lower_clean = "";
    for (char j : clean){
        lower_clean += tolower(j);
    }

    StringValue = lower_clean;
}

void AString::countLetters(int array[26]){
    char alpha_arr[26];
    int index = 0;
    for (char i = 'a'; i <= 'z'; i+=1){
        alpha_arr[index] =  i;
        index += 1;  
    }
    
    for (char a : StringValue){
        for (int b = 0; b < 26; b++){
            if (a == alpha_arr[b]){
                array[b] += 1;
            }
        }
    }
}

bool compareCounts(int array1[], int array2[]){
    for (int i = 0; i < 26; i++){
        if (array1[i] != array2[i]){
            return true;
        }
    }
    return false;
}

