#include "headers.h"

int main() {
    vector<int> v;
    for (int i = 1; i <= 9; i++) {
        v.push_back(i);
    }
    for (auto iter = v.cbegin(); iter != v.cend(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    list<int> ins;
    list<int> back_ins;
    list<int> front_ins;

    copy(v.cbegin(), v.cend(), inserter(ins, ins.end()));
    for (auto iter = ins.cbegin(); iter != ins.cend(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    copy(v.cbegin(), v.cend(), back_inserter(back_ins));
    for (auto iter = back_ins.cbegin(); iter != back_ins.cend(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    copy(v.cbegin(), v.cend(), front_inserter(front_ins));
    for (auto iter = front_ins.cbegin(); iter != front_ins.cend(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}
