#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << cin.goodbit << endl;
    cout << cin.badbit << endl;
    cout << cin.eofbit << endl;
    cout << cin.failbit << endl << endl;
    // Should be three bits in total: XXX.
    // Leftmost bit: failbit. 1 if recoverable error;
    // Middle bit: eofbit. 1 if eof.
    // Rightmost bit: badbit. 1 if system-level error.
    // If all ok, ok bit is 0. 

    cout << cin.rdstate() << endl;
    cout << cin.good() << endl;
    cout << cin.fail() << endl;
}