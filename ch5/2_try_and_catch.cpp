#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int i1, i2;
    while (cin >> i1 >> i2) {
        try {
            if (i2 == 0) {
                throw runtime_error("Cannot divide by zero!");
            } else {
                cout << i1 / i2 << endl;
                break;
            }
        } catch (runtime_error err) {
            cout << err.what() << endl;
            cout << "Please enter the 2 numbers again: \n";
        }
    }

    return 0;
}