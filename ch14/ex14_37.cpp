#include "headers.h"

class If_equal {
   public:
    bool operator()(const string& s1, const string& s2) { return s1 == s2; }
    // This function must be a const function. The const keyword(not added here)
    // tells compiler that calling this would not change the state of the object.
    // Otherwise you need to use the mutable keyword in the lambda function.
    // The logic here is similar, even though you do not actually
    // change this object in the lambda(this object has no state at all),
    // the compiler does not know your operation to it at runtime.
    // Thus, you have to declare this memeber as constant, or you need
    // the lambda keyword in the lambda function.

    // By default, variables in the capture list are copied, unless prefixed with &.
};

int main() {
    If_equal if_equal;
    vector<string> hi{"hi", "hi", "hi"};
    // replace hi with hello

    for (auto s : hi) {
        cout << s << " ";
    }
    cout << endl;

    replace_if(hi.begin(), hi.end(),
               [if_equal](string& s) mutable -> bool { return if_equal(s, "hi"); },
               "hello");

    for (auto s : hi) {
        cout << s << " ";
    }
    cout << endl;

    // One way to escape both const and mutable: by removing capture
    for (auto s : hi) {
        cout << s << " ";
    }
    cout << endl;

    replace_if(hi.begin(), hi.end(),
               [](string& s) -> bool { return If_equal()(s, "hello"); },
               "hi");

    for (auto s : hi) {
        cout << s << " ";
    }
    cout << endl;

    // Another way to escape both const and mutable: by capture by reference.
    // Because the restriction of modification is only on variables captured
    // by copy.
    for (auto s : hi) {
        cout << s << " ";
    }
    cout << endl;

    replace_if(hi.begin(), hi.end(),
               [&if_equal](string& s) -> bool { return if_equal(s, "hello"); },
               "hi");

    for (auto s : hi) {
        cout << s << " ";
    }
    cout << endl;
}
