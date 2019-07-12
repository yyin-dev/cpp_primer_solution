#include <string>
#include "ex7_42.h"

using namespace std;

int main() {
    Employee e1('M', "Research", "Senior", false);
    Employee e2('F');
    Employee e3("Junior", true);
    e1.print();
    e2.print();
    e3.print();
}