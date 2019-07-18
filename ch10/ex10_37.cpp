#include "headers.h"

int main() {
    vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> sub;

    copy(v.crend() - 7, v.crend() -3 + 1, back_inserter(sub));

    for (auto e : sub) {
        cout << e << " ";
    }
    cout << endl;
}