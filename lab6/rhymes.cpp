#include <iostream> 
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

// necessary functions
string last_word(string sentence, int asize);
string word_clean(string word, int asize);
bool last_comparison(string clean1, string clean2, int asize1, int asize2);

// my funcs 
string plural_check(string single, string plural, int a);
void aggre_func(string filename);


string last_word(string sentence, int asize){
    int index = sentence.rfind(' ');
    return sentence.substr(index + 1);
}

string word_clean(string word, int asize){
    string clean_word = "";
    for (char i:word){
        if (isalpha(i)){
            clean_word += i;
        }
    }
    return clean_word;
}

bool last_comparison(string clean1, string clean2, int asize1, int asize2){
     if ((clean1[asize1-1] == clean2[asize2-1]) && (clean1[asize1-2] == clean2[asize2-2])){
         return true;
     }
     else{
         return false; 
     }
}

string plural_check(string single, string plural, int a){
    if (a == 1){
        return single;
    }
    else{
        return plural;
    }
}

void aggre_func(string filename){
    ifstream in1, in2;
    string line1, line2, last1, last2, last1_clean, last2_clean;
    double rhy_count(0), line_count(1);

    in1.open(filename); 
    if (in1.fail()){
        cerr << "Input file opening failed.";
        exit(1);
    }
    in2.open(filename);

    getline(in2, line2);
    while (!in2.eof()){
        getline(in1, line1);
        getline(in2, line2); 
        last1 = last_word(line1, line1.size());
        last2 = last_word(line2, line2.size());
        last1_clean = word_clean(last1, last1.size());
        last2_clean = word_clean(last2, last2.size());

        if (last_comparison(last1_clean, last2_clean, last1_clean.size(), last2_clean.size())){
            cout << last1_clean << " and " << last2_clean << endl;
            rhy_count += 1;
        }
        line_count += 1;
    }
    if (rhy_count > 0){
        cout << "There " << plural_check("is ", "are ", rhy_count)
        << rhy_count << plural_check(" pair", " pairs", rhy_count)
        <<" of rhyming words." << endl;

        cout << "There " << plural_check("is ", "are ", line_count) 
        << line_count << plural_check(" line", " lines", line_count)
        << " in this poem, so the rhyme-line density is: ";
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << rhy_count / line_count << endl;
    } 
    else{
        cout << "No rhymes found." << endl;
        cout << "There " << plural_check("is ", "are ", line_count) 
        << line_count << plural_check(" line", " lines", line_count)
        << " in this poem."; 
    }
    in1.close();
    in2.close();
}


int main(){

    string filename;
    cout << "Enter filename: ";
    getline(cin, filename); 
    aggre_func(filename);
    return 0;
}