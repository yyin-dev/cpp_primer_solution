#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H
#include "headers.h"

class QueryResult {
    friend ostream& print(ostream&, QueryResult);

   public:
    QueryResult() = default;
    QueryResult(const string& s, map<int, string> res) : target(s), mapping(res){};

   private:
    map<int, string> mapping;
    const string target;
};

ostream& print(ostream& os, QueryResult qr) {
    size_t freq = qr.mapping.size();
    os << qr.target << " occurs " << freq << (freq > 1 ? " times" : " time") << endl;
    for (const pair<int, string>& p : qr.mapping) {
        cout << "\t(line " << p.first << ") " << (p.second.length() > 50 ? p.second.substr(0, 50) : p.second) << endl;
    }
    return os;
}
#endif