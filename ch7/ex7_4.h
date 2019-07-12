#ifndef EX7_4_H
#define EX7_4_H

#include <iostream>
#include <string>

struct Person {
    // const getter
    const std::string& get_name() const { return name; }
    const std::string& get_address() const { return address; }

    std::string name;
    std::string address = "HKU";
};

#endif