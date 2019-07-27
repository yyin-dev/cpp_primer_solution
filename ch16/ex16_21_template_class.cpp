#include "headers.h"

template <typename T>
class Debug_deleter {
   public:
    Debug_deleter(ostream& os = cerr) : os(os) {}
    void operator()(T* ptr) {
        os << "Deleting unique_ptr." << endl;
        delete ptr;
    }

   private:
    ostream& os;
};

int main() {
    unique_ptr<int, Debug_deleter<int>> uniq_ptr_int(new int, Debug_deleter<int>(cout));
}