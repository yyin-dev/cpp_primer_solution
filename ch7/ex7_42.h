#include <iostream>
#include <string>

class Employee {
   public:
    Employee(const char& g, const std::string& d, const std::string& l, bool r) : gender(g), department(d), level(l), remote(r) {}
    Employee(const char& g) : Employee(g, "Development", "Junior", false) {}
    Employee(const std::string l, bool r) : Employee('M', "Development", l, r) {}
    void print(std::ostream& os); // os = std::cout should be removed. Default parameter can only be defined once.

   private:
    char gender = 'M';
    std::string department = "Development";
    std::string level = "Junior";
    bool remote = false;
};

void Employee::print(std::ostream& os = std::cout) {
    os << gender << " " << department << " " << level << " " << (remote ? "remote" : "onsite") << std::endl;
}