#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // case 1: int, could have confusion

    // default initialization
    vector<int> v1;

    // copy elements, approach 1
    vector<int> v2 = v1;
    // copy elements, approach 2
    vector<int> v3(v1);

    // list initialization, approach 1
    vector<int> v4 = {1, 2, 3};
    // vector<int> v4 = (1, 2, 3); // error, cannot use ()
    // list initialization, approach 2
    vector<int> v5{1, 2, 3};

    // value initialization, with explicit initializer
    vector<int> v6(10, 1);
    // value initialization, without explicit initialization
    vector<int> v7(10);


    // case 2: string, no confusion
    vector<string> v8{"hi"};
    // vector<string> v8("hi");    // error
    vector<string> v8{10};          // list initialization fail
    vector<string> v10(10, "hi");  
    vector<string> v11{10, "hi"};   // list initialization fail
}