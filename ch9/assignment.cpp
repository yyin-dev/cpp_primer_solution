#include "headers.h"

int main() {
    // Assign container of the same type, same element type, with different size is ok.
    vector<int> v1{1, 2};
    vector<int> v2{1, 2, 3};
    cout << v1.size() << endl;
    v1 = v2; // v1 and v2 are of the same type: vector<int>
    cout << v1.size() << endl;

    // Assign array of the SAME size is ok.
    array<int, 3> arr1{1, 2, 3};
    array<int, 3> arr2{4, 5, 6};
    for(int i : arr1){ cout << i << " "; }
    cout << endl;
    arr1 = arr2; // arr1 and arr2 are of the same type: array<int, 3>
    for(int i : arr1){ cout << i << " "; }
    cout << endl;

    // Assign between different container types are not allowed.
    vector<int> v3{1, 2, 3};
    list<int> l{1, 2};
    // l = v3; // error
}