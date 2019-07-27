#include "headers.h"

template <unsigned sz, typename elem_T>
elem_T* my_begin(elem_T (&arr)[sz]) {
    return &(arr[0]);
}

template <unsigned sz, typename elem_T>
elem_T* my_end(elem_T (&arr)[sz]) {
    return &(arr[sz]);
}

// This is wrong. When you need to deal with element types
// inside the array, you need to use the way in my_begin()
// template <typename arr_T>
// arr_T::iterator wrong_begin(arr_T& arr) { /* ... */
// }

int main() {
    int arr[3] = {2, 4, 6};
    string strs[2] = {"hello", "there"};
    cout << *(my_begin(arr)) << endl;
    cout << *(my_end(arr)) << endl;
    for (auto p = my_begin(arr); p != my_end(arr); p++) {
        cout << *p << " ";
    }
}