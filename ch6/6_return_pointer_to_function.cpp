#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;


int takesTwoIntsReturnsOneInt(int i1, int i2);

// direct
vector<int (*) (int i1, int i2)> v1;

// type alias
typedef int takesTwoIntsReturnsOneIntFunctionType (int i1, int i2);
vector<takesTwoIntsReturnsOneIntFunctionType *> v2;

using takesTwoIntsReturnsOneIntFunctionPointerType = int (*) (int i1, int i2);
vector<takesTwoIntsReturnsOneIntFunctionPointerType> v3;

// decltype
vector<decltype(takesTwoIntsReturnsOneInt) *> v4;


inline int add(int i1, int i2){
    return i1 + i2;
}

inline int sub(int i1, int i2){
    return i1 - i2;
}

inline int mul(int i1, int i2){
    return i1 * i2;
}

inline int divide(int i1, int i2){
    return i1 / i2;
}


int main(int argc, char **argv) {
    vector<takesTwoIntsReturnsOneIntFunctionPointerType> functionPointers = {add, sub, mul, divide}; // automatically converted to pointer
    int a = 2, b = 4;
    cout << functionPointers[0](a, b) << endl; // automatically dereferenced
    cout << functionPointers[1](a, b) << endl;
    cout << functionPointers[2](a, b) << endl;
    cout << functionPointers[3](a, b) << endl;
    return 0;
}
