#ifndef EX_15_35_STRBLOB_H
#define EX_15_35_STRBLOB_H

#include "headers.h"

using namespace std;

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;

   public:
    using size_type = vector<string>::size_type;

    StrBlob() : data_sp(new vector<string>) {}
    StrBlob(initializer_list<string> il)
        : data_sp(make_shared<vector<string>>(il.begin(), il.end())) {}

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
#endif