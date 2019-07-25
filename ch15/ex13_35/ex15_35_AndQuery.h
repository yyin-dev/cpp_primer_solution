#ifndef EX_15_35_AND_QUERY_H
#define EX_15_35_AND_QUERY_H

#include "ex15_35_TextQuery_QueryResult.h"
#include "ex15_35_Query_base.h"
#include "ex15_35_Query.h"
#include "ex15_35_BinaryQuery.h"
#include "headers.h"

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query& lhs, const Query& rhs);

    AndQuery(const Query& lhs, const Query& rhs) : BinaryQuery(lhs, rhs, "&") {}

    QueryResult eval(const TextQuery& tq) const override;  
};

Query operator&(const Query& lhs, const Query& rhs) {
    return Query(shared_ptr<Query_base>(new AndQuery(lhs, rhs)));
}

QueryResult AndQuery::eval(const TextQuery& tq) const {
    QueryResult left = lhs.eval(tq), right = rhs.eval(tq);

    auto ret_line_nos = make_shared<set<TextQuery::lineNo>>();
    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                          inserter(*ret_line_nos, ret_line_nos->begin()));

    return QueryResult(rep(), left.get_file(), ret_line_nos);
}

#endif