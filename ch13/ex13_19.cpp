#include "headers.h"

class Employee {
   public:
    Employee() : id(++count), name("Annonymous") {}
    Employee(const string& s) : id(++count), name(s) {}

    Employee(const Employee& e) : id(++count), name(e.name) {}
    Employee& operator=(const Employee& e) {
        id = ++count;
        name = e.name;
        return *this;
    }

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
    Employee e4(e2);
    e1.info();
    e2.info();
    e3.info(); 
    e4.info();
}