#include "headers.h"

int main() {
    forward_list<int> fl{0, 1, 2, 3, 4, 5, 6};
    auto prev = fl.before_begin();
    auto curr = fl.begin();

    while (curr != fl.end()) {
        if (*curr % 2 == 1) {
            cout << "Odd value found: " << *curr << ". ";
            curr = fl.erase_after(prev);
            cout << "Removed!" << endl;
        } else {
            ++prev;
            ++curr;
        }
    }
}