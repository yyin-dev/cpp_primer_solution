#ifndef STRBLOB_STRBLOBPTR
#define STRBLOB_STRBLOBPTR

#include "headers.h"

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
    friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);

   public:
    using size_type = vector<string>::size_type;

    StrBlob();
    StrBlob(initializer_list<string> il);

    StrBlob(const StrBlob &from) : data(make_shared<vector<string>>(*(from.data))) {}
    StrBlob &operator=(const StrBlob &rhs) {
        data = make_shared<vector<string>>(*(rhs.data));
        return *this;
    }

    size_type size() { return data->size(); }
    bool empty() { return data->empty(); }
    void push_back(const string &s) { data->push_back(s); }
    string &front();
    const string &front() const;
    string &back();
    const string &back() const;
    StrBlobPtr begin();
    StrBlobPtr end();

   private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(StrBlob::size_type i, const string &msg) const {
    if (i >= data->size()) {
        throw out_of_range(msg);
    }
}

string &StrBlob::front() {
    check(0, "front at empty StrBlob");
    return data->front();
}

const string &StrBlob::front() const {
    check(0, "front at empty StrBlob");
    return data->front();
}

string &StrBlob::back() {
    check(0, "back at empty StrBlob");
    return data->back();
}

const string &StrBlob::back() const {
    check(0, "back at empty StrBlob");
    return data->back();
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
    return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}



class StrBlobPtr {
    friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

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

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    // Referr to the same element in the same vector
    return *(lhs.wptr.lock()) == *(rhs.wptr.lock()) && lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}

#endif