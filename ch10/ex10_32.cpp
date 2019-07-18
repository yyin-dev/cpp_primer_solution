#include "Sales_item.h"
#include "headers.h"

int main() {
    ifstream ifs("./transaction_input.txt");
    istream_iterator<Sales_item> is_iter(ifs), eof;
    vector<Sales_item> items;

    // read input into vector
    copy(is_iter, eof, back_inserter(items));

    // sort elements in vector
    sort(items.begin(), items.end(), compareIsbn);
    for (auto iter = items.cbegin(); iter != items.cend(); iter++) {
        cout << *iter << " " << endl;
    }
    cout << endl;

    // process
    auto first_in_group_iter = items.cbegin();
    
    while (first_in_group_iter != items.cend()) {
        auto one_past_group_iter = find_if(first_in_group_iter, items.cend(),
                                           [first_in_group_iter](Sales_item item) -> bool { return item.isbn() != (*first_in_group_iter).isbn(); });
        Sales_item sum = accumulate(first_in_group_iter, one_past_group_iter, Sales_item((*first_in_group_iter).isbn()));
        cout << sum << endl;
        first_in_group_iter = one_past_group_iter;
    }
}