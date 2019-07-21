#include "headers.h"

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;

   public:
    using size_type = vector<string>::size_type;

    StrBlob();
    StrBlob(initializer_list<string> il);

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