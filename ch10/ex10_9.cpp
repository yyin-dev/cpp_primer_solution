#include "headers.h"


void elimDups(vector<string> & v){
    sort(v.begin(), v.end());
    auto iter_after_uniq = unique(v.begin(), v.end());
    v.erase(iter_after_uniq, v.end());
}

int main() {
    vector<string> v{ "a", "v", "a", "s", "v", "a", "a" };
    for(auto iter = v.cbegin(); iter != v.cend(); iter++){ cout << *iter << " "; }
    elimDups(v);
    cout << endl;
    for(auto iter = v.cbegin(); iter != v.cend(); iter++){ cout << *iter << " "; }
}