#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NoDefault {
   public:
    NoDefault(int i) : integer(i) {}
    int integer;
};

class C {
   public:
    C() : obj(0) {} 
    NoDefault obj;
};

int main() {
    C c;
    cout << c.obj.integer;

    vector<NoDefault> vec(10);
}