#include "headers.h"

class X {
   public:
    X() { cout << "X()" << endl; }
    X(const X&) { cout << "X(const X&)" << endl; }
    X& operator=(const X&) {
        cout << "X& operator=(const X& rhs)" << endl;
        return *this;
    }
    ~X() { cout << "~X()" << endl; }
};

void nonref(X x) {}
void ref(X& x) {}
void dynamic() { X* x = new X(); delete x;}
void into_container() { vector<X> v{X()}; }

int main() {
    // X x;
    // nonref(x);
    // ref(x);
    // dynamic();
    into_container();
}