#include<iostream>
using namespace std;

//
//   If you have nested comment pairs, compiler gives the following error message: 
// 
//   2_comments.cpp:7:3: error: expected unqualified-id before '/' token
//   */
//    ^
// 


int main() {
    cout << "/*";
    cout << "*/";
    // cout << /* "*/" */ ;
    cout << /* "*/" /* "/*" */;
    return 0;
}