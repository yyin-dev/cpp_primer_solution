#include "headers.h"
// #include "ex12_19_StrBlob.h"
// #include "ex12_19_StrBlobPtr.h"
#include "ex12_19_combined.h"

int main() {
    StrBlob sb{"hu", "jdkf"};
    StrBlobPtr sbp(sb, 0);
    sb.push_back("fhdj");
    
    cout << sbp.deref() << endl;
    cout << sbp.incre().deref() << endl;
}