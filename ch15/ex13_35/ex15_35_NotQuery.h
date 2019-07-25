#ifndef EX_15_35_NOT_QUERY_H
#define EX_15_35_NOT_QUERY_H

#include "headers.h"
#include "ex15_35_Query.h"
#include "ex15_35_Query_base.h"
#include "ex15_35_TextQuery_QueryResult.h"

class NotQuery : public Query_base {
    // All members would be private, use only uses Query interface class.
    friend Query operator~(const Query &);

    NotQuery(const Query& q) : query(q) {}
    string rep() const override { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery& tq) const override;   // TODO

    Query query;
};


inline Query operator~(const Query& q) {
    return Query(shared_ptr<Query_base>(new NotQuery(q)));
}

QueryResult NotQuery::eval(const TextQuery& tq) const {
    auto result = query.eval(tq);
    auto ret_line_nos = make_shared<set<TextQuery::lineNo>>();

    // algorithm
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for (size_t i = 0; i < sz; i++) {
        if (beg == end || i != *beg) {
            // ( all elements in result have been traversed || i is not contained in result )
            ret_line_nos -> insert(i);
        } else {
            ++beg;
        }
    }

    return QueryResult(rep(), result.get_file(), ret_line_nos);
}

#endif