#include "headers.h"

void find_digits_letters_v1(const string& s) {
    string::size_type pos = 0;
    // find digits
    while( (pos = s.find_first_of("abcdefghijklmnopqrstuwxyzABCDEFGHIJKLMNOPQRSTUWXYZ", pos)) != string::npos ){
        cout << "Find alphbet at index: " << pos << ", '" << s.at(pos) << "'." << endl;
        ++pos;
    }

    // find letters
    pos = 0;
    while( (pos = s.find_first_of("0123456789", pos)) != string::npos ){
        cout << "Find digit at index: " << pos << ", '" << s.at(pos) << "'." << endl;
        ++pos;
    }
}

void find_digits_letters_v2(const string& s) {
    string::size_type pos = 0;
    // find digits
    while( (pos = s.find_first_not_of("abcdefghijklmnopqrstuwxyzABCDEFGHIJKLMNOPQRSTUWXYZ", pos)) != string::npos ){
        cout << "Find digit at index: " << pos << ", '" << s.at(pos) << "'." << endl;
        ++pos;
    }

    // find letters
    pos = 0;
    while( (pos = s.find_first_not_of("0123456789", pos)) != string::npos ){
        cout << "Find alphabet at index: " << pos << ", '" << s.at(pos) << "'." << endl;
        ++pos;
    }
}

int main() {
    find_digits_letters_v1("1a2b3c");
    cout << endl;
    find_digits_letters_v2("1a2b3c");
}