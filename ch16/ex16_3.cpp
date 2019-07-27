#include "headers.h"
#include "Sales_data.h"


template <typename T> 
int compare(T v1, T v2) {
    if (v1 < v2) {
        return -1;
    }

    if (v2 < v1 ) {
        return 1;
    }

    return 0;
}

int main() {
    cout << compare(Sales_data(), Sales_data()) << endl;
    /*
    In instantiation of 'int compare(T, T) [with T = Sales_data]':
    ex16_3.cpp:19:47:   required from here
    ex16_3.cpp:7:12: error: no match for 'operator<' (operand types are 'Sales_data' and 'Sales_data')
        if (v1 < v2) {
            ~~~^~~~
    ex16_3.cpp:11:12: error: no match for 'operator<' (operand types are 'Sales_data' and 'Sales_data')
        if (v2 < v1 ) {
            ~~~^~~~
     */
}