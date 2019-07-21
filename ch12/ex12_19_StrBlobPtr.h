#include "headers.h"

class StrBlob;

// StrBlobPtr is a class provided for
// user of StrBlob class to access
// string elements stored in the StrBlob object
class StrBlobPtr {
   public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &sb, size_t init_idx = 0) : wptr(sb.data), curr(init_idx) {}
    string &deref();
    StrBlobPtr &incre();

   private:
    shared_ptr<vector<string>> check(size_t i, const string &msg) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const {
    auto sp = wptr.lock();
    if (!sp) {
        throw runtime_error("Memory already freed!");
    }
    if (i >= sp->size()) {
        throw out_of_range(msg);
    }

    return sp;
}

string &StrBlobPtr::deref() {
    auto p = check(curr, "dereference past the end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incre() {
    check(curr, "increment past end of StrBlob");
    ++curr;
    return *this;
}