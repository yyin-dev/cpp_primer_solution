#ifndef EX7_23_H
#define EX7_23_H

#include <iostream>
#include <string>

class Screen {
   public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos h, pos w, char c) : height(h), width(w), content(h * w, c) {}
    // https://stackoverflow.com/questions/45317692/how-the-members-initial-value-like-contentsht-wd-c-works-in-constructor/56981531#56981531

    // get char at current cursor 
    inline char get() const {
        return content[cursor];
    }

    // get char at a specified cursor
    inline char get(pos ht, pos wd) const {
        return content[ht * wd];
    }

    // move cursor to a location
    inline Screen & set_cursor(pos r, pos c){
        cursor = r * width + c;
        return *this;
    }
    
   private:
    std::string content;
    pos height = 0, width = 0;
    pos cursor = 0;
};

#endif