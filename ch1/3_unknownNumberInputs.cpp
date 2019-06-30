#include <iostream>
using namespace std;

int main() {
    cout << "The way to generate end-of-file through keyboard: press Ctrl+Z and then press Enter.\n";

    int sum = 0;
    int val = 0;
    cout << "Enter as many integers as you like to get the sum: \n";
    while ( cin >> val){
        sum += val;
    }

    cout << "Sum: " << sum;
}