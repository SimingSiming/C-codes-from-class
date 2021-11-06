// YOUR NAME HERE
// Siming, Su.

#include <iostream>
#include <string>
#include "functions.cpp"
using namespace std;

int main()
{
    // Other than completing the missing function calls,
    // per the comments below, 
    // DO NOT CHANGE ANY OF THE OTHER INSTRUCTIONS HERE!
    //
    // EVEN IF YOU PASS THE AUTOGRADER, YOU WILL GET A ZERO GRADE
    // IF YOU CHANGE ANY OF THE LINES BELOW!!!
    
    AString sentence1, sentence2("nothing");
    int ca1[26] = {0}, ca2[26]={0};

    // Call the member functions on each of 
    // these class objects that will:
    //   (a) get the string values
    //   (b) clean up the string values
    //   (c) create the array of letter counts
    // See lab description for details.
    sentence1.getAString();
    sentence2.getAString();  
    sentence1.cleanUp(); 
    sentence2.cleanUp();

    sentence1.countLetters(ca1);
    sentence2.countLetters(ca2);

    bool badCount = compareCounts(ca1, ca2);
    if (badCount) {
        cout << "The strings are not anagrams.\n";
    } else {
        cout << "The strings are anagrams.\n";
    }

    return 0;
}
