#include "headers.h"
#include "ex16_12_Blob.h"
#include "ex16_12_BlobPtr.h"


int main() {
    Blob<string> strBlob{"hello ", "world!"};
    BlobPtr<string> strBlobPtr(strBlob);
    cout << *strBlobPtr << endl;
    cout << *(++strBlobPtr) << endl;
    cout << *(--strBlobPtr) << endl;
    cout << *(--strBlobPtr) << endl;
}
