#include "ex15_35_StrBlobPtr.h"
#include "ex15_35_StrBlob.h"
#include "headers.h"

using namespace std;


string &StrBlobPtr::deref() {
    auto sp = check(curr, "Reference out of range");
    return (*sp)[curr];
}


StrBlobPtr& StrBlobPtr::incre() {
    check(++curr, "Reference past the end of StrBlob");
    return *this;
}


/*
weak_ptr API:
weak_ptr<T> wp(sp); // returns a weak_ptr pointing to the same object as shared_ptr sp.
w = p;              // p can be a shared_ptr or weak_ptr
w.reset();          // makes w null
w.use_count();      // The number of shared_ptrs sharing ownership wit w
w.expired();        // returns true if w.use_count() returns 0;
w.lock();           // returns a nullptr if w.expired() is true. Otherwise return a
                    // shared_ptr pointing to the same object as w.
 */

shared_ptr<vector<string>> StrBlobPtr::check(StrBlob::size_type idx, const string& error_msg) const {
    auto sp = wptr.lock();
    if (!sp) {
        throw runtime_error("StrBlobPtr Not bound to a StrBlob!");
    }
    if (idx > sp->size()) {
        throw out_of_range(error_msg);
    }

    return sp;  // sp is a shared_ptr
}