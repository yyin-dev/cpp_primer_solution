#include "headers.h"

int main() {
    vector<int> v;
    v.resize(10);
    fill_n(v.begin(), 10, 1);
    for(auto iter = v.cbegin(); iter != v.cend(); iter++){ cout << *iter << " "; }
}