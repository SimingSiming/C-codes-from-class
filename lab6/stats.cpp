#include <iostream> 
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;

// three required functions
double cal_mean(double sort_array[], int asize);
double cal_std(double sort_array[], int asize);
double cal_median(double sort_array[], int asize);

// my funcs
void  get_array(ifstream& inStream, double my_array[], int& asize);
void sort_array(double my_array[], int asize); 
void aggre_func(string filename);




// function definitions

double cal_mean(double sort_array[], int asize){
    double sum = 0; 
    for (int i = 0; i < asize; i++){
        sum += sort_array[i];
    }
    return sum/asize;
}

double cal_std(double sort_array[], int asize){
    double numerator; 
    for (int i = 0; i < asize; i++){
        numerator += pow(sort_array[i] - cal_mean(sort_array, asize),2); 
    }
    return sqrt(numerator/(asize - 1));
}

double cal_median(double sort_array[], int asize){
    int mid; 
    if (asize % 2){
        mid = (asize/2); 
        return sort_array[mid];
    }
    else{
        mid = (asize/2); 
        return (sort_array[mid] + sort_array[mid - 1])/2.0;
    }
}

void get_array(ifstream& inStream, double my_array[], int& asize){
    int count = 0;

    while (inStream >> my_array[count]){ 
        count++;
    }
    
    asize = count;
}

void sort_array(double my_array[], int asize){
    for (int i = asize - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (my_array[j+1] >= my_array[j]){
                double temp = my_array[j+1]; 
                my_array[j+1] = my_array[j];
                my_array[j] = temp;
            }
        }
    }
}

void aggre_func(string filename){
    ifstream inStream1, inStream2;
    inStream1.open(filename);
    inStream2.open(filename);
    int asize = 1000; 
    double in_array[asize];
    get_array(inStream1, in_array, asize);
    double clean_array[asize];
    get_array(inStream2, clean_array, asize);
    sort_array(clean_array, asize); 

    cout << "Mean = " << cal_mean(clean_array, asize) << endl; 
    cout << "Median = " << cal_median(clean_array, asize) << endl; 
    cout << "Stddev = " << cal_std(clean_array, asize) << endl;

    inStream1.close();
    inStream2.close();
}

int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    string filename; 
    cout << "Enter filename: ";
    getline(cin, filename);
    aggre_func(filename);
    return 0; 
}