#include "ex12_27_QueryResult_wo_sharedptr.h"
#include "ex12_27_TextQuery_wo_sharedptr.h"
#include "headers.h"

int main() {
    TextQuery tq;
    while(true){
        string input;
        cout << "Enter the word for query, or enter 'q' to exit: ";
        if( cin >> input && input.length() > 0 && input != "q"){
            print(cout , tq.query(input)) << endl;
        } else {
            cout << "Exit." << endl;
            break;
        }
    }
}