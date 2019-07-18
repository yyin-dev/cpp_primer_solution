#include "headers.h"

int main() {
    list<string> l{
        "1234",
        "HKU",
        "alan",
        "1234",
        "HKUST",
        "HKU",
        "UCB",
        "1234",
    };
    for (auto e : l) {
        cout << e << " ";
    }
    cout << endl;

    l.sort([](string s1, string s2) {return s1 < s2;});
    for (auto e : l) {
        cout << e << " ";
    }
    cout << endl;

    l.unique();
    for (auto e : l) {
        cout << e << " ";
    }
    cout << endl;
}