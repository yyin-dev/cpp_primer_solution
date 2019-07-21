#include "headers.h"

int main() {
    const int size = 3;
    allocator<string> alloc;
    string *p = alloc.allocate(size), *b = p, *e = p + size;

    string word;
    while (p != e) {
        cin >> word;
        alloc.construct(p++, word);
    }

    for(auto ptr = b; ptr < e; ptr++){
        cout << *ptr << " " ;
    }

    while(p != b){
        alloc.destroy(--p);
    }

    alloc.deallocate(p, size);
}