#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string clean_string(string sentence, int size); 
string bubble_sort(string clean, int size);
void sort_string(string sentence, int size);
void print_freq(string sentence, int size);
string unique_string(string sentence, int size);
int target_search(string sentence, int size, char target); 

string clean_string(string sentence, int size){
    string clean = "";
    for (int i = 0; i < size; i++){
        if (isalpha(sentence[i])){
             clean += sentence[i];
        }
    }
    return clean; 
}

string bubble_sort(string sentence, int size){
    char temp;
    string clean;
    int clean_size;
    clean = clean_string(sentence, size);
    clean_size = clean.length();
    for (int i = clean_size - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (clean[j] >= clean[j+1]){
                temp = clean[j+1];
                clean[j+1] = clean[j];
                clean[j] = temp;
            }
        }
    }
    return clean;
}

void sort_string(string sentence, int size){
    string sort;
    sort = bubble_sort(sentence, size);
    cout << "Sorted and cleaned-up sentence:"
         << sort << endl;
}

string unique_string(string sentence, int size){
    string unique = "";
    for (int i = 0; i < size; i++){
        bool is_unique = true;
        int uni_len = unique.length();
        for (int j = 0; j < uni_len; j++){
            if (sentence[i] == unique[j]){
                is_unique = false;
            }
        }
        if (is_unique == true){
            unique += sentence[i];
        }
    }
    return unique;
}

int target_search(string sentence, int size, char target){
    int count = 0;
    for (char i:sentence){
        if (i == target){
            count += 1;
        }
    }
    return count;
}

void print_freq(string sentence, int size){
     string sort, unique;
     int sort_size;
     sort = bubble_sort(sentence, size);
     sort_size = sort.length();
     unique = unique_string(sort, sort_size);
     for (char i: unique){
         cout << i << ": " 
              << target_search(sort, sort_size, i) 
              << endl;
    }
}

int main()
{   
    string user_sentence; 
    cout << "Enter sentence: " ;
    getline(cin, user_sentence); 
    sort_string(user_sentence, user_sentence.size());
    print_freq(user_sentence, user_sentence.size());
}

// MISSING FUNCTION DEFINITIONS HERE (you can remove these comments)
