#include "headers.h"

// Note: template definition should be provided in the header file.
// The definition is required at compiling time, instead of linking time.

template <typename T>
class BlobPtr;

template <typename T>
class Blob {
    friend class BlobPtr<T>;  // only friend with BlobPtr with the same type

   public:
    typedef typename vector<T>::size_type size_type;

    Blob<T>() : data(new vector<T>){};
    Blob<T>(initializer_list<T> il) : data(make_shared<vector<T>>(il)) {}
    
    template <typename iter_T>
    Blob(const iter_T& b, const iter_T& e) : data(new vector<T>(b, e)) {}


    size_type size() { return data->size(); }
    bool empty() { return data->empty(); }
    void push_back(const T& ele) { data->push_back(ele); }
    void push_back(T&& ele) { data->push_back(std::move(ele)); }
    void pop_back();
    T& back();
    T& operator[](const size_type idx);

   private:
    shared_ptr<vector<T>> data;
    void check(size_type index, const string& err_msg);
};

template <typename T>
void Blob<T>::pop_back() {
    check(0, "Cannot call pop_back() on empty Blob!");
    data->pop_back();
}

template <typename T>
T& Blob<T>::back() {
    check(0, "Cannot call back() on empty Blob!");
    return data->back();
}

template <typename T>
T& Blob<T>::operator[](const size_type idx) {
    check(idx, "Subscripting out of range!");
    return (*data)[idx];
}

template <typename T>
void Blob<T>::check(size_type idx, const string& err_msg) {
    if (idx >= size()) {
        throw out_of_range(err_msg);
    }
}


int main() {
    vector<int> v{1, 2, 3};
    Blob<int> b(v.begin(), v.end());
    cout << b[0] << endl;
}