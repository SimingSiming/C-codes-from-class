#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string clean_string(string sentence, int size); 
string unique_string(string sentence, int size);
string lower_string(string sentence, int size);
int target_search(string sentence, int size, char target);
void anagrams_check(string sentence1, string sentence2, int size1, int size2);

string clean_string(string sentence, int size){
    string clean = "";
    for (int i = 0; i < size; i++){
        if (isalpha(sentence[i])){
             clean += sentence[i];
        }
    }
    return clean; 
}

string lower_string(string sentence, int size){
    for (int i = 0; i < size; i++){
        if (islower(sentence[i]) == false){
            sentence[i] = tolower(sentence[i]);  
        }
    }
    return sentence;
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

void anagrams_check(string sentence1, string sentence2, int size1, int size2){
	int clean1_size, clean2_size, unique1_size, unique2_size, 
    lower1_size, lower2_size; 
	string clean1, clean2, unique1, unique2, lower1, lower2, output;
	clean1 = clean_string(sentence1, size1);
	clean2 = clean_string(sentence2, size2);
    clean1_size = clean1.length();
	clean2_size = clean2.length();

    lower1 = lower_string(clean1, clean1_size); 
    lower2 = lower_string(clean2, clean2_size);
    lower1_size = clean1_size;
    lower2_size = clean2_size; 

	unique1 = unique_string(lower1, lower1_size);
	unique2 = unique_string(lower2, lower2_size); 
	unique1_size = unique1.length();
	unique2_size = unique2.length(); 
 
	if (lower1_size != lower2_size){
		output = "The strings are not anagrams.";
        cout << output << endl;
		return;
	}
	else {
		if (unique1_size != unique2_size){
            output = "The strings are not anagrams.";
            cout << output << endl;
            return;
        }
        else { 
            for (char i : unique1){
                int count1 = target_search(lower1, lower1_size, i);
                int count2 = target_search(lower2, lower2_size, i);
                if (count1 != count2){
                    output = "The strings are not anagrams.";
                    cout << output << endl;
                    return;
                }
            }
            output = "The strings are anagrams.";
            cout << output << endl; 
            return; 
        }
	}
}

int main()
{
    string user_sen1, user_sen2;
    cout << "Enter first string:" << endl;
    getline(cin, user_sen1);
    cout << "Enter second string:" << endl;
    getline(cin, user_sen2);

    int sen1_size = user_sen1.length();
    int sen2_size = user_sen2.length();
    anagrams_check(user_sen1, user_sen2, sen1_size, sen2_size);
    return 0;
}

// MISSING FUNCTION DEFINITIONS HERE (you can remove these comments)
