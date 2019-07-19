#include "headers.h"

int main() {
    map<string, int> counting_book;
    set<string> exculsion_set = {"and", "but", "or"};

    ifstream ifs("./word_count_input.txt");
    string word;
    while (ifs >> word) {
        if (exculsion_set.find(word) == exculsion_set.end()) {
            ++counting_book[word];
        }
    }

    for (auto &kv_pair : counting_book) {
        cout << kv_pair.first << ": " << kv_pair.second << "; " << endl;
    }
}