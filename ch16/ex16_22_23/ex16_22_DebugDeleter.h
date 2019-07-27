#ifndef EX_16_22_DEBUG_DELETER_H
#define EX_16_22_DEBUG_DELETER_H

#include "headers.h"

class DebugDeleter {
   public:
    DebugDeleter(ostream& os = cerr) : os(os) {}

    template <typename T>
    void operator()(T* ptr) {
        os << "Deleting shared_ptr." << endl;
        delete ptr;
    }

   private:
    ostream& os;
};

#endif