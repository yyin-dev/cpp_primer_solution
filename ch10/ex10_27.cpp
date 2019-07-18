#include "headers.h"

int main() {
    vector<string> v{"1234", "1234", "1234", "Hi", "alan", "wang", "HKUST", "HKU", "UC_Berkerly", "HKU"};
    for (auto iter = v.cbegin(); iter != v.cend(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    sort(v.begin(), v.end());
    for (auto iter = v.cbegin(); iter != v.cend(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    list<string> uniq;
    unique_copy(v.begin(), v.end(), back_inserter(uniq));
    for (auto iter = uniq.cbegin(); iter != uniq.cend(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}