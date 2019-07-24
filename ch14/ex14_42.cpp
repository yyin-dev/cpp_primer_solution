#include "headers.h"

int main () {
    vector<int> vi{1000, 2000, 3000};
    greater<int> comp;
    int counter = 0;
    for(auto i : vi) {
        if ( comp(i, 2014) ) {
            ++counter;
        }
    }
    cout << counter << endl;

    vector<string> vs{"pooh", "pooh", "Pooh", "Booh"};
    equal_to<string> equal;
    for(auto s : vs) {
        if ( ! equal(s, "pooh") ) {
            cout << s << endl;
            break;
        }
    }

    multiplies<int> doub;
    for(int & i : vi) {
        cout << i << endl;
    }
    for(int & i : vi) {
        i = doub(i, 2);
        cout << i << endl;
    }
}