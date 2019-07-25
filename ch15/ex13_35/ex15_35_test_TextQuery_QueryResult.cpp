#include "headers.h"
#include "ex15_35_TextQuery_QueryResult.h"

/*
g++ ex15_35_test_TextQuery_QueryResult.cpp ^
ex15_35_TextQuery_QueryResult.cpp ^
ex15_35_StrBlob_StrBlobPtr.cpp ^
-o ex15_35_test_TextQuery_QueryResult

ex15_35_test_TextQuery_QueryResult
 */

// int main() {
//     ifstream ifs("./headers.h");
//     TextQuery tq(ifs);
//     while(true) {
//         string input;
//         cout << "Please enter a word for query, or 'q' to quit: ";
//         cin >> input;
//         if ( input == "q") {
//             cout << "Quit.";
//             break;
//         } else {
//             cout << tq.query(input);
//         }
//     }
// }