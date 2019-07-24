#include "headers.h"

class Judger {
   public:
    string operator()(bool condition, string str_corr, string str_wrong) {
        return condition ? str_corr : str_wrong;
    }
};

int main() {
    Judger judge;
    cout << judge(1 + 4 > 8, "Correct!", "Wrong!");
}
