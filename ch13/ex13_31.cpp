#include "ex13_31.h"
#include "headers.h"

int main() {
    vector<HasPtr> v{HasPtr("A"), HasPtr("B"), HasPtr("C"), HasPtr("D"), HasPtr("E"),
                     HasPtr("F"), HasPtr("G"), HasPtr("H"), HasPtr("I"),
                     HasPtr("A"), HasPtr("B"), HasPtr("C"), HasPtr("D"), HasPtr("E"),
                     HasPtr("A"), HasPtr("B"), HasPtr("C"), HasPtr("D"), HasPtr("E"),
                     HasPtr("A"), HasPtr("B"), HasPtr("C"), HasPtr("D"), HasPtr("E")};
    for (auto h : v) {
        h.print();
    }
    cout << endl;
    sort(v.begin(), v.end());
    for (auto h : v) {
        h.print();
    }
}