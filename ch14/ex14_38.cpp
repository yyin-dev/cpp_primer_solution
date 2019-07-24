#include "headers.h"

class Count_longer {
   public:
    Count_longer(const int l, const int u)
        : lower(l), upper(u) {}

    void operator()(const string& input) {
        if (input.length() >= lower && input.length() <= upper) {
            cout << input.length() << endl;
            ++counter;
            cout << counter << endl;
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

int main () {
    vector<string> v{"Hello", "it's", "me", "blablablablabla"};

    // This does not work as you are passing a copy of the object.
    Count_longer counter(1, 10);
    for_each(v.cbegin(), v.cend(), counter);
    counter.notify_clear();

    // This still does not work, you are still passing a copy of object.
    // You need to pass in a pointer, but this is not possible with for_each.
    Count_longer * p_counter = new Count_longer(1, 10);
    for_each(v.cbegin(), v.cend(), *p_counter);
    (*p_counter).notify_clear();
}