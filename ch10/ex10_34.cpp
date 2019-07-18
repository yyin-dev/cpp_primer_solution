#include "headers.h"

int main() {
    vector<int> v{1, 2, 3};
    for (auto iter = v.crbegin(); iter != v.crend(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}