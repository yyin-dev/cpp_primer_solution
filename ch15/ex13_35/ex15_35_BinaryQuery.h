#ifndef EX_15_35_BINARY_QUERY_H
#define EX_15_35_BINARY_QUERY_H

#include "ex15_35_Query.h"
#include "ex15_35_Query_base.h"
#include "ex15_35_TextQuery_QueryResult.h"
#include "headers.h"

class BinaryQuery : public Query_base {
    protected:
    BinaryQuery(const Query& lhs, const Query& rhs, const string& op)
        : lhs(lhs), rhs(rhs), opSym(op) {}

    string rep() const override { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
    // eval() is not overrided and BinaryQuery is still an abstract class.

    Query lhs, rhs;
    const string opSym;
};

#endif