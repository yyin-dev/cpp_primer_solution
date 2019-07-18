#include "headers.h"

int main() {
    // (b)
    vector<int> v;
    v.reserve(10);
    fill_n(v.begin(), 10, 0);
    for(auto iter = v.cbegin(); iter != v.cend(); iter++){ cout << *iter << " "; }
}