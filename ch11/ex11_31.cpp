#include "headers.h"

void find_and_erase(multimap<string, string> &m, string k) {
    auto iter = m.find(k);
    if (iter == m.end()) {
        cout << "Element not found!\n";
    } else {
        m.erase(iter);
        cout << "Element with value: " << iter -> second << " found and erased!\n";
    }
}

int main() {
    using author_work_type = pair<string, string>;
    multimap<string, string> m{
        author_work_type{"Shakespear", "King Lear"},
        author_work_type{"Marquez", "One hundred years of solitude"},
        author_work_type{"Marquez", "Love in the Time of Cholera"},
        author_work_type{"Shakespear", "Macbeth"},
        author_work_type{"Shakespear", "Hamlet"},
        author_work_type{"Yu Hua", "A life"},
        author_work_type{"Hemingway", "The sun also rises"},
        author_work_type{"Hemingway", "A fareware to arms"},
    };

    // erase
    find_and_erase(m, "Shakespear");
    cout << m.find("Shakespear") -> second << endl;
    find_and_erase(m, "Fred");
}