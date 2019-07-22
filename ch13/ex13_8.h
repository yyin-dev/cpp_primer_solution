#include "headers.h"

class HasPtr {
   public:
    // normal constructor
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}

    // copy constructor
    HasPtr(const HasPtr &rhs) : ps(new string(*(rhs.ps))), i(rhs.i) {}

    // copy assignment operator
    HasPtr &operator=(const HasPtr &rhs) {
        delete ps;
        ps = new string(*(rhs.ps));
        i = rhs.i;
        return *this;
    }

   private:
    string *ps;
    int i;
};
