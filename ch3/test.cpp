#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main() {
    int arr[10];
    for (size_t i = 0; i < 10; ++i) {
        arr[i] = i;
    }

    for (int i : arr) {
        cout << i << " ";
    }

    cout << endl;

    for (int* ptr = arr; ptr != end(arr); ++ptr) {
        *ptr = 0;
    }

    for (int i : arr) {
        cout << i << " ";
    }
}