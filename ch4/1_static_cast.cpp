#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main() {
    int i1 = 2;
    double d = 2.5;
    i1 *= static_cast<int>(d);
    cout << i1 << endl;

    int i2 = 2;
    i2 *= d;
    cout << i2 << endl;
}