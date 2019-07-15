#include "headers.h"

string add_prefix_suffix(string name, string prefix, string suffix){
    string s = prefix.append(" ").append(name).append(" ").append(suffix);
    return s;
}

int main() {
    string name = "Authur";
    string added = add_prefix_suffix(name, "King", "I");
    cout << added;
}