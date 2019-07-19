#include "headers.h"



void new_family(map<string, vector<string>> &family_book, const string &lastname, const vector<string> &children) {
    family_book[lastname] = children; 
}

void new_children(map<string, vector<string>> &family_book, const string &lastname, const vector<string> &new_children){
    for(auto &c: new_children){
        family_book[lastname].push_back(c);
    }
}

void print_family_book(map<string, vector<string>> family_book){
    for (auto &p: family_book){
        cout << "[Family] " << p.first << ": ";
        for(auto &c: p.second){
            cout << c << ", ";
        }
        cout << endl;
    }
}


int main() {
    map<string, vector<string>> family_book;
    new_family(family_book, "James", {"Bronny", "Bryce", "Jr."});
    new_family(family_book, "Bryant", {"Natalie", "Bianka", "Gianna"});
    print_family_book(family_book);
    cout << "[News] New children to Bryant's family!" << endl;
    new_children(family_book, "Bryant", {"Capri"});
    print_family_book(family_book);
}
