#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H
#include "headers.h"

class QueryResult {
    friend ostream& print(ostream&, QueryResult);

   public:
    QueryResult(const string& s, shared_ptr<vector<string>> lines, shared_ptr<set<vector<string>::size_type>> lineNums)
        : target(s), lines(lines), lineNums(lineNums){};

   private:
    const string target;
    const shared_ptr<vector<string>> lines;
    const shared_ptr<set<vector<string>::size_type>> lineNums;
};

ostream& print(ostream& os, QueryResult qr) {
    size_t freq = qr.lineNums->size();
    os << qr.target << " occurs " << freq << (freq > 1 ? " times" : " time") << endl;
    for (auto lineNo : *(qr.lineNums)) {
        cout << "\t(line " << (lineNo + 1) << ") " << (*qr.lines)[lineNo] << endl;
    }
    return os;
}
#endif