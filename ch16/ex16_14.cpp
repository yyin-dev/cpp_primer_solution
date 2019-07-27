#include "headers.h"

// Refer to ex16_16.cpp for more detail.
// 1. Forward declare template class
template <unsigned H, unsigned W>
class Screen;

// 2. Forward declare template functions
template <unsigned H, unsigned W>
ostream &operator<<(ostream &os, const Screen<H, W> &c);

template <unsigned H, unsigned W>
istream &operator>>(istream &is, Screen<H, W> &c);

template <unsigned H, unsigned W>
class Screen {
   public:
    // 3. Declare as friends
    friend ostream &operator<<<H, W>(ostream &os, const Screen<H, W> &c);
    friend istream &operator>><H, W>(istream &is, Screen &c);

    typedef string::size_type pos;
    Screen() = default;
    Screen(char c) : contents(H * W, c) {}

    char get() const { return contents[cursor]; }  // get the character at the cursor
    Screen &move(pos r, pos c);

   private:
    pos cursor = 0;
    pos height = H, width = W;
    string contents;
};

template <unsigned H, unsigned W>  // required even for definition of friend, non-member function
ostream &operator<<(ostream &os, const Screen<H, W> &c) {
    unsigned int i, j;
    for (i = 0; i < c.height; i++) {
        os << c.contents.substr(0, W) << endl;
    }
    return os;
}

// 4. Define functions
template <unsigned H, unsigned W>  // required even for definition of friend, non-member function
istream &operator>>(istream &is, Screen<H, W> &c) {
    char a;
    is >> a;
    string temp(H * W, a);
    c.contents = temp;
    return is;
}

template <unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

int main() {
    // For class template, everything in the template initialization list
    // is specified at the declaration of the object. The compiler does not
    // know and will not deduce the template initialization list for you.
    // This is a big difference from function template.

    Screen<5, 5> scr('c');
    Screen<5, 5> scr2;

    // output src to the screen
    cout << scr;
    // input connet  to the  src
    cin >> scr2;
    // test input
    cout << scr2;

    return 0;
}