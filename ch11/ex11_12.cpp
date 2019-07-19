#include "headers.h"

int main() {
    string s;
    int i;
    vector<pair<string,int>> v;
    while(cin >> s >> i){
        pair<string, int> p{s, i};
        v.push_back(p);
    }
    for (auto &p : v){
        cout << p.first << "-" << p.second << endl;
    }
}