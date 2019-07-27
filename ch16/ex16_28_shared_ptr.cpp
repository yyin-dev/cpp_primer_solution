#include "headers.h"

class Debug_deleter {
   public:
    Debug_deleter(ostream& os = cerr) : os(os) {}
    template <typename T>
    void operator()(T* ptr) {
        os << "Deleting unique_ptr." << endl;
        delete ptr;
    }

   private:
    ostream& os;
};

template <typename T>
class my_shared_ptr {
    friend void swap(my_shared_ptr<T> & msp1, my_shared_ptr<T> & msp2) {
        msp1.swap(msp2);
    }

   public:
    // Default constructor
    my_shared_ptr() : n_ptr(new int(1)), p(nullptr) {
        cout << "my_shared_ptr()" << endl;
    }

    // Constructor that takes a pointer from placement new
    my_shared_ptr(T* p) : n_ptr(new int(1)), p(p) {
        cout << "my_shared_ptr(const T* p)" << endl;
    }

    // Constructor that takes a pointer from placement new, AND a callable deleter
    // 7.27 TODO: Here we are passing a reference to a function object, then we
    // use the address-of operator to store as a member.
    // However, I cannot find a way to pass in pointer to function-object.
    // Function-object is also called "functor".
    // 7.28: There's no reason to store a pointer to functor though.
    // Using a functor directly seem to be good enough.
    my_shared_ptr(T* p, const function<void(T*)>& p_del)
        : n_ptr(new int(1)), p(p), p_del(p_del) {
        cout << "my_shared_ptr(T* p, const function<void(T*)>& p_del)" << endl;
    }

    // Constructor that assums the ownership from a unique_ptr
    my_shared_ptr(unique_ptr<T> up) : n_ptr(new int(1)) {
        // u.release(): relinquish the control of the pointer held by u and
        // returns the pointer. Set u to null.
        p = up.release();
    }

    // Copy constrcutor
    my_shared_ptr(const my_shared_ptr&);

    // Variant of the copy constructor
    my_shared_ptr(const my_shared_ptr&, const function<void(T*)>& p_del);

    // Copu assignment operator
    my_shared_ptr& operator=(const my_shared_ptr<T>&);

    // Destructor
    ~my_shared_ptr() {
        cout << "~my_shared_ptr()" << endl;
        free();
    }

    T& operator*() const {
        return *p;
    }

    T* operator->() const {
        return p;
    }

    T* get() const {
        return p;
    }

    void swap(my_shared_ptr<T>& other) {
        auto other_n_ptr = other.n_ptr;
        auto other_p = other.p;
        other.n_ptr = n_ptr;
        other.p = p;

        n_ptr = other_n_ptr;
        p = other_p;
    }

    bool unique() { return use_count() == 1; }
    int use_count() {
        if (n_ptr) {
            return *n_ptr;
        }
        return -1;
    }

    void reset() {  // Do not free object if shared by other
        if (--*n_ptr == 0) {
            free();
        } else {
            p = nullptr;
            n_ptr = nullptr;
        }
    }

    void reset(T* p) {
        reset();
        *n_ptr = 1;
        this->p = p;
    }

    void reset(T* p, const function<void(T*)>& p_del) {
        this->p_del = p_del;
        reset(p);
    }

   private:
    void free();

    int* n_ptr;
    T* p;
    const function<void(T*)> p_del;
};

template <typename T>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr& other)
    : n_ptr(&++*(other.n_ptr)), p(other.p) {
    cout << "my_shared_ptr(const my_shared_ptr&). Counter: " << *n_ptr << endl;
}

template <typename T>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr& other, const function<void(T*)>& p_del)
    : n_ptr(&++*(other.n_ptr)), p(other.p), p_del(&p_del) {
    cout << "my_shared_ptr(const my_shared_ptr&, const function<void(T*)>&). Counter: " << *n_ptr << endl;
}

template <typename T>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(const my_shared_ptr<T>& rhs) {
    cout << "my_shared_ptr<T>::operator=(const my_shared_ptr<T>&)" << endl;
    auto new_n_ptr = &(++*(rhs.n_ptr));
    auto new_p = rhs.p;

    if (--*n_ptr == 0) {
        free();
    }

    n_ptr = new_n_ptr;
    p = new_p;
    return *this;
}

template <typename T>
void my_shared_ptr<T>::free() {
    // Should be deleted separately !!!
    if (p_del) {
        p_del(p);
    } else {
        delete p;
    }

    delete n_ptr;

    n_ptr = nullptr;
    p = nullptr;
    cout << "Resource freed!" << endl;
}

int main() {
    // Test copy constructor and copy assignment
    my_shared_ptr<int> sp1;
    my_shared_ptr<int> sp2(sp1);
    my_shared_ptr<int> sp3;
    sp3 = sp1;

    // Test with placement new
    my_shared_ptr<int> test_new(new int(10));

    // Test deleter
    my_shared_ptr<int> test_del2(new int(10), Debug_deleter());

    // Test operator*
    my_shared_ptr<int> test_deref(new int(10));
    cout << *test_deref << endl;
    *test_deref = 20;
    cout << *test_deref << endl;

    // Test operator->
    my_shared_ptr<string> test_arrow(new string("hello world!"));
    cout << test_arrow->length() << endl;

    // Test get()
    my_shared_ptr<string> test_get(new string("Hello again!"));
    auto p = test_get.get();
    cout << *p << endl;

    // Test swap(my_shared_ptr<T> &) and swap(my_shared_ptr<T> &, my_shared_ptr<T>&)
    my_shared_ptr<string> msp1(new string("A"));
    my_shared_ptr<string> msp2(new string("B"));
    my_shared_ptr<string> msp3(msp1);
    cout << *msp1 << " " << *msp2 << endl;
    cout << msp1.use_count() << " " << msp2.use_count() << endl;
    cout << *msp3 << endl;
    msp1.swap(msp2);
    cout << *msp1 << " " << *msp2 << endl;
    cout << msp1.use_count() << " " << msp2.use_count() << endl;
    cout << *msp3 << endl;
    cout << endl;
    swap(msp1, msp2);
    cout << *msp1 << " " << *msp2 << endl;
    cout << msp1.use_count() << " " << msp2.use_count() << endl;
    cout << *msp3 << endl;

    cout << "----------" << endl;
}

// When you want a object constructed with default constructor in C++,
// use ClassName identifier; instead of ClassName identifier();
// https://stackoverflow.com/questions/11963849/c-constructor-not-being-called