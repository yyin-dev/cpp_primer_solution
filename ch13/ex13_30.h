#ifndef EX_13_30_H
#define EX_13_30_H

#include "headers.h"

class HasPtr {  // value like
    friend void swap(HasPtr &lhs, HasPtr &rhs);

   public:
    // normal constructor
    HasPtr(const int i, const string &s = string()) : ps(new string(s)), i(i) {}

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

    void print() {
        cout << *ps << " " << i << endl;
    }

   private:
    string *ps;
    int i;
};

HasPtr::~HasPtr() {
    delete ps;
}

void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.i, rhs.i);
    swap(lhs.ps, rhs.ps);
    cout << "swappd!" << endl;
}

#endif