#include "headers.h"

class ConstStrBlobPtr;

class StrBlob {
    friend class ConstStrBlobPtr;

   public:
    using size_type = vector<string>::size_type;

    StrBlob();
    StrBlob(initializer_list<string> il);

    size_type size() const{ return data->size(); }
    bool empty() { return data->empty(); }
    void push_back(const string &s) { data->push_back(s); }
    string &front();
    const string &front() const;
    string &back();
    const string &back() const;
    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;

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

// StrBlobPtr is a class provided for
// user of StrBlob class to access
// string elements stored in the StrBlob object
class ConstStrBlobPtr {
   public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob &sb, size_t init_idx = 0) : wptr(sb.data), curr(init_idx) {}
    string &deref();
    ConstStrBlobPtr &incre();

   private:
    const shared_ptr<vector<string>> check(size_t i, const string &msg) const;
    const weak_ptr<vector<string>> wptr;
    size_t curr;
};

const shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const {
    auto sp = wptr.lock();
    if (!sp) {
        throw runtime_error("Memory already freed!");
    }
    if (i >= sp->size()) {
        throw out_of_range(msg);
    }

    return sp;
}

string &ConstStrBlobPtr::deref() {
    auto p = check(curr, "dereference past the end");
    return (*p)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incre() {
    check(curr, "increment past end of StrBlob");
    ++curr;
    return *this;
}

ConstStrBlobPtr StrBlob::begin() const {
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const{
    return ConstStrBlobPtr(*this, data->size());
}