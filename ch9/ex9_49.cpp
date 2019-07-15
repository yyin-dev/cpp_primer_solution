#include "headers.h"

string longest_word_wo_ascender_or_descender(string file) {
    string::size_type max_len = 0;
    string w_ascenders_or_descenders = "bdfghklpqty";
    string res;

    fstream fs(file);
    string word;
    while (fs >> word) {
        if (word.length() > max_len && word.find_first_of(w_ascenders_or_descenders) == string::npos) {
            cout << "Original word: " << res << ", original length: " << max_len << endl; 
            res = word;
            max_len = word.length();
            cout << "New word: " << res << ", new length: " << max_len << endl; 
        }
    }

    return res;
}

int main() {
    string word = longest_word_wo_ascender_or_descender("assignment.cpp");
    cout << word << endl;
}