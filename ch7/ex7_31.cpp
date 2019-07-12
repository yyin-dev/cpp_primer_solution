#include <iostream>

using namespace std;

class Y;
class X;

class X {
    Y * y_ptr;
};

class Y {
    X x;
};

