#include "Sales_data.h"
#include "headers.h"

/////////////////////////////////////////////////////////////////////
// Forget about this way. Use the way in my_print always!!!!
/////////////////////////////////////////////////////////////////////
// template <typename arr_T>
// void print(const arr_T& arr) {              // You cannot use the element type or the size
//     for (auto element : arr) {
//         cout << element << " ";
//     }
//     cout << endl;
// }

template <unsigned sz, typename elem_T>
void my_print(const elem_T (&arr)[sz]) {   // This way, you can use the element type and the size
    for (auto element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    int arr[3] = {2, 4, 6};
    string strs[2] = {"hello", "there"};
    my_print(arr);
    my_print(strs);
}