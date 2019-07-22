#ifndef EX_13_31_H
#define EX_13_31_H

#include "headers.h"

class HasPtr {  // value like
    friend void swap(HasPtr &lhs, HasPtr &rhs);

   public:
    // normal constructor
    HasPtr(const string &s = string()) : ps(new string(s)), i(i) {}

    // copy constructor
    HasPtr(const HasPtr &rhs) : ps(new string(*(rhs.ps))), i(rhs.i) {}

    // copy assignment operator
    HasPtr &operator=(const HasPtr &rhs) {
        auto new_ps = new string(*(rhs.ps));
        delete ps;
        ps = new_ps;
        i = rhs.i;
        return *this;
    }

    ~HasPtr();

    bool operator<(const HasPtr &rhs) const {
        return *ps < *(rhs.ps);
    }

    void print() {
        cout << *ps << " ";
    }

   private:
    string *ps;
    int i;
};

HasPtr::~HasPtr() {
    delete ps;
}

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.i, rhs.i);
    swap(lhs.ps, rhs.ps);
    cout << "swappd!" << endl;
}

#endif