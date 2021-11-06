#include <iostream>
#include <string>
using namespace std;

void compute_coins(int amount);
string plural_check(int num, string s, string ss);

string plural_check(int num, string s, string ss){
    if (num == 1){
        return s;
    }
    else{
        return ss;
    }
}

void compute_coins(int amount){
    string a = " cent can be given in ", 
           as = " cents can be given in ",
           q = " quarter",
           qs = " quarters",  
           d = " dime",
           ds = " dimes",  
           p = " penny.",
           ps = " pennies.",
           out = "Amount is out of bounds. Must be between 1 and 99.";

    int quarter(0), quarter_left(0), dime(0), dime_left(0), penny(0);
    
     quarter = amount / 25;
     quarter_left = amount % 25; 
     dime = quarter_left / 10; 
     dime_left = quarter_left % 10; 
     penny = dime_left;

    if (amount > 99 || amount < 1){
         cout << out << endl;
         return;
     }

    if (quarter != 0 && dime != 0 && penny != 0){
        cout << amount << plural_check(amount, a, as)  
             << quarter << plural_check(quarter, q, qs) << ", "
             << dime << plural_check(dime, d, ds) << ", "
             << penny << plural_check(penny, p, ps) << endl;
    }
    else if (quarter != 0 && dime != 0 && penny == 0){
        cout << amount << plural_check(amount, a, as) 
             << quarter << plural_check(quarter, q, qs) << ", "
             << dime << plural_check(dime, d, ds) << "."<<endl; 
    }
    else if (quarter != 0 && dime == 0 && penny == 0){
        cout << amount << plural_check(amount, a, as)  
             << quarter << plural_check(quarter, q, qs) << "." <<endl;        
    } 
    else if (quarter == 0 && dime != 0 && penny == 0){
        cout << amount << plural_check(amount, a, as) 
             << dime << plural_check(dime, d, ds) << "." <<endl;
    }
    else if (quarter != 0 && dime == 0 && penny != 0){
        cout << amount << plural_check(amount, a, as)  
             << quarter << plural_check(quarter, q, qs) << ", "
             << penny << plural_check(penny, p, ps) << endl;
    }
    else if (quarter == 0 && dime == 0 && penny != 0){
        cout << amount << plural_check(amount, a, as)  
             << penny << plural_check(penny, p, ps) << endl; 
    }
    else if (quarter == 0 && dime != 0 && penny != 0){
        cout << amount << plural_check(amount, a, as) 
             << dime << plural_check(dime, d, ds) << ", "
             << penny << plural_check(penny, p, ps) << endl; 
    }
 
}

int main(){
    int user_amount(0);
    string enter = "Enter number of cents (or zero to quit):";
    cout << enter << endl; 
    cin >> user_amount; 
    while (user_amount != 0){
        compute_coins(user_amount);
        cout << enter << endl;
        cin >> user_amount;
    }
    return 0; 
}