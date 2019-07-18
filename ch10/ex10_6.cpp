#include "headers.h"

int main() {
    vector<int> v(10, -1);
    for(auto iter = v.cbegin(); iter != v.cend(); iter++){ cout << *iter << " "; }
    
    fill_n(v.begin(), v.size(), 0);

    for(auto iter = v.cbegin(); iter != v.cend(); iter++){ cout << *iter << " "; }
}