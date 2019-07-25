#include "headers.h"

class Func {  // abstract class
   public:
    Func() = default;
    Func(const string& n, const size_t& np, const string& rt)
        : name(n), num_params(np), return_type(rt) {}
    virtual void info() const = 0;

   private:
    string name;
    size_t num_params;
    string return_type;
};

void Func::info() const {
    cout << "Function: " << name << ", " << num_params << " paramters"
         << ", return type: " << return_type;
}

class Mem_func : public Func {
   public:
    Mem_func() = default;
    Mem_func(const string& n, const size_t& np, const string& rt, const string& defined_in)
        : Func(n, np, rt), defined_in(defined_in) {}

    void info() const override;

   private:
    string defined_in = "unspecified";
};

void Mem_func::info() const {
    Func::info();
    cout << " [Member Function defined in class: " << defined_in << " ].";
}

class Nonmem_func : public Func {
   public:
    Nonmem_func() = default;
    Nonmem_func(const string& n, const size_t& np, const string& rt) : Func(n, np, rt) {}

    void info() const override;
};

void Nonmem_func::info() const {
    Func::info();
    cout << " [Non-Member Function].";
}

int main() {
    Mem_func mem("debug", 0, "void", "Bulk");
    Nonmem_func nonmem("main", 0, "int");
    mem.info();
    cout << endl;

    nonmem.info();
}