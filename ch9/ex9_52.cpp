#include "headers.h"

void print(stack<string, vector<string>> s) {
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}

int main() {
    vector<string> v = {"Kobe Bryant", "(", "24", "Lakers", ")"};
    stack<string, vector<string>> s(v), s_copy(s);

    print(s);
    print(s_copy);
    
    cout << endl;

    bool inside_parenthesis = false;
    while (!s_copy.empty()) {
        auto item = s_copy.top();
        if (item == ")") {
            cout << "open parenthesis encountered!" << endl;
            inside_parenthesis = true;
        } else if (item == "(") {
            cout << "close parenthesis encountered!" << endl;
            s_copy.pop();
            s_copy.push("[cleaned]");
            inside_parenthesis = false;
            break;
        }

        if (inside_parenthesis) {
            s_copy.pop();
        }
    }
    print(s);
    print(s_copy);
}