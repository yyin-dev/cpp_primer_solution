#include "headers.h"

int main() {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

    vector<int> iv;
    list<int> il;
    for (int i : ia) {
        iv.push_back(i);
        il.push_back(i);
    }

    cout << iv.size() << endl;

    auto iter1 = iv.begin();
    while (iter1 != iv.end()) {
        if (*iter1 % 2 == 1) {
            iter1 = iv.erase(iter1);
        } else {
            iter1++;
        }
    }

    cout << iv.size() << endl;

    auto iter2 = il.begin();
    while (iter2 != il.end()) {
        if (*iter2 % 2 == 0) {
            iter2 = il.erase(iter2);
        } else {
            iter2++;
        }
    }
    cout << il.size() << endl;

}