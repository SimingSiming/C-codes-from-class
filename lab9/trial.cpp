#include <iostream>
#include <string>
using namespace std; 

int main() {
    string p;
    cout << "Enter sentence:\n";
    getline(cin, p);

    int str_length = p.length();

    for (int i = 0; i < str_length; i++){
        p[i] = tolower(p[i]);
        }
    cout << p << endl;
    }
    //         p.erase(i, 1);
    //     } 
    // }
    // cout << p << endl;


