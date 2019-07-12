#ifndef EX7_22_H
#define EX7_22_H

#include <iostream>
#include <string>

class Person {
    // implicitly private
    std::string name;
    std::string address = "HKU";

   public:
    const std::string& get_name() const { return name; }
    const std::string& get_address() const { return address; }
};

#endif