#include "headers.h"

// https://stackoverflow.com/questions/18792565/declare-template-friend-function-of-template-class
// To define template function as a friend of a template class:
// 1. Forward declare Vec as a template. As later forward declare of operator<<, which takes a Vec<T>;
// 2. Forward declare operator<< as a template.
// 3. Declare operator<< as a friend inside the class, add <T>!
// 4. Define operator<< outside class. 

template<typename T>
class Vec;

template<typename T>
ostream &operator<< (ostream& os, Vec<T> vec);


template <typename T>
class Vec {
   public:
    friend ostream &operator<<<T>(ostream &os, Vec<T> vec);

    Vec<T>() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vec<T>(const Vec<T> &);
    Vec<T>(initializer_list<T> il);

    Vec<T> &operator=(const Vec<T> &sv);

    ~Vec<T>();

    size_t size() const;
    size_t capacity() const;
    T *begin() const;
    T *end() const;
    void push_back(const T &s);
    void reserve(const int new_capacity);
    void resize(const int new_size);

   private:
    allocator<T> alloc;

    pair<T *, T *> allocate_n_copy(const T *b, const T *e);
    void free();
    void possible_reallocate();
    void reallocate();
    void reallocate_by_capacity(const int new_capacity);

    T *elements;
    T *first_free;
    T *cap;
};

template <typename T>
Vec<T>::Vec(const Vec<T> &sv) {  // Here you should use Vec<T>::Vec(...) instead of Vec<T>::Vec<T>(...) !!!
    auto pair = allocate_n_copy(sv.begin(), sv.end());
    elements = pair.first;
    first_free = pair.second;
    cap = pair.second;
}

template <typename T>
Vec<T>::Vec(initializer_list<T> il) {  // Here you should use Vec<T>::Vec(...) instead of Vec<T>::Vec<T>(...) !!!
    auto pair = allocate_n_copy(il.begin(), il.end());
    elements = pair.first;
    first_free = cap = pair.second;
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec<T> &sv) {
    auto pair = allocate_n_copy(sv.begin(), sv.end());
    free();
    elements = pair.first;
    first_free = pair.second;
    cap = pair.second;
    return *this;
}

template <typename T>
Vec<T>::~Vec<T>() { free(); }

template <typename T>
size_t Vec<T>::size() const { return first_free - elements; }

template <typename T>
size_t Vec<T>::capacity() const { return cap - elements; }

template <typename T>
T *Vec<T>::begin() const { return elements; }

template <typename T>
T *Vec<T>::end() const { return first_free; }

template <typename T>
void Vec<T>::push_back(const T &s) {
    possible_reallocate();
    alloc.construct(first_free++, s);
}

template <typename T>
pair<T *, T *> Vec<T>::allocate_n_copy(const T *b, const T *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free() {
    if (elements) {
        for (auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
void Vec<T>::possible_reallocate() {
    if (size() == capacity()) {
        reallocate();
    }
}

template <typename T>
void Vec<T>::reallocate_by_capacity(const int new_capacity) {
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

template <typename T>
void Vec<T>::reallocate() {  // called when size == capacity, cap == first_free
    auto new_capacity = capacity() ? 2 * capacity() : 1;
    reallocate_by_capacity(new_capacity);
}

template <typename T>
void Vec<T>::reserve(const int new_capacity) {
    if (new_capacity > capacity()) {
        reallocate_by_capacity(new_capacity);
    }
}

template <typename T>
void Vec<T>::resize(const int new_size) {
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

template <typename T>
ostream &operator<<(ostream &os, Vec<T> vec) {
    cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << ", [ ";
    for (auto p = vec.elements; p != vec.first_free; p++) {
        cout << *p << " ";
    }
    cout << "]";
    return os;
}

int main() {
    Vec<string> v_string{"Hello", "world"};
    Vec<int> v_int{1, 2, 3};
    cout << v_string << endl;
    cout << v_int << endl;
}