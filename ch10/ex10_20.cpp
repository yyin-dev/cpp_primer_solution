#include "headers.h"

int main() {
    vector<string> v{"1234", "1234", "1234", "Hi", "alan", "wang", "HKUST", "HKU", "UC_Berkerly"};
    cout << count_if(v.cbegin(), v.cend(), [](const string & s){return s.length() > 6;});
}