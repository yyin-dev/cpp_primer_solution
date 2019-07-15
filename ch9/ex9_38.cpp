// vector memory allocation implementation

#include "headers.h"

int main() {
    int prev_capacity = -1;

    vector<int> v;
    for (int i = 0; i < 50; i++) {
        v.push_back(i);
        if(prev_capacity!= v.capacity()){
            cout << "When pushing " << i << ", memory allocation happens." 
            << " Size: " << v.size() << ", Capacity: " << v.capacity() << endl;
            prev_capacity = v.capacity();
        }
    }
}