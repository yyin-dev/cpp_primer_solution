#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    // string str;
    // while ( cin >> str ){
    //     cout << str << " ";
    // }

    string line;
    cout << "getline(cin, line) reads the stream up to the first newline character \'\\n\' (inclusive)." << endl;
    cout << "Then it stores what is read in to the string argument, EXCLUDING the \'\\n\' character." << endl;
    cout << "Thus we need to manually add a endl at the end of cout." << endl << endl;
    
    cout << "Enter a whole new line and will print it out: " << endl;
    while (getline(cin, line)) {
        if ( !line.empty()){
            cout << line << " | Length: " << line.size() << endl;
        }
    }
}