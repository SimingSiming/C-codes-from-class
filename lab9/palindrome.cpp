
// PLACE THE NECESSARY include, etc... STATEMENTS HERE
//
#include <iostream>
#include <string>
using namespace std; 

// DECLARE THE FUNCTIONS HERE:
// 
void cleanUp(string& str);
bool isPalindrome(string str);

int main() {
    string p;
    cout << "Enter sentence:\n";
    getline(cin, p);
    
    cleanUp(p);

    bool answer = isPalindrome(p);
   
    if (answer) {
        cout << "It is a palindrome.\n";
    } else {
        cout << "It is not a palindrome.\n";
    }

    return 0;
}

// DEFINE THE FUNCTIONS HERE:
//
void cleanUp(string& str){
    string lower = "", clean = "";

    for (char i:str){
        if(isalpha(i)){
            clean += i;
        }
    }

    for (char j:clean){
        lower += tolower(j);
    }
    str = lower;
}


bool isPalindrome(string str){
    int str_len = str.length();

    if (str_len == 0 || str_len == 1){
        return true;
    }
    else {
        return (isPalindrome(str.substr(1, str_len - 2))) && (str[0] == str[str_len-1]);
    }
}

