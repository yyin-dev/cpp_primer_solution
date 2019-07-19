#include "headers.h"

void tolower(string &s) {
    for (char &c : s) {
        c = tolower(c);
    }
}

void remove_punc(string &s) {
    auto iter = s.begin();
    while (iter != s.end()) {
        if (!isalpha(*iter)) {
            iter = s.erase(iter, iter + 1);
        } else {
            ++iter;
        }
    }
}

int main() {
    map<string, int> counting_book;
    set<string> exculsion_set = {"and", "but", "or"};

    ifstream ifs("./word_count_input.txt");
    string word;
    while (ifs >> word) {
        tolower(word);
        remove_punc(word);
        if (exculsion_set.find(word) == exculsion_set.end()) {
            ++counting_book[word];
        }
    }

    for (auto &kv_pair : counting_book) {
        cout << kv_pair.first << ": " << kv_pair.second << "; " << endl;
    }
}