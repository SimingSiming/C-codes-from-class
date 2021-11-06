#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int terms = 1;
    double pivalue = 0;

    while (terms != 0){
        pivalue = 0;
        cout << "Enter the number of terms to approximate (or zero to quit):" << endl;
        cin >> terms;
        
        if (terms != 0){
            pivalue += 1; 
            for (double t = 1; t <= terms; t++){
                pivalue += (1 / (2 * t + 1)) * pow(-1, t);
            }
            pivalue *= 4; 
            cout << "The approximation for Leibniz's Formula is " << pivalue << " using " << terms << " terms." << endl;
            }
        } 
    return 0;
}