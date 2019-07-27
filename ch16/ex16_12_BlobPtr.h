#ifndef EX_16_12_BLOB_PTR_H
#define EX_16_12_BLOB_PTR_H

#include "ex16_12_Blob.h"
#include "headers.h"

template <typename T>
class BlobPtr {
   public:
    typedef typename Blob<T>::size_type size_type;
    BlobPtr<T>() = default;
    BlobPtr<T>(const Blob<T>& blob, size_type curr = 0) : wptr(blob.data), curr(curr) {}

    T& operator*();
    BlobPtr<T>& operator++();
    BlobPtr<T>& operator--();

   private:
    weak_ptr<vector<T>> wptr;
    shared_ptr<vector<T>> check(size_type idx, const string& err_msg);
    size_type curr;
};

template <typename T>
T& BlobPtr<T>::operator*() {
    auto sp = check(curr, "Dereference out of range of Blob!");
    return (*sp)[curr];
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
    check(++curr, "Increment past the end of the Blob!");
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
    check(--curr, "Decrement past the begin of the Blob!");
    return *this;
}

template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_type idx, const string& err_msg) {
    auto sp = wptr.lock();
    if (!sp) {
        throw runtime_error("BlobPtr not bound to Blob!");
    }

    if (idx >= sp->size()) {
        throw out_of_range(err_msg);
    }
    return sp;
}

#endif