#ifndef EX_15_35_OR_QUERY_H
#define EX_15_35_OR_QUERY_H

#include "ex15_35_BinaryQuery.h"
#include "ex15_35_Query.h"
#include "ex15_35_Query_base.h"
#include "ex15_35_TextQuery_QueryResult.h"
#include "headers.h"

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query& lhs, const Query& rhs);

    OrQuery(const Query& lhs, const Query& rhs) : BinaryQuery(lhs, rhs, "|") {}

    QueryResult eval(const TextQuery& tq) const override;  
};

Query operator|(const Query& lhs, const Query& rhs) {
    return Query(shared_ptr<Query_base>(new OrQuery(lhs, rhs)));
}

QueryResult OrQuery::eval(const TextQuery& tq) const {
    QueryResult left = lhs.eval(tq), right = rhs.eval(tq);

    auto ret_line_nos = make_shared<set<TextQuery::lineNo>>(left.begin(), left.end());

    for (auto p = right.begin(); p != right.end(); p++) {
        ret_line_nos -> insert(*p);
    }

    return QueryResult(rep(), left.get_file(), ret_line_nos);
}

#endif