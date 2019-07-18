#include "headers.h"

int main() {
    vector<int> v{1, 2, 3};
    for (auto iter = v.cend() - 1; iter != v.cbegin() - 1; iter--) {
        cout << *iter << " ";
    }
    cout << endl;
}