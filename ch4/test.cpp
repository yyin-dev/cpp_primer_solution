#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main() {
    int array[5] = {9, 7, 5, 3, 1};

    cout << sizeof(array) << endl;
    cout << *array << endl;
    cout << sizeof(*array) << endl;
    
    return 0;
}