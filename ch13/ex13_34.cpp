#include "ex13_34.h"
#include "headers.h"

int main() {
    Message m1("For m1 m2");
    Folder f1("Folder1");
    Folder f2("Folder2");
    Folder f3("Folder3");
    m1.save(&f1);
    m1.save(&f2);
    Message m2(m1);
    m1.info();
    m2.info();
    f1.info();
    f2.info();
    f3.info();
    cout << endl;

    m2.save(&f3);
    m1.remove(&f1);
    m1.info();
    m2.info();
    f1.info();
    f2.info();
    f3.info();
    cout << endl;

    Message m3 = m1;
    m3.info();
    f1.info();
    f2.info();
    f3.info();
    m3 = m2;
    m3.info();
    f1.info();
    f2.info();
    f3.info();
    cout << endl;

    Message m4("For m3 m4");
    m3 = m4;
    m1.info();
    m2.info();
    m3.info();
    m4.info();
    cout << endl;

    m2.info();
    m3.info();
    swap(m2, m3);
    m2.info();
    m3.info();
}