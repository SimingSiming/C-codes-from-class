#include <iostream>
using namespace std; 

int main(){
    int row, col;

    while (row != 0 || col != 0) {
        cout << "Enter number of rows and columns:" << endl; 
        cin >> row >> col;
        for (int r = 0; r < row; r++){
            for (int c = 0; c < col; c++){
                cout << "X.";
            }
            cout << endl; 
        }
    }
    return 0; 
}