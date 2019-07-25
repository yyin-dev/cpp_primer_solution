#ifndef EX_15_35_QUERY_BASE_H
#define EX_15_35_QUERY_BASE_H

#include "ex15_35_TextQuery_QueryResult.h"
#include "headers.h"

class Query_base {
    friend class Query;

   protected:
    using lineNo = TextQuery::lineNo;
    virtual ~Query_base() = default; // protected and virtual for derived class to override

   private:
    virtual QueryResult eval(const TextQuery& tq) const = 0;
    virtual string rep() const = 0;
};
#endif