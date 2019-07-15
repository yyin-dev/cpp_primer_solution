#include "headers.h"

void use_deque() {
    deque<string> container;

    string str;
    while (cin >> str) {
        container.push_back(str);
    }

    for (auto iter = container.cbegin(); iter != container.cend(); iter++) {
        cout << *iter << " ";
    }
}

void use_list() {
    list<string> container;

    // below the same
    string str;
    while (cin >> str) {
        container.push_back(str);
    }

    for (auto iter = container.cbegin(); iter != container.cend(); iter++) {
        cout << *iter << " ";
    }
}



int main() {
    use_list();
}