#include <iostream>
#include <string>

using namespace std;

istream& read_until_eof(istream& is){
    char c;
    while ( is >> c ){
        cout << c;
    }

    cout << endl;
    cout << is.rdstate() << endl;
    cout << is.good() << endl;
    cout << is.bad() << endl;
    cout << is.eof() << endl;
    cout << is.fail() << endl << endl;

    is.clear();
    return is;
}

int main() {
    read_until_eof(cin);
    cout << cin.rdstate() << endl;
}