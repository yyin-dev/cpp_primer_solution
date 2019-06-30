#include<iostream>
using namespace std;

int main() {
    int i1 = 0, i2 =0;
    cout << "Enter 2 integers: \n";
    cin >> i1 >> i2;

    if (i1 > i2){
        int temp = i2;
        i2 = i1;
        i1 = temp;
    }

    for (int i = i1; i <= i2; i++){
        cout <<  i << " ";
    }
    return 0;
}