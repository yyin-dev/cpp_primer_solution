#include "headers.h"

class Debug_deleter {
   public:
    Debug_deleter(ostream& os = cerr) : os(os) {}
    template <typename T> void operator()(T* ptr) {
        os << "Deleting unique_ptr." << endl;
        delete ptr;
    }

   private:
    ostream& os;
};

int main() {
    unique_ptr<double, Debug_deleter> uniq_ptr_double(new double, Debug_deleter());
}