#include "headers.h"

int main() {
    ifstream ifs("./headers.h");
    istream_iterator<string> is_iter(ifs), eof;
    vector<string> vec(is_iter, eof);
    for (auto iter = vec.cbegin(); iter != vec.cend(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}
