#include <iostream>
using namespace std;

int main() {
    // In all but two cases, when a fixed array is used in an expression, 
    // the fixed array will decay (be implicitly converted) into a pointer that points to the first element of the array.
    // Fixed arry: an array whose size is known at compile time.

    int array[5] = {9, 7, 5, 3, 1};

    // 1. Decay happens automatically: 
    // print address of the array's first element
    cout << "Element 0 has address: " << &(array[0]) << '\n';

    // print the value of the pointer the array decays to
    cout << "The array decays to a pointer holding address: " << array << '\n';


    // It’s a common fallacy in C++ to believe an array and a pointer to the 1st element in the array are identical. 
    // They’re not. In the above case, array is of type “int[5]”, and it’s “value” is the array elements themselves. 
    // A pointer to the array would be of type “int *”, and its value is the address of the first element of the array.

    // All elements of the array can still be accessed through the pointer, 
    // but information derived from the array’s type (such as how long the array is) can not be accessed from the pointer.
    int arr[] = {0, 1, 2};
    int i = arr[2]; // arr decays to a pointer, equivalent to: int i = *(arr + 2)


    cout << *array << endl; 
    // We’re not dereferencing the array itself. The array (of type int[5]) decays into a pointer (of type int *), 
    // and we dereference the pointer.

    int *ptr = array; // Decay happens.
    cout << *ptr << endl;


    // 2. When decay does not happen

    // 2.1 sizeof()
    cout << sizeof(array) << "  " << sizeof(ptr) << endl;
    // For array, sizeof() returns the size for entire array (array length * element size);
    // For pointer, sizeof() returns the size of the memory address. 
    // An array knows the number of elements itself contains(this is part of its type information),
    // but a pointer to the array (pointing to the first element) does not.   

    // 2.2
    // The second difference occurs when using the address-of operator (&). 
    // Taking the address of a pointer yields the memory address of the pointer variable. 
    // Taking the address of the array returns a pointer to the ENTIRE array. 
    // This pointer also points to the first element of the array, but the type information is different 
    // (in the above example, int(*)[5]).

    // https://stackoverflow.com/a/4223652
    return 0;
}