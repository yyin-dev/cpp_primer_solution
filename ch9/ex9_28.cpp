#include "headers.h"

void print_forward_list(forward_list<string> fl) {
    if (!fl.empty()) {
        for (auto iter = fl.cbegin(); iter != fl.cend(); iter++) {
            std::cout << *iter << " ";
        }
        std::cout << endl;
    }
}

void insert_behind(forward_list<string> fl, string target, string str) {
    if(fl.empty()){
        std::cout << "Empty forward list, no processing." << endl;
        return;
    }

    std::cout << "Before processing: " << endl;
    print_forward_list(fl);

    bool inserted = false;
    auto curr = fl.begin();
    auto prev= fl.before_begin();

    while (curr != fl.end()) {
        if (*curr == target) {
            fl.insert_after(curr, str);
            inserted = true;
            break;
        } else {
            ++prev;
            ++curr;
        }
    }

    if (!inserted){
        fl.insert_after(prev, str);
    }

    std::cout << "After processing: " << endl;
    print_forward_list(fl);
}

int main() {
    forward_list<string> fl{"Do you love me?", "I am happy.", "Do you love me?"};
    insert_behind(fl, "Do you love me?", "Yes.");
    std::cout << endl;
    fl = {"Do you hate me?", "I am sad.", "Do you hate me?"};
    insert_behind(fl, "Do you love me?", "Yes.");
}