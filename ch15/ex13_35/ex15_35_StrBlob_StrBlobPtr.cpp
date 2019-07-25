#include "headers.h"
#include "ex15_35_StrBlob_StrBlobPtr.h"

using namespace std;

StrBlob::size_type StrBlob::size() {
    return data_sp->size();
}

bool StrBlob::empty() {
    return data_sp->empty();
}

void StrBlob::push_back(const string& s) {
    data_sp->push_back(s);
}

const string& StrBlob::front() const {
    return *(data_sp->begin());
}

const string& StrBlob::back() const {
    return *(data_sp->end());
}

string& StrBlob::front() {
    return data_sp->front();
}

string& StrBlob::back() {
    return data_sp->back();
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this, 0);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, size());
}

/////////////////////////////////////////////////////////////////////////////////////////////////

string& StrBlobPtr::deref() {
    auto sp = check(curr, "Reference out of range");
    return (*sp)[curr];
}

StrBlobPtr& StrBlobPtr::incre() {
    check(++curr, "Reference past the end of StrBlob");
    return *this;
}

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

// Test for the two classes:
// 
// int main() {
//     StrBlob sb{"hello", "there"};
//     StrBlobPtr sbp(sb, 0);
//     cout << sb.front();
//     cout << sb.back();

//     sb.push_back("Hello!");
//     cout << sb.front();
//     cout << sb.back();

//     cout << sbp.incre().deref();
// }