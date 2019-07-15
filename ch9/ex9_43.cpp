#include "headers.h"

void replace_all(string &s, string old_val, string new_val) {
    int old_val_length = old_val.length();
    auto iter = s.begin();

    while (iter != s.end()) {
        string next_substr = s.substr(iter - s.begin(), old_val_length);
        if (next_substr == old_val) {
            iter = s.erase(iter, iter + old_val_length); // iter is updated to pointing the element after the erased range
            iter = s.insert(iter, new_val.begin(), new_val.end()); // iter pointed to the first inserted element
            iter += new_val.length();
        } else {
            iter++;
        }
    }
}

int main() {
    string s = "Hi, tho, how are you. I still love you tho. tho";
    cout << s << endl;
    replace_all(s, "tho", "though");
    cout << s << endl;
}