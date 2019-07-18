#include "headers.h"

using namespace std::placeholders;

void elimDups(vector<string>& v) {
    sort(v.begin(), v.end());
    auto iter_after_uniq = unique(v.begin(), v.end());
    v.erase(iter_after_uniq, v.end());
}

bool isShorter(const string& c1, const string& c2) {
    return c1.length() < c2.length();
}

bool isNoShorterThan(const string& s, const int min_len) {
    return s.length() >= min_len;
}

void biggies(vector<string>& v) {
    elimDups(v);
    stable_sort(v.begin(), v.end(), isShorter);

    string::size_type min_len = 4;
    auto one_past_last_biggie = stable_partition(v.begin(), v.end(), bind(isNoShorterThan, _1, min_len));  // only this line is different

    auto count = one_past_last_biggie - v.begin();
    cout << count << " " << (count > 1 ? "words" : "word") << " is longer than " << min_len << " characters." << endl;

    for_each(v.begin(), one_past_last_biggie, [](const string& s) { cout << s << " "; });
}

int main() {
    vector<string> v{"1234", "1234", "1234", "Hi", "alan", "wang", "HKUST", "HKU", "UC_Berkerly"};
    biggies(v);
}