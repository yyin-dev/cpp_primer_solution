#include "headers.h"

int main() {
    list<int> l = {0, 1, 2, 3, 4};

    deque<int> even, odd;

    int counter = 0;
    for (auto iter = l.begin(); iter != l.end(); iter++) {
        if (counter % 2 == 0) {
            even.push_back(*iter);
        } else {
            odd.push_back(*iter);
        }
        counter++;
    }

    cout << even.size() << endl;
    cout << odd.size() << endl;
}