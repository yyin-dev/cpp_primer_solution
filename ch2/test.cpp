#include <iostream>
using namespace std;

int main() {
    int i1 = 10, i2 = 20;

    int *iPointer = &i1;
    cout << *iPointer << endl;
    iPointer = &i2;
    cout << *iPointer << endl;

    *iPointer = 30;
    cout << *iPointer << endl;
    cout << i2 << endl;

    return 0;
}