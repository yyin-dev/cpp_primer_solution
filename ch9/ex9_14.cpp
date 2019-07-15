#include "headers.h"

int main() {
    list<const char *> l{"Go", "Big"};
    vector<string> v;
    // v.assign(l); // error
    v.assign(l.begin(), l.end());
}