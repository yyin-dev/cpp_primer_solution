#include "ex12_30_QueryResult.h"
#include "ex12_30_TextQuery.h"
#include "headers.h"

int main() {
    TextQuery tq = TextQuery();
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