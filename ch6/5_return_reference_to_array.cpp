#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;


// direct return type and trailing return are similar
string (&returnRefToArrayOfTwoStrings(string (&ref) [2])) [2]{
    return ref;
}

auto returnRefToArrayOfTwoStringsWithTrailingReturn(string (&ref) [2]) -> string (&) [2]{
    return ref;
}


// typedef and decltype are similar
typedef string arrayOfTwoStrings [2];
arrayOfTwoStrings & returnRefToArrayOfTwoStringsWithTypeAlias(string (&ref) [2]){
    return ref;
}

string emptyStrings[] = {"", ""};
decltype(emptyStrings) & returnRefToArrayOfTwoStringsWithDecltype (string (&ref) [2]){
    return ref;
}


int main(int argc, char **argv) {
    string strs[] = {"Hi", "Hello"};
    string (&r) [2] = returnRefToArrayOfTwoStrings(strs);
    // r is a reference to the array
    // But when we later use r, it decays to be a pointer to the
    // first string object in the array.
    // So, string arr[2] = r; is wrong as r is actually a pointer.

    cout << r[0] <<endl;
    cout << r[1] << endl;

    string * ptr = r;
    cout << *ptr++ << endl;
    cout << *ptr << endl;
}
