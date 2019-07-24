#include "headers.h"

/*
+: function
-: class generated from lambda expression
*: callable object
/: lambda expression
%: from <functional>
 */

int add(const int& a, const int& b) { return a + b; }
auto subtract = [](const int& a, const int& b) -> int { return a - b; };
struct multiply {
    int operator()(const int& a, const int& b) { return a * b; }
};

int main() {
    map<string, function<int(int, int)>> function_table{
        {"+", add},
        {"-", subtract},
        {"*", multiply()},
        {"/", [](const int& a, const int& b) -> int { return a / b; }},
        {"%", modulus<int>()}};

    cout << function_table["+"](10, 2) << endl;
    cout << function_table["-"](10, 2) << endl;
    cout << function_table["*"](10, 2) << endl;
    cout << function_table["/"](10, 2) << endl;
    cout << function_table["%"](10, 2) << endl;
}