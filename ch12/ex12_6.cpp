#include "headers.h"

vector<int> *create() {
    vector<int> *pv = new vector<int>();
    return pv;
}

vector<int> *fill(vector<int> *pv) {
    int i;
    while (cin >> i) {
        pv->push_back(i);
    }

    return pv;
}

void print_delete(vector<int> *pv) {
    for (auto i : *pv) {
        cout << i << " ";
    }
    delete pv;
}

int main() {
    print_delete(fill(create()));
}