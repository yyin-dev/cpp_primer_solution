#include "headers.h"

template <unsigned sz, typename elem_T>
constexpr size_t my_size(const elem_T (&arr)[sz]) {
    return sz;
}


int main() {
    int arr[3] = {2, 4, 6};
    string strs[2] = {"hello", "there"};
    cout << my_size(arr) << endl;
    cout << my_size(strs) << endl;
}