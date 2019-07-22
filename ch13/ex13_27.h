#include "headers.h"

class HasPtr {  // pointer like
   public:
    // normal constructor
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new int(1)) {}

    // copy constructor
    HasPtr(const HasPtr &rhs) : ps(rhs.ps), i(rhs.i), use(rhs.use) { ++*use; }

    // copy assignment operator
    HasPtr &operator=(const HasPtr &rhs) {
        auto new_ps = new string(*(rhs.ps));
        ++*rhs.use;
        if (--*use == 0) {
            delete ps;
            delete use;
        }
        ps = new_ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }

    ~HasPtr() {
        if (--*use == 0) {
            delete ps;
            delete use;
        }
    }

   private:
    string *ps;
    int i;
    int *use;
};

HasPtr::~HasPtr() {
    delete ps;
}
