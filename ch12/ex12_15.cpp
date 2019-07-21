#include "headers.h"

class Connection {
   public:
    Connection(string dst) {
        cout << "Connection to " << dst << " created!" << endl;
    }
};

Connection connect(string dst) {
    Connection &c = *(new Connection(dst));
    cout << "Connection to " << dst << " conncted!" << endl;
    return c;
}

void fn() {
    Connection c = connect("USA");
    shared_ptr<Connection> spc(&c,
                               [](Connection *pc) -> void {delete pc; pc = nullptr; cout << "Connection ended!" << endl; });
}

int main() {
    fn();
}