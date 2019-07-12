#include <iostream>
#include "ex7_41.h"
using namespace std;

int main() {
    Sales_data d1 = Sales_data();
    cout << endl;
    Sales_data d2 = Sales_data("CSAPP", 2, 25);
    cout << endl;
    Sales_data d3 = Sales_data("Primer");
    cout << endl;
    Sales_data d4(cin);
    cout << endl;

    Sales_data arr[4] = {d1, d2, d3, d4};
    for (Sales_data d : arr){
        print(cout, d) << endl;
    }
}