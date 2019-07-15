#include "headers.h"

bool contains(vector<int>::const_iterator begin, vector<int>::const_iterator end, int target) {
    while (begin != end) {
        if (*begin == target) {
            return true;
        } else {
            begin++;
        }
    }
    return false;
}

vector<int>::iterator get_pointer(vector<int>::iterator begin, vector<int>::iterator end, int target) {
    vector<int>::iterator null_pointer(nullptr);
    while (begin != end) {
        if (*begin == target) {
            return begin;
        } else {
            begin++;
        }
    }
    return null_pointer;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    cout << contains(v.cbegin(), v.cend(), 3) << endl;
    cout << contains(v.cbegin(), v.cend(), 10) << endl;

    cout << *get_pointer(v.begin(), v.end(), 3) << endl;
    cout << *get_pointer(v.begin(), v.end(), 10) << endl;
}