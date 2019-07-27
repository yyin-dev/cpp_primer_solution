#include "headers.h"

template <typename container_T>
ostream& print(ostream& os, const container_T& container) {
    typedef typename container_T::size_type size_type;

    auto ptr = container.cbegin();
    for (size_type i = 0; i < container.size(); ptr++, i++) {
        os << *ptr << " ";
    }
    return os;
}

int main() {
    vector<int> v_int{1, 2, 3};
    list<int> l_int{1, 3, 5};
    print(cout, v_int) << endl;
    print(cout, l_int) << endl;
}