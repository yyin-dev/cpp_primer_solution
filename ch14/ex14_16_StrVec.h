#include "headers.h"

class StrVec {
    friend bool operator==(const StrVec &lhs, const StrVec &rhs);
    friend bool operator!=(const StrVec &lhs, const StrVec &rhs);

   public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {
        cout << "StrVec()" << endl;
    }
    StrVec(initializer_list<string>);
    StrVec(const StrVec &);
    StrVec(StrVec &&other);
    StrVec &operator=(const StrVec &sv);
    StrVec &operator=(StrVec &&rhs);
    ~StrVec();

    size_t size() const;
    size_t capacity() const;
    string *begin() const;
    string *end() const;
    void push_back(const string &s);
    void reserve(const int new_capacity);
    void resize(const int new_size);
    string *at(const int pos);
    void info();

   private:
    allocator<string> alloc;

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
    cout << "StrVec(const StrVec &)" << endl;
    auto pair = allocate_n_copy(sv.begin(), sv.end());
    elements = pair.first;
    first_free = pair.second;
    cap = pair.second;
}

StrVec::StrVec(StrVec &&other) : elements(other.elements), first_free(other.first_free), cap(other.cap) {
    cout << "StrVec(StrVec &&)" << endl;
    other.elements = other.first_free = other.cap = nullptr;
}

StrVec::StrVec(initializer_list<string> il) {
    cout << "StrVec(initializer_list<string>" << endl;
    auto init_size = il.size();

    elements = alloc.allocate(2 * init_size);

    for (auto p = il.begin(); p != il.end(); p++) {
        alloc.construct(p - il.begin() + elements, *p);
    }
    first_free = elements + init_size;
    cap = elements + 2 * init_size;
}

StrVec &StrVec::operator=(const StrVec &sv) {
    cout << "StrVec::operator=(StrVec &). Copying resource." << endl;
    auto pair = allocate_n_copy(sv.begin(), sv.end());
    free();
    elements = pair.first;
    first_free = pair.second;
    cap = pair.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) {
    cout << "StrVec::operator=(StrVec &&). Moving resource." << endl;
    if (this != &rhs) {  // rhs is still a reference. When you dereference it, you get a pointer.
        free();
        elements = rhs.elements;
        first_free = rhs.elements;
        cap = rhs.cap;
    }

    return *this;
}

StrVec::~StrVec() {
    cout << "~StrVec()" << endl;
    free();
}

size_t StrVec::size() const { return first_free - elements; }
size_t StrVec::capacity() const { return cap - elements; }
string *StrVec::begin() const { return elements; }
string *StrVec::end() const { return first_free; }

void StrVec::push_back(const string &s) {
    possible_reallocate();
    alloc.construct(first_free++, s);
}

string *StrVec::at(const int pos) {
    return (elements + pos);
}

pair<string *, string *> StrVec::allocate_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for_each(elements, first_free, [this](const string &s) { alloc.destroy(&s); });
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
        for (auto p = first_free; p != cap; p++) {
            alloc.construct(p, "");
        }
    } else if (new_size < size()) {
        for (auto p = first_free; p != elements + new_size;) {
            alloc.destroy(--p);
        }
        first_free = elements + new_size;
    }
}

void StrVec::info() {
    cout << "size: " << size() << ", capacity: " << capacity() << " [ ";
    for (auto p = elements; p != first_free; p++) {
        cout << *p << " ";
    }
    cout << "]" << endl;
}

bool operator==(const StrVec &lhs, const StrVec &rhs) {
    if (lhs.size() != rhs.size() || lhs.capacity() != rhs.capacity()) {
        return false;
    }

    for (auto lhs_p = lhs.elements, rhs_p = rhs.elements;
         lhs_p != lhs.first_free && rhs_p != rhs.first_free;
         lhs_p++, rhs_p++) {
        if (*lhs_p != *rhs_p) {
            return false;
        }
    }

    return true;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs == rhs);
}

int main() {
    StrVec v1({"Hi", "Hello"});
    StrVec v2(v1);
    StrVec v3(std::move(v1));
}
