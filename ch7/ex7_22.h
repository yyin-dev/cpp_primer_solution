#ifndef EX7_15_H
#define EX7_15_H

#include <iostream>
#include <string>

class Person {
    Person() = default;
    Person(const std::string& str) : name(str) {}
    Person(const std::string& str1, const std::string& str2) : name(str1), address(str2) {}

    // const getter
    const std::string& get_name() const { return name; }
    const std::string& get_address() const { return address; }

    std::string name;
    std::string address = "HKU";
};

#endif