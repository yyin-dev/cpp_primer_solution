#include "headers.h"

int main () {
    modulus<int> mod;
    int i = 15;
    int j = 2;
    int k = 3;
    cout << (mod(i, j) == 0) << endl;
    cout << (mod(i, k) == 0) << endl;
}   