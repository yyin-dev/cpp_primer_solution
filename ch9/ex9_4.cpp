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

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    cout << contains(v.cbegin(), v.cend(), 3) << endl;
    cout << contains(v.cbegin(), v.cend(), 10) << endl;
}