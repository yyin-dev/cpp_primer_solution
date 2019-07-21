#include "headers.h"

int main() {
    string word;
    cin >> word;
    char* arr = new char[word.length()];
    auto iter = word.begin();
    while (iter != word.end()) {
        arr[iter - word.begin()] = *iter;
        ++iter;
    }

    for (int i = 0; i < word.length(); i++) {
        cout << arr[i];
    }
}