

#include "headers.h"

class HasPtr {  // value like
    friend void swap(HasPtr &lhs, HasPtr &rhs);

   public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(i) {}

    HasPtr(const HasPtr &rhs);
    HasPtr &operator=(const HasPtr &rhs);

    HasPtr(HasPtr &&other);
    HasPtr &operator=(HasPtr &&rhs);

#ifdef combined
    HasPtr &operator=(HasPtr rhs);
#endif

    ~HasPtr();

    bool operator<(const HasPtr &rhs) const;
    void print();

   private:
    string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr &rhs) : ps(new string(*(rhs.ps))),
                                    i(rhs.i) {}

/*
Copy assignment:
1. Make a new copy of string;
2, Delete original string;
3. Update ps and i.

Compared with this, copy and swap:
1 additional copy of int;
2 additional swaps, one of string and one of int;
 */
HasPtr &HasPtr::operator=(const HasPtr &rhs) {
    auto new_ps = new string(*(rhs.ps));
    delete ps;
    ps = new_ps;
    i = rhs.i;
    return *this;
}

HasPtr::HasPtr(HasPtr &&other) : ps(other.ps), i(other.i) {
    other.ps = nullptr;
}

/*
Move assignment(if not to self):
1. Delete original string;
2. Update ps and i;
3. Make the moved-from object has nullptr;

Compared with this, copy and swap:
Makes one extra copy.
 */
HasPtr &HasPtr::operator=(HasPtr &&rhs) {
    if (this != &rhs) {
        delete ps;

        ps = rhs.ps;
        i = rhs.i;
        
        rhs.ps = nullptr;
    }
    return *this;
}

/*
Copy and swap. 
For copy:
1. Make a copy: nonreference parameter type.
    This involves: 
    Make a copy of the HasPtr object. 
2. Swap this with rhs:
    Swap string;
    Swap int;
3. Cleanup before return:
    Delete original string.
 */
#ifdef combined
HasPtr &HasPtr::operator=(HasPtr rhs) {
    swap(*this, rhs);
    return *this;
}
#endif

HasPtr::~HasPtr() {
    delete ps;
}

bool HasPtr::operator<(const HasPtr &rhs) const {
    return *ps < *(rhs.ps);
}

void HasPtr::print() {
    cout << *ps << " ";
}

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.i, rhs.i);
    swap(lhs.ps, rhs.ps);
    cout << "swappd!" << endl;
}

int main() {
    HasPtr hp1("A"), hp2;
    hp2 = hp1;
}