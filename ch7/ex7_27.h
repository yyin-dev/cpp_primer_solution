#ifndef EX7_24_H
#define EX7_24_H

#include <iostream>
#include <string>

class Screen {
   public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos h, pos w) : height(h), width(w), content(h * w, ' ') {}
    Screen(pos h, pos w, char c) : height(h), width(w), content(h * w, c) {}

    // get char at current cursor
    inline char get() const {
        return content[cursor];
    }

    // get char at a specified cursor
    inline char get(pos r, pos c) const {
        return content[r * width + c];
    }

    // move cursor to a location
    inline Screen& move(pos r, pos c) {
        cursor = r * width + c;
        return *this;
    }

    inline Screen& set(char c) {
        content[cursor] = c;
        return *this;
    }

    inline Screen& set(pos r, pos col, char c) {
        content[r * width + col] = c;
        return *this;
    }

    Screen & display(std::ostream& os){
        do_display(os);
        return *this;
    }

    const Screen & display(std::ostream& os) const {
        do_display(os);
        return *this;
    }

   private:
    std::string content;
    pos height = 0, width = 0;
    pos cursor = 0;

    void do_display(std::ostream& os) const{
        for (int i = 0; i < height; i++){
            for ( int j =0; j < width; j++){
                os << content[i * width + j];
            }
            os << std::endl;
        }
    }
};

#endif