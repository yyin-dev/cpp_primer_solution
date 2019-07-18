#include "headers.h"

void elimDups(vector<string>& v) {
    sort(v.begin(), v.end());
    auto iter_after_uniq = unique(v.begin(), v.end());
    v.erase(iter_after_uniq, v.end());
}

bool isShorter(const string& c1, const string& c2) {
    return c1.length() < c2.length();
}

void biggies(vector<string>& v) {
    elimDups(v);
    stable_sort(v.begin(), v.end(), isShorter);

    string::size_type min_len = 4;
    auto one_past_last_biggie = partition(v.begin(), v.end(), [min_len](const string & s){return s.length() >= min_len; });

    auto count = one_past_last_biggie - v.begin();
    cout << count << " " << (count > 1 ? "words" : "word") << " is longer than " << min_len << " characters." << endl;

    for_each(v.begin(), one_past_last_biggie, [](const string& s) { cout << s << " "; });
}

int main() {
    vector<string> v{"1234", "1234", "1234", "Hi", "alan", "wang", "HKUST", "HKU", "UC_Berkerly"};
    biggies(v);
}