#include "ex15_35_StrBlob.h"
#include "ex15_35_StrBlobPtr.h"
#include "headers.h"

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