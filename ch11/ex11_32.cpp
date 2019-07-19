#include "headers.h"

using author_work_type = pair<string, string>;

void find_and_erase(multimap<string, string> &m, string k) {
    auto iter = m.find(k);
    if (iter == m.end()) {
        cout << "Element not found!\n";
    } else {
        m.erase(iter);
        cout << "Element with value: " << iter -> second << " found and erased!\n";
    }
}

bool entry_comp(const string & s1, const string & s2){ // must be declared as const
    return s1 < s2;
}

void print_alphabetically(multimap<string, string> &m) { // pass by reference    
    multimap<string, string, decltype(entry_comp) *> alphabetical_ordered(entry_comp);
    for(auto & entry: m){
        alphabetical_ordered.insert(entry);
    }
    for(auto & entry: alphabetical_ordered){
        cout << entry.first << ": " << entry.second << endl;
    }
}

int main() {
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

    print_alphabetically(m);
}