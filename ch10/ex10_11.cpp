#include "headers.h"

void elimDups(vector<string>& v) {
    sort(v.begin(), v.end());
    auto iter_after_uniq = unique(v.begin(), v.end());
    v.erase(iter_after_uniq, v.end());
}

bool isShorter(const string& c1, const string& c2) {
    return c1.length() < c2.length();
}

int main() {
    vector<string> v{"1234", "1234", "1234", "Hi", "alan", "wang"};
    for (auto iter = v.cbegin(); iter != v.cend(); iter++) {
        cout << *iter << " ";
    }
    elimDups(v);
    stable_sort(v.begin(), v.end(), isShorter); // stable_sort() cannot use cbegin or cend!
    cout << endl;

    for (auto iter = v.cbegin(); iter != v.cend(); iter++) {
        cout << *iter << " ";
    }
}