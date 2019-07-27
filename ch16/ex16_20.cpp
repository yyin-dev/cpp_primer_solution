#include "headers.h"

template <typename container_T>
ostream& print(ostream& os, const container_T& container) {
    typedef typename container_T::const_iterator const_iterator_type;

    for (const_iterator_type iter = container.cbegin(); iter != container.cend(); iter++) {
        os << *iter << " ";
    }
    return os;
}

int main() {
    vector<int> v_int{1, 2, 3};
    list<int> l_int{1, 3, 5};
    print(cout, v_int) << endl;
    print(cout, l_int) << endl;
}