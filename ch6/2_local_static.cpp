#include <iostream>
#include "Chapter6.h"
using std::cout;
using std::endl;

int count() {
    static int i = 0;
    return ++i;
}

void declaredButNotDefined(); // You can declare a function without define it
void declaredButNotDefined(); // You can even declare it many times.


int main() {
    for (int i = 0; i < 10; i++) {
        cout << count() << " ";
    }
}