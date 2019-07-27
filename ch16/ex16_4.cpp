#include "headers.h"
#include "Sales_data.h"


template <typename iter_T, typename val_T>
iter_T my_find(iter_T beg, iter_T end, val_T target) {
    for(iter_T p = beg; p != end; p++) {
        if ( *p == target ) {
            return p;
        }
    }
    return end;
} 


int main() {
    vector<int> v{1, 2, 3, 4, 5};
    vector<int>::iterator iter = my_find(v.begin(), v.end(), 10);
    if(iter == v.end()) {
        cout << "Not found." << endl;
    } else {
        cout << "Find " << *iter << endl;
    }
}