#include "headers.h"

class String {
    friend void print(String& s);

   public:
    // Normal constructors
    String() : begin(nullptr), end(nullptr){};
    String(const string& s);
    String(const char* pc);

    size_t length() const;

   private:
    allocator<char> alloc;
    char* begin;
    char* end;
};

String::String(const string& s) {
    auto size = s.length();
    begin = alloc.allocate(size);
    end = uninitialized_copy(s.begin(), s.end(), begin);
}

String::String(const char* pc) {
    int len = 0;
    auto p = pc;
    while (*p != '\0') {
        len++;
        p++;
    }

    begin = alloc.allocate(len);
    end = uninitialized_copy(pc, pc + len, begin);
}

size_t String::length() const { return end - begin; }

void print(String& s) {
    cout << "\"";
    for (auto p = s.begin; p != s.end; p++) {
        cout << *p;
    }
    cout << "\", " << s.length() << endl;
}

int main() {
    String s1;
    print(s1);

    char cstyle[] = "Hello";
    const int length = sizeof(cstyle) / sizeof(cstyle[0]);
    cout << length << endl;
    String s2(cstyle);
    print(s2);
}