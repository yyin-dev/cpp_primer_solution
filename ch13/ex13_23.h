#include "headers.h"

class HasPtr { // value like
   public:
    // normal constructor
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}

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

    ~HasPtr() { }

   private:
    string *ps;
    int i;
};

HasPtr::~HasPtr() {
    delete ps;  
    // need to free the memory manually, as is dynamically allocated 
    // and is not smart pointer
}
