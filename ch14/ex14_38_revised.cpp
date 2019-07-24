#include "headers.h"

class Count_longer {
   public:
    Count_longer(const int l, const int u)
        : lower(l), upper(u) {}

    void operator()(const string& input) {
        if ((input.length() >= lower && input.length() <= upper) ||
            input.length() >= 10) {
            ++counter;
            // cout << counter << " word(s) has required length!" << endl;
        }
    }

    void notify_clear() {
        cout << counter << " word(s) has length in given bound!" << endl;
        cout << "Resetting counter... Reset done." << endl;
        counter = 0;
    }

   private:
    const int lower, upper;
    int counter = 0;
};

int main() {
    ifstream ifs("./ex14_37.cpp");
    Count_longer count(1, 9);
    string word;
    while (ifs >> word) {
        count(word);
    }
    count.notify_clear();
}