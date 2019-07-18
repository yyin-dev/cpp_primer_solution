#include "headers.h"

bool no_shorter_than(const string & s) {
    return s.length() >= 5;
}

int main() {
    vector<string> v{"1234", "1234", "1234", "Hi", "alan", "wang", "HKUST", "HKU", "UC_Berkerly"};
    string::size_type min_len = 5;
    auto one_past_first_half_iter = partition(v.begin(), v.end(), [min_len] (const string & s){return s.length() >= min_len;});
    for (auto iter = v.begin(); iter != one_past_first_half_iter; iter++) {
        cout << *iter << " ";
    }
}