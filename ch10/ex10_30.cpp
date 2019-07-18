#include "headers.h"

int main() {
    istream_iterator<int> is_iter(cin), eof;
    ostream_iterator<int> os_iter(cout);

    vector<int> vec(is_iter, eof);
    sort(vec.begin(), vec.end());
    copy(vec.cbegin(), vec.cend(), os_iter);
}
