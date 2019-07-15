#include "headers.h"

void replace_all(string &s, string old_val, string new_val) {
    int old_val_length = old_val.length();

    int index = 0;
    while (index <= s.size()) {
        string next_substr = s.substr(index, old_val_length);
        if(next_substr == old_val){
            s.replace(index, old_val_length, new_val);
            cout << "Replaced " << old_val << " with " << new_val << endl;
            index = index + old_val_length + 1;
        } else{
            ++index;
        }   
    }
}

int main() {
    string s = "Hi, tho, how are you. I still love you tho. tho";
    cout << s << endl;
    replace_all(s, "tho", "though");
    cout << s << endl;
}