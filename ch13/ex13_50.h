#ifndef EX13_50_H
#define EX13_50_H

#include "headers.h"

class String {
    friend void print(const String& s);

   public:
    // Normal constructors
    String() : begin(nullptr), end(nullptr) { cout << "String()" << endl; };
    String(const string& s);
    String(const char* pc);

    // Copy constructor
    String(const String& s);

    // Copy assgnment operator
    String& operator=(const String& rhs);

    // move constructor
    String(String&& other);

    // move assignment
    String& operator=(String&& rhs);

    // destructor
    ~String();

    size_t length() const;

   private:
    allocator<char> alloc;
    char* begin;
    char* end;

    void free();
    pair<char*, char*> allocate_n_copy(const char* begin, const char* end);
};

String::String(const string& s) {
    cout << "String(const string&)." << endl;
    auto size = s.length();
    begin = alloc.allocate(size);
    end = uninitialized_copy(s.begin(), s.end(), begin);
}

String::String(const char* pc) {
    cout << "String(const char*)" << endl;
    int len = 0;
    auto p = pc;
    while (*p != '\0') {
        len++;
        p++;
    }

    auto pair = allocate_n_copy(pc, pc + len);
    begin = pair.first;
    end = pair.second;
}

String::String(const String& s) {
    cout << "String(const String& s).";
    print(s);
    cout << ", Copying resource." << endl;
    auto pair = allocate_n_copy(s.begin, s.end);
    begin = pair.first;
    end = pair.second;
}

String& String::operator=(const String& rhs) {
    cout << "operator=(const String &)." << endl;

    // construction
    auto new_begin = alloc.allocate(rhs.length());
    auto new_end = uninitialized_copy(rhs.begin, rhs.end, new_begin);

    // destuction
    free();

    begin = new_begin;
    end = new_end;
    return *this;
}

String::String(String&& other) : begin(other.begin), end(other.end) {
    cout << "String(String &&).";
    print(*this);
    cout << ", Moving reference." << endl;
    other.begin = other.end = nullptr;
}

String& String::operator=(String&& rhs) {
    cout << "String::operator=(String &&)" << endl;
    if (this != &rhs) {
        free();
        begin = rhs.begin;
        end = rhs.end;
    }

    return *this;
}

String::~String() {
    cout << "~String() " ;
    print(*this);
    cout << endl;
    free();
}

size_t String::length() const { return end - begin; }

void String::free() {
    for_each(begin, end, [this](char& c) { alloc.destroy(&c); });
    alloc.deallocate(begin, length());
}

pair<char*, char*> String::allocate_n_copy(const char* b, const char* e) {
    auto size = e - b;
    auto begin = alloc.allocate(size);
    auto end = uninitialized_copy(b, e, begin);
    return {begin, end};
}

void print(const String& s){
    cout << "\"";
    for (auto p = s.begin; p != s.end; p++) {
        cout << *p;
    }
    cout << "\", " << s.length();
}

#endif