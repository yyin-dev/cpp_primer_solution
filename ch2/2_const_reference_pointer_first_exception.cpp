#include <iostream>
using namespace std;

int main() {
    int i = 10;

    cout << "Reference Example: " << endl;
    // 1.1 Normal reference usage
    int &intRef1 = i;                    // nonconst int ref can bind nonconst int
    cout << intRef1 << endl;
    const int &constIntRef1 = i;         // const int can bind nonconst int
    cout << constIntRef1 << endl;
    // double &doubleRef = i;            // error: type mismatch

    const int ci = 20;
    // int &intRef2 = ci;                // nonconst int ref CANNOT bind const int
    const int constIntRef2 = ci;         // const int ref can bind const int   

    // 1.2 Reference first exception
    const double &constDoubleRef = i;
    cout << constDoubleRef << endl;

    cout << endl << "Pointer Example: " << endl;
    // 2.1 Normal pointer usage
    int *intPtr = &i;
    cout << intPtr << endl;
    cout << *intPtr << endl;
    const int *constIntPtr = &i;
    cout << constIntPtr << endl;
    cout << *constIntPtr << endl;
    // double *doublePtr = &i; // error: type mismatch

    // 2.2 Pointer first exception
    const int *constDoublePtr = &i;
    cout << constDoublePtr << endl;
    cout << *constDoublePtr << endl;

    cout << endl << "For the logic of the language design, refer to "
                    "page 61 and 62 of C++ Primer." << endl;
}