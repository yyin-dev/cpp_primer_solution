#ifndef EX_15_35_STRBLOBPTR_H
#define EX_15_35_STRBLOBPTR_H

#include "ex15_35_StrBlob.h"
#include "headers.h"

using namespace std;

class StrBlobPtr {
    friend class StrBlob;

   public:
    StrBlobPtr() : curr(0){};
    StrBlobPtr(StrBlob sb, StrBlob::size_type idx) : wptr(sb.data_sp), curr(idx) {}
    string& deref();
    StrBlobPtr& incre();

   private:
    weak_ptr<vector<string>> wptr;
    shared_ptr<vector<string>> check(StrBlob::size_type idx, const string& error_msg) const;
    // This can be a common technique when using weak_ptr: normally we do not want the 
    // existence of a pointer to affect the lifespan of the object it points to. However,
    // when we are performing something on it, we want to be sure that the object is not
    // deleted, so we need a shared_ptr.
    StrBlob::size_type curr;
};
#endif