#include <iostream>
using namespace std;

int main() {
    int i1 = 1, i2 = 10;

    // 1. normal pointer
    int * ptrToInt = &i1;
    cout << *ptrToInt << endl;
    ptrToInt = &i2;
    cout << *ptrToInt << endl;
    *ptrToInt += 1;
    cout << *ptrToInt << endl;

    // 2. pointer to const
    const int * ptrToConst = &i1;
    cout << *ptrToConst << endl;
    // *ptrToConst += 1; // error
    ptrToConst = &i2;
    cout << *ptrToConst << endl;

    // 3. const pointer to const
    const int * const constPtrToConst = &i1;
    cout << *constPtrToConst << endl;
    // constPtrToConst = &i2; // error
    // *constPtrToConst += 1; // error
    return 0;
}