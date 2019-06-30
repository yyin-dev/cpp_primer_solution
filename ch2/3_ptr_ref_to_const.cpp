#include <iostream>
using namespace std;

int main() {
    cout << "1. You can use const reference/pointer to refer/point non-const objects."
         << "Objects referenced by const reference or pointed to by const pointers are "
         << "not const! You just cannot modify them through const reference or pointer."
         << "As written in C++ Primer page 63: \nIt is helpoful to think of pointers and "
         << "references to const as pointers or references 'that think they point/refer to const.'"
         << endl;
    int i = 1;
    int* intPtr = &i;
    int& intRef = i;
    const int* ptrToConstInt = &i;
    const int& refToConstInt = i;

    cout << i << endl;
    cout << *intPtr << endl;
    cout << intRef << endl;
    cout << *ptrToConstInt << endl;
    cout << refToConstInt << endl;

    *intPtr = 2;
    cout << *intPtr << endl;
    intRef = 3;
    cout << intRef << endl;
    // *ptrToConstInt = 4;   // error: cannot modify const
    // refToConstInt = 5;    // error: cannot modify const

    cout << "2. However, you cannot use non-const reference/pointer to refer/point const objects." << endl;
    const double d = 1.1;
    const double* ptrToConstDouble = &d;
    const double& refToConstDouble = d;
    // double * doublePtr = &d;
    // double & doubleRef = d;
    cout << *ptrToConstDouble << endl;
    cout << refToConstDouble << endl;

    return 0;
}