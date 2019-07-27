#include "headers.h"
#include "ex15_35_StrBlob_StrBlobPtr.h"
#include "ex15_35_TextQuery_QueryResult.h"

/*
g++ ./*.cpp -o ex16_22

ex16_22
 */

int main() {
    ifstream ifs("./headers.h");
    TextQuery tq(ifs);
    cout << tq.query("#include");
    /*
    In the program, one set of shared_ptrs are used by StrBlob class + StrBlobPtr class, another
    set is used by TextQuery and QueryResult class. The instantiation of a TextQuery object creates
    a shared_ptr<StrBlob> by TextQuery, and the StrBlob in turn creats a shared_ptr<vector<string>>.
    Both of them are deleted when the program terminates. 
     */
}

