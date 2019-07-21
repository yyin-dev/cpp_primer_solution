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

void end_connection(Connection * pc){
    delete pc;
    pc = nullptr;
    cout << "Connection ended!" << endl;
}

void fn() {
    Connection c = connect("USA");
    shared_ptr<Connection> spc(&c, end_connection);
}

int main() {
    fn();
}