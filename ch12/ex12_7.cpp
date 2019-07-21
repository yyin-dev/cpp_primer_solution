#include "headers.h"

shared_ptr<vector<int>> create() {
    return make_shared<vector<int>>();
}



shared_ptr<vector<int>> fill(shared_ptr<vector<int>> pv) {
    int i;
    while (cin >> i) {
        pv->push_back(i);
    }

    return pv;
}

void print(shared_ptr<vector<int>> pv) {
    for (auto i : *pv) {
        cout << i << " ";
    }
}

int main() {
    print(fill(create()));
}