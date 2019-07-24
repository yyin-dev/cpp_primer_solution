#include "headers.h"

class Read {
   public:
    Read(istream& is = cin) : is(is) {}
    string operator()() {
        cout << "Enter a string: ";
        string line;
        getline(is, line);
        if(is) {
            return line;
        } else {
            return "";
        }
    }

   private:
    istream& is;
};

int main() {
    Read read;
}
