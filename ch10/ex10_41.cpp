#include "headers.h"

int main() {
    replace(beg, end, old_val, new_val); // replace the old_elements in the input range with new_elements.
    replace_if(beg, end, pred, new_val); // replace the elements in the input range  with new_elements, if its pred is true.
    replace_copy(beg, end, dest, old_val, new_val); // Copies the elements in the input range to dest, replacing the appearances of old_value by new_value.
    replace_copy_if(beg, end, dest, pred, new_val); // Copies the elements in the input range to dest, replacing those for which pred returns true by new_value.
}