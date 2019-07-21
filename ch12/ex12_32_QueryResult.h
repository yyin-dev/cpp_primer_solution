#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include "headers.h"

class StrBlob;
class StrBlobPtr;

class QueryResult {
    friend ostream& print(ostream&, QueryResult);

   public:
    QueryResult(const string& s, shared_ptr<StrBlob> lines, shared_ptr<set<vector<string>::size_type>> lineNums)
        : target(s), lines(lines), lineNums(lineNums){};
    const set<vector<string>::size_type>::const_iterator begin() { return lineNums->begin(); }
    const set<vector<string>::size_type>::const_iterator end() { return lineNums->end(); }
    const shared_ptr<StrBlob> file() { return lines; }

   private:
    const string target;
    const shared_ptr<StrBlob> lines;
    const shared_ptr<set<vector<string>::size_type>> lineNums;
};

ostream& print(ostream& os, QueryResult qr) {
    size_t freq = qr.lineNums->size();

    os << qr.target << " occurs " << freq << (freq > 1 ? " times" : " time") << endl;
    for (auto lineNo : *(qr.lineNums)) {
        StrBlobPtr p{*(qr.lines), lineNo};
        cout << "\t(line " << (lineNo + 1) << ") " << p.deref() << endl;
    }
    return os;
}
#endif