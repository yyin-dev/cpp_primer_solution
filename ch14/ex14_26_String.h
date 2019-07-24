#ifndef EX13_50_H
#define EX13_50_H

#include "headers.h"

class String {
    friend ostream& operator<<(ostream& os, const String& s);
    friend bool operator==(const String& lhs, const String& rhs);
    friend bool operator!=(const String& lhs, const String& rhs);

    friend bool operator<(const String& lhs, const String& rhs);

   public:
    String() : begin(nullptr), end(nullptr) { cout << "String()" << endl; };
    String(const string& s);
    String(const char* pc);

    String(const String& s);
    String(String&& other);

    String& operator=(const String& rhs);
    String& operator=(String&& rhs);

    ~String();

    size_t length() const;
    char& operator[](const size_t idx);
    const char& operator[](const size_t idx) const;

   private:
    allocator<char> alloc;
    char* begin;  // to the first char
    char* end;    // one past the last char

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
    cout << s;
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
    cout << *this;
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
    cout << "~String() ";
    cout << *this;
    cout << endl;
    free();
}

size_t String::length() const { return end - begin; }

char& String::operator[](const size_t idx) {
    if (idx > length()) {
        cout << "Subscribing out of range! Return the first element." << endl;
        return *begin;
    }
    return *(begin + idx);
}

const char& String::operator[](const size_t idx) const {
    if (idx > length()) {
        cout << "Subscribing out of range! Return the first element." << endl;
        return *begin;
    }
    return *(begin + idx);
}

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

ostream& operator<<(ostream& os, const String& s) {
    os << "\"";
    for (auto p = s.begin; p != s.end; p++) {
        os << *p;
    }
    os << "\", " << s.length();
    return os;
}

bool operator==(const String& lhs, const String& rhs) {
    for (auto lhs_p = lhs.begin, rhs_p = rhs.begin;
         lhs_p != lhs.end && rhs_p != rhs.end;
         lhs_p++, rhs_p++) {
        if (*lhs_p != *rhs_p) {
            return false;
        }
    }
    return true;
}

bool operator!=(const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}

bool operator<(const String& lhs, const String& rhs) {
    // https://www.geeksforgeeks.org/comparing-string-objects-using-relational-operators-c/
    if (lhs.length() < rhs.length()) {
        return true;
    }

    for (auto lhs_p = lhs.begin, rhs_p = rhs.begin;
         lhs_p != lhs.end && rhs_p != rhs.end;
         lhs_p++, rhs_p++) {
        if (*lhs_p == *rhs_p) {
            continue;
        } else if (*lhs_p < *rhs_p) {
            return true;
        } else {
            return false;
        }
    }
}

#endif