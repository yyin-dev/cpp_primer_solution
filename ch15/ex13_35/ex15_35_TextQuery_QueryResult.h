#ifndef EX_15_35_TEXTQUERY_QUERYRESULT_H
#define EX_15_35_TEXTQUERY_QUERYRESULT_H

/*
For similar reason as mentioned in ex15_35_StrBlob_StrBlobPtr.h, we would 
define TextQuery and QueryResult in the same file.
 */

#include "ex15_35_StrBlob_StrBlobPtr.h"
#include "headers.h"

// Before writing a class, you should think about how the class intends to be used.
// Do you want to user to write
// TextQuery tq(ifstream("input.txt"), "target"); or
// TextQuery tq(ifstream("input.txt")); cout << tq.query("target") ?
// The implementation below is for the second usage.

class QueryResult;

class TextQuery {
   public:
    using lineNo = StrBlob::size_type;

    TextQuery(istream& is);
    QueryResult query(const string& target) const;

   private:
    shared_ptr<StrBlob> file_lines_sp;
    map<string, shared_ptr<set<lineNo>>> word_map;
};

class QueryResult {
    friend void operator<<(ostream& os, const QueryResult& qr);

   public:
    QueryResult(const string & t, shared_ptr<StrBlob> file_lines_sp, shared_ptr<set<TextQuery::lineNo>> line_nos)
        : target(t), file_lines_sp(file_lines_sp), line_nos(line_nos){};

    set<TextQuery::lineNo>::const_iterator begin() const { return line_nos->cbegin(); }
    set<TextQuery::lineNo>::const_iterator end() const { return line_nos->cend(); }
    shared_ptr<StrBlob> get_file() { return file_lines_sp; }

   private:
    shared_ptr<StrBlob> file_lines_sp;
    shared_ptr<set<TextQuery::lineNo>> line_nos;
    const string target;
};

#endif