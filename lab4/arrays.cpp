/*
/ Skeleton file for arrays.cpp for CS16, 2021, UCSB
/ Copyright © 2021 by Zachary Sisco. All rights reserved.
/
*/

// DO NOT MODIFY THESE NEXT 6 LINES - DO NOT ADD TO THEM
#include <iostream> // for cout, cin
#include <fstream>  // for ifstream
#include <cstdlib>  // for exit
using namespace std;
#include "headers.h"    // contains the function declarations
#include "constants.h"  // contains 4 global variables

void print_array (int arr[], int asize){
    for (int i = 0; i < asize; i++){
        if (i == asize - 1){
            cout << arr[i] << endl;
            return;
        }
        cout << arr[i] << ", ";
    }
}

int maxArray (int arr[], int asize){
    int max(arr[0]);
    for (int i = 1; i < asize; i++){
        if (arr[i] >= max){
            max = arr[i];
        }
    }
    return max;
}

int minArray (int arr[], int asize){
    int min(arr[0]);
    for (int i = 1; i < asize; i++){
        if (arr[i] <= min){
            min = arr[i];
        }
    }
    return min;   
}

int sumArray (int arr[], int asize){
    int sum(0);
    for (int i = 0; i < asize; i++){
        sum += arr[i];
    }
    return sum;
}

void evensArray (int arr[], int asize){
    cout << "Evens: ";
    for (int i = 0; i < asize; i++){
        if (arr[i] % 2 == 0){
            cout << arr[i] << ", ";
        }
    }
    cout << "end" << endl;
}

void primesArray (int arr[], int asize){ 
    cout << "Primes: ";
    for (int i = 0; i < asize; i++){
        bool is_prime = false;
        for (int j = 2; j < arr[i]; j++){
            if (arr[i] % j == 0){
                is_prime = false;
                break;
            }
            else {
                is_prime = true; 
            }
            }
            
        if (arr[i] == 2){
            is_prime = true;
        }
        
        if (arr[i] <= 0){
            is_prime = false;
        }

        if (is_prime == true){
            cout << arr[i] << ", ";
        }
        }
    cout << "end" << endl; 

}

int SeqSearch (int arr[], int array_size, int target){
    int is_in = -1;
    int idx = 0;

    for (int i = 0; i < array_size; i++){
        if (arr[i] == target){
            is_in = 1; 
            idx = i;
            break;
        }
    }
    if (is_in == -1){
        return -1;
    }
    else{
        return idx;
    }
}


void AllSearches (int arr[], int array_size){
    cout << "Searches:" << endl;
    for (int i = 0; i < NSEARCHES; i++){
        cout << "Looking for " << SEARCHES[i] << ". ";
        if (SeqSearch(arr, array_size, SEARCHES[i]) == -1){
            cout << "Not Found!" << endl;
        }
        else{
            cout << "Found at index: "  
            << SeqSearch(arr, array_size, SEARCHES[i]) << endl; 
        }
    }
}

int main( )
{
    // DO NOT MODIFY THESE NEXT 3 LINES - DO NOT ADD TO THEM
    ifstream ifs;
    int size = MAXSIZE, array[MAXSIZE];
    getArray(ifs, FILENAME, array, size);

    int max(0), min(0), sum(0); 
    print_array(array, size);
    max = maxArray(array, size);
    min = minArray(array, size);
    sum = sumArray(array, size); 
    cout << "Max = " << max << endl;
    cout << "Min = " << min << endl; 
    cout << "Sum = " << sum << endl;
    evensArray(array, size); 
    primesArray(array, size); 
    AllSearches(array, size);

    // hints for the tasks: 
    // all that needs to be in here is simple calls the functions, like these: 
    // in addition to, some print to std.out statements.
    // 
    // Your main() will ideally look clean and uncluttered and be made up
    // mostly of function calls.
    // 
    // Example:
    // ...
    // printArray(array, size);
    // max = maxArray(array, size);
    // min = minArray(array, size);
    // ...
    // ...etc...
    

    // PUT MISSING CODE HERE

    return 0;
}

// PUT MISSING FUNCTION DEFINITIONS HERE

