#include <iostream>
#include <fstream>
using namespace std;

// Define your FOUR functions here (no more, no less):
// First, the 3 functions for the selectionSort:
// swap_values, find_index_of_swap, sort
void swap(int& num1, int& num2){
    int temp; 
    temp = num1;
    num1 = num2;
    num2 = temp;
}

int find_index_of_swap(bool choice, int myarray[], int arr_size, int begin_index){
    int swap_idx = begin_index;
    int min_max = myarray[begin_index]; 

    if (choice == 0){
        for (int i = begin_index + 1; i < arr_size; i++){
            if (myarray[i] < min_max){
                min_max = myarray[i]; 
                swap_idx = i;
            }
    }
    }

    else{
        for (int i = begin_index + 1; i < arr_size; i++){
            if (myarray[i] > min_max){
                min_max = myarray[i];
                swap_idx = i;
            }
        }
    }

    return swap_idx;
}

void sort(bool choice, int myarray[], int arr_size, int begin_index){
    if (begin_index == arr_size){
        return; 
    }
    else{
        int my_idx = find_index_of_swap(choice, myarray, arr_size, begin_index);
        swap(myarray[my_idx], myarray[begin_index]); 
        sort(choice, myarray, arr_size, begin_index+1);
    }
}

// Next, define the function getArray here. 
// This is the same one we used in Lab 4, so you can copy it over as is.
void getArray(ifstream& in, string fname, int arr[], int size)
{
    in.open(fname);
    if ( in.fail() ) 
    { 
        cerr << "Input file opening failed.\n"; 
        exit(1); 
    }
    for (int i = 0; i < size; i++)
    {
        in >> arr[i];
    }
}