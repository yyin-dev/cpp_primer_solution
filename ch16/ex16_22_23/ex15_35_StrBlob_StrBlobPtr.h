#ifndef EX_15_35_STRBLOB_STRBLOBPTR_H
#define EX_15_35_STRBLOB_STRBLOBPTR_H

/* Taken from ex 13.35 */

/*
ex15_35_StrBlob.h, ex15_35_StrBlobPtr.h, ex15_35_StrBlob.cpp, ex15_35_StrBlobPtr.cpp and
ex15_35_test_StrBlob_StrBlobPtr.cpp are good illustration for separate compilation. Though one thing
should be noted is that, we could also group StrBlobPtr and StrBlob classes together, the reason is
that both classes are closely related with each other: StrBlob would be hard to use without 
StrBlobPtr, and StrBlobPtr would be meaningless without StrBlob. 

Thus, for convenience and the reasons mentioned above, we use one file for 2 classes in this program.
Though you should understand how separate compilation works and the motivation behind. 

StrBlob class is just a wrapper for vector<string>, to illustrate the usage of smart pointers. 
Do not think too hard about why smart pointers are used in the code here, so of them are just for
illustration purpose. 
 */

#include "headers.h"
#include "ex16_22_DebugDeleter.h"

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;

   public:
    using size_type = vector<string>::size_type;

    StrBlob() : data_sp(new vector<string>, DebugDeleter()) {}
    StrBlob(initializer_list<string> il)
        : data_sp(shared_ptr<vector<string>>(new vector<string>(il.begin(), il.end()), DebugDeleter())) {}

    size_type size();
    bool empty();
    void push_back(const string& s);
    const string& front() const;
    const string& back() const;
    string& front();
    string& back();
    StrBlobPtr begin();
    StrBlobPtr end();

   private:
    shared_ptr<vector<string>> data_sp;
};

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
    StrBlob::size_type curr;
};

#endif