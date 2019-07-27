#ifndef EX13_39_H
#define EX13_39_H

#include "headers.h"

class StrVec {
   public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);

    StrVec &operator=(const StrVec &sv);

    ~StrVec();
    
    size_t size() const;
    size_t capacity() const;
    string *begin() const;
    string *end() const;
    void push_back(const string &s);
    void reserve(const int new_capacity);
    void resize(const int new_size);
    void info();

   private:
    allocator<string> alloc; 
    // By design this should be made static, but 
    // the compiler generats error when did so. So we
    // keep it as non-static.

    pair<string *, string *> allocate_n_copy(const string *b, const string *e);
    void free();
    void possible_reallocate();
    void reallocate();
    void reallocate_by_capacity(const int new_capacity);

    string *elements;
    string *first_free;
    string *cap;
};

StrVec::StrVec(const StrVec &sv) {
    auto pair = allocate_n_copy(sv.begin(), sv.end());
    elements = pair.first;
    first_free = pair.second;
    cap = pair.second;
}

StrVec &StrVec::operator=(const StrVec &sv) {
    auto pair = allocate_n_copy(sv.begin(), sv.end());
    free();
    elements = pair.first;
    first_free = pair.second;
    cap = pair.second;
    return *this;
}

StrVec::~StrVec() { free(); }

size_t StrVec::size() const { return first_free - elements; }
size_t StrVec::capacity() const { return cap - elements; }
string *StrVec::begin() const { return elements; }
string *StrVec::end() const { return first_free; }

void StrVec::push_back(const string &s) {
    possible_reallocate();
    alloc.construct(first_free++, s);
}

pair<string *, string *> StrVec::allocate_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::possible_reallocate() {
    if (size() == capacity()) {
        reallocate();
    }
}

void StrVec::reallocate_by_capacity(const int new_capacity) {
    auto new_elements = alloc.allocate(new_capacity);

    const size_t origin_size = size();
    for (size_t pos = 0; pos < size(); pos++) {
        alloc.construct(new_elements + pos, std::move(*(elements + pos)));
    }

    free();
    elements = new_elements;
    first_free = new_elements + origin_size;
    cap = new_elements + new_capacity;
}

void StrVec::reallocate() {  // called when size == capacity, cap == first_free
    auto new_capacity = capacity() ? 2 * capacity() : 1;
    reallocate_by_capacity(new_capacity);
}

void StrVec::reserve(const int new_capacity) {
    if (new_capacity > capacity()) {
        reallocate_by_capacity(new_capacity);
    }
}

void StrVec::resize(const int new_size) {
    if (new_size > size()) {
        reallocate_by_capacity(new_size);
        for(auto p = first_free; p != cap; p++){
            alloc.construct(p, "");
        }
    } else if (new_size < size()) {
        for(auto p = first_free; p != elements + new_size;){
            alloc.destroy(--p);
        }
        first_free = elements + new_size;
    }
}

void StrVec::info() {
    cout << "size: " << size() << ", capacity: " << capacity() << " [ ";
    for(auto p = elements; p != first_free; p++){ cout << *p << " "; }
    cout << "]" << endl;
}

#endif