#include "headers.h"

int main() {
    int i = 3;
    auto decrement_to_zero = [&i]() -> bool { --i; cout << i << endl; return i > 0; };

    while(decrement_to_zero()){}
}