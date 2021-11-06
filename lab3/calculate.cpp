#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 4){
        cerr << "Number of arguments is incorrect." << endl;
        exit(1); 
    }
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);

    if (num2 == 0 && argv[2] == string("%")) {
        cerr << "Cannot divide by zero." << endl;
        exit(1);
    }

    if (argv[2] == string("x")){
        cout << num1 * num2 << endl; 
    }
    else if (argv[2] == string("%")){
        cout << num1 % num2 << endl;
    }
    else if (argv[2] == string("+")){
        cout << num1 + num2 << endl;
    }
    else{
        cerr << "Bad operation choice." << endl;
    }
    return 0;
}