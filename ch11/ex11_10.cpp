#include "headers.h"

bool int_vector_iter_comp(const vector<int>::iterator iter1, const vector<int>::iterator iter2) {
    return *iter1 < *iter2;
}

bool int_list_iter_comp(const list<int>::iterator iter1, const list<int>::iterator iter2) {
    return *iter1 < *iter2;
}

int main() {
    // 1. Test vector<int>::iterator as key type

    // Without providing custom comparison function
    map<vector<int>::iterator, int> default_comparison;

    // Providing custom comparison function, check C++ Primer p247
    // Basic version
    map<vector<int>::iterator, int,
        bool (*)(const vector<int>::iterator iter1, const vector<int>::iterator iter2)>
        basic(int_vector_iter_comp);

    // use decltype
    map<vector<int>::iterator, int, decltype(int_vector_iter_comp)*> with_decltype(&int_vector_iter_comp);

    // Use type alias or using
    typedef bool my_predicate(const vector<int>::iterator iter1, const vector<int>::iterator iter2);
    map<vector<int>::iterator, int, my_predicate*> with_typedef(&int_vector_iter_comp);

    using my_predicate_pointer_type = bool (*)(const vector<int>::iterator iter1, const vector<int>::iterator iter2);
    map<vector<int>::iterator, int, my_predicate_pointer_type> with_using(&int_vector_iter_comp);

    vector<int> v = {1, 2, 3};

    default_comparison.insert(pair<vector<int>::iterator, int>({v.end(), 0}));
    default_comparison.insert(pair<vector<int>::iterator, int>({v.begin(), 0}));
    default_comparison.insert(pair<vector<int>::iterator, int>({v.begin(), 1}));
    default_comparison.insert(pair<vector<int>::iterator, int>({v.begin() + 1, 1}));

    cout << "size: " << default_comparison.size() << endl;
    for (auto& p : default_comparison) {
        cout << *(p.first) << ": " << p.second << endl;
    }

    basic.insert(pair<vector<int>::iterator, int>({v.end(), 0}));
    basic.insert(pair<vector<int>::iterator, int>({v.begin(), 0}));
    basic.insert(pair<vector<int>::iterator, int>({v.begin(), 1}));
    basic.insert(pair<vector<int>::iterator, int>({v.begin() + 1, 1}));

    cout << "size: " << basic.size() << endl;
    for (auto& p : basic) {
        cout << *(p.first) << ": " << p.second << endl;
    }

    with_decltype.insert(pair<vector<int>::iterator, int>({v.end(), 0}));
    with_decltype.insert(pair<vector<int>::iterator, int>({v.begin(), 0}));
    with_decltype.insert(pair<vector<int>::iterator, int>({v.begin(), 1}));
    with_decltype.insert(pair<vector<int>::iterator, int>({v.begin() + 1, 1}));

    cout << "size: " << with_decltype.size() << endl;
    for (auto& p : with_decltype) {
        cout << *(p.first) << ": " << p.second << endl;
    }

    with_typedef.insert(pair<vector<int>::iterator, int>({v.end(), 0}));
    with_typedef.insert(pair<vector<int>::iterator, int>({v.begin(), 0}));
    with_typedef.insert(pair<vector<int>::iterator, int>({v.begin(), 1}));
    with_typedef.insert(pair<vector<int>::iterator, int>({v.begin() + 1, 1}));

    cout << "size: " << with_typedef.size() << endl;
    for (auto& p : with_typedef) {
        cout << *(p.first) << ": " << p.second << endl;
    }

    // 2. Test list<int>::iterator as key type
    map<list<int>::iterator, int> my_map;
    map<list<int>::iterator, int, decltype(int_list_iter_comp)*> my_map2;

    list<int> l{1, 2, 3};

    // my_map.insert(pair<list<int>::iterator, int>({l.begin(), 1}));  // Error, as list<int>::iterator has no < operator defined
    my_map2.insert(pair<list<int>::iterator, int>({l.begin(), 1}));    // ok, if you supply the comparison function
}