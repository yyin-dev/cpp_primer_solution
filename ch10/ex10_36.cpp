#include "headers.h"

int main() {
    list<int> l{ 1, 2, 3, 0, 1};
    auto last_zero_iter = find(l.crbegin(), l.crend(), 0);
    cout << *last_zero_iter;
}