// Declare your FOUR functions here (no more, no less):
// That is, the 3 functions for the selectionSort:
// swap_values, find_index_of_swap, sort
// plus the function getArray
void swap(int& num1, int& num2); 
int find_index_of_swap(bool choice, int myarray[], int arr_size, int begin_index);
void sort(bool choice, int myarray[], int arr_size, int begin_index);
void getArray(ifstream& in, string fname, int arr[], int size);

// Constants for the data file that your program is reading in
// Only change these if you want to test your program with a different array file
// than the one provided for you (ArrayFile.txt).
//
const int MAXSIZE = 20;     // amount of integers in the file (you need this to declare your array size)
const std::string FILENAME = "ArrayFile.txt";    // The file name with the integers

