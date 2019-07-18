#include "headers.h"

using namespace std::placeholders;

bool longer_than_six(const string& s) {
    return s.length() > 6;
}

bool longer_than_specified(const string& s, const int min_len) {
    return s.length() > min_len;
}


int main() {
    vector<string> v{"1234", "1234", "1234", "Hi", "alan", "wang", "HKUST", "HKU", "UC_Berkerly"};
    cout << count_if(v.cbegin(), v.cend(), longer_than_six) << endl;
    cout << count_if(v.cbegin(), v.cend(), bind(longer_than_specified, _1, 6)) << endl;
}