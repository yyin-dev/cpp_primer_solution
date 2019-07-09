#include <iostream>
#include "Chapter6.h"
using std::cout;
using std::endl;

void swapWithPointer(int * ip1, int * ip2){
    int temp = *ip1;
    *ip1 = *ip2;
    *ip2 = temp;
}

void swapWithReference(int &i1, int &i2){
    int temp = i1;
    i1 = i2;
    i2 = temp;
}

int main(){
    int a = 1, b =2;
    swapWithPointer(&a, &b);
    cout << a << " " << b << endl;

    swapWithReference( a, b);
    cout << a << " " << b << endl;
}