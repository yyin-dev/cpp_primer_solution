#include "headers.h"

using namespace std::placeholders;

bool longer_than(string s, string threshold_s){
    return s.length() > threshold_s.length();
}

int main() {
    vector<string> v{"1234", "1234", "1234", "Hi", "alan", "wang", "HKUST", "HKU", "UC_Berkerly"};
    auto iter = find_if(v.cbegin(), v.cend(), bind(longer_than, _1, "1234" ));
    cout << *iter << endl;
}