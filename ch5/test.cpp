#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s, previous;
    bool repeated = false;
    while (cin >> s) {
        if (s == previous && !s.empty() && isupper(s[0]) )  {
            repeated = true;
            break;
        } else {
            previous = s;
        }
    }

    if (repeated) {
        cout << s << " is repeated!" << endl;
    } else {
        cout << "No word was repeated!" << endl;
    }
    return 0;
}