#include "headers.h"

using name_birthday_pair = pair<string, string>;

void new_family(multimap<string, vector<name_birthday_pair>> &family_book, const string &lastname, const vector<name_birthday_pair> &children) {
    family_book.insert({lastname, children});
}

void print_family_book(multimap<string, vector<name_birthday_pair>> family_book) {
    for (auto &p : family_book) {
        cout << "[Family] " << p.first << ": ";
        for (auto &name_birthday_p : p.second) {
            cout << name_birthday_p.first << "(" << name_birthday_p.second << "), ";
        }
        cout << endl;
    }
}

int main() {
    multimap<string, vector<name_birthday_pair>> family_book;

    new_family(family_book, "James", {make_pair("Bronny", "2001-01-01"), make_pair("Bryce", "2005-01-01"), make_pair("Jr.", "2007-01-01")});
    new_family(family_book, "Bryant", {make_pair("Natalie", "2002-01-01"), make_pair("Bianka", "2006-01-01"), make_pair("Gianna.", "2008-01-01")});
    print_family_book(family_book);
}
