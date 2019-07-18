#include "headers.h"

int main() {
    ifstream ifs("./ints.txt");
    istream_iterator<int> is_iter(ifs), eof;
    vector<int> v;
    copy(is_iter, eof, back_inserter(v));
    for (auto iter = v.cbegin(); iter != v.cend(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    stable_sort(v.begin(), v.end(), [](int i1, int i2) -> bool {
        if (i1 % 2 != i2 % 2) {
            return i1 % 2 > i2 % 2;
        } else {
            return i1 < i2;
        }
    });

    for (auto iter = v.cbegin(); iter != v.cend(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    auto first_even_iter = find_if(v.cbegin(), v.cend(), [](int i) { return i % 2 == 0; });
    vector<int> odds, evens;
    copy(v.cbegin(), first_even_iter, back_inserter(odds));
    copy(first_even_iter, v.cend(), back_inserter(evens));    
    for (auto iter = odds.cbegin(); iter != odds.cend(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    for (auto iter = evens.cbegin(); iter != evens.cend(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}