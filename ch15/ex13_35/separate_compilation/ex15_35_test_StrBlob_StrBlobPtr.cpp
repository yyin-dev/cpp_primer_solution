#include "ex15_35_StrBlob.h"
#include "ex15_35_StrBlobPtr.h"
#include "headers.h"

/*
g++ ex15_35_StrBlob.cpp ex15_35_StrBlobPtr.cpp ^
ex15_35_test_StrBlob_StrBlobPtr.cpp ^
-o ex15_35_test_StrBlob_StrBlobPtr

Or:
g++ ./*.cpp -o ex15_35_test_StrBlob_StrBlobPtr

ex15_35_test_StrBlob_StrBlobPtr
 */

int main() {
    StrBlob sb{"hello", "there"};
    StrBlobPtr sbp(sb, 0);
    cout << sb.front();
    cout << sb.back();

    sb.push_back("Hello!");
    cout << sb.front();
    cout << sb.back();

    cout << sbp.incre().deref();
}