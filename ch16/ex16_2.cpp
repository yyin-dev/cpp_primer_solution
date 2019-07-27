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
    cout << compare(1, 2) << endl;
    cout << compare(1.5, 2.1) << endl;
    cout << compare(string("A"), string("B")) << endl;
}