#include <iostream> // for cout, cin
#include <fstream>  // for ifstream
#include <cstdlib>  // for exit
using namespace std;

int SeqSearch (int arr[], int array_size, int target){
    int index;
    // int is_in = -1;
    for (int i = 0; i < array_size; i++){
        if (arr[i] == target){
            // is_in = 1; 
            index = i;
            break;
        }
    }
    return index;
    // if (is_in == -1){
    //     return -1;
    // }
}

int main(){
    // int array[4] = {1,2,3,4}; 
    // int idx; 
    // idx = SeqSearch(array, 4, 2);
    // cout << idx << endl; 
    // bool is = true;
    for (int i = 2; i < 1; i++){
        cout << "aa";
    }
}