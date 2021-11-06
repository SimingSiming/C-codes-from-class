#include <iostream>
#include <string>
using namespace std;

string func1(int a, string str1, string str2);

string func1(int a, string str1, string str2){
    if (a == 1){
        return str1;
    }
    else {
        return str2;
    }
}

void lala(int a){
    if (1 < a && a < 5){
         cout << "lala";
    }
    else{
        cout << func1(a, string("lala"), string("lalas"));
    }
}

int main(){
    string b = "3";
    lala(3);
    lala(6);
    return 0; 
}