#include "headers.h"

class Employee {
   public:
    Employee() : id(++count), name("Employee_" + to_string(id)) {}
    Employee(const string& s) : id(++count), name(s) {}

    void info() { cout << id << ": " << name << endl; }

   private:
    static int count;
    int id;
    string name;
    static const int in_class_initialization_only_for_const_static = 0;
};

int Employee::count = 0;

int main() {
    Employee e1;
    Employee e2("Dave");
    Employee e3 = e1;
    e1.info();
    e2.info();
    e3.info();  // Not desired
}