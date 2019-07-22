#include "ex13_39.h"
#include "headers.h"

int main() {
    // test reallocate
    StrVec sv1;
    sv1.push_back("Hi");
    sv1.info();
    sv1.push_back("Hello");
    sv1.info();
    sv1.push_back("There");
    sv1.info();
    cout << endl;

    // test copy assignment operator
    StrVec sv2 = sv1;
    sv2.info();
    sv2.push_back("Good");
    sv1.info();
    sv2.info();
    cout << endl;

    // test copy constructor
    StrVec sv3(sv1);
    sv3.info();
    sv3.push_back("Great");
    sv1.info();
    sv3.info();
    cout << endl;

    // test reserve
    StrVec reserve_test;
    reserve_test.info();
    reserve_test.reserve(10);
    reserve_test.push_back("Here");
    reserve_test.info();
    cout << endl;

    // rest resize
    StrVec resize_test;
    for (int i = 0; i < 5; i++) {
        resize_test.push_back("Hi");
    }
    resize_test.info();
    resize_test.resize(1);
    resize_test.info();
}