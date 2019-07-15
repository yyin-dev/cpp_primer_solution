#include "headers.h"

int main() {
    vector<int> v1{1, 2, 3};
    vector<int> v2{-1, -2, -3};
    vector<int>::iterator iter = v1.begin();
    int * i_ptr = &v1[1];
    int & i_ref = v1[2];
    cout << "Before swap: " << endl;
    cout << *iter << " " << *i_ptr << " " << i_ref << endl;

    swap(v1, v2);

    cout << "After swap: " << endl;
    cout << *iter << " " << *i_ptr << " " << i_ref << endl;
}