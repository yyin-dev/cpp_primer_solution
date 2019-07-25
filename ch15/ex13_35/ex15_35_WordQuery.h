#ifndef EX_15_35_WORD_QUERY_H
#define EX_15_35_WORD_QUERY_H

#include "headers.h"
#include "ex15_35_Query.h"
#include "ex15_35_Query_base.h"
#include "ex15_35_TextQuery_QueryResult.h"

class WordQuery : public Query_base {
    // All members would be private, use only uses Query interface class.
    friend class Query;

    WordQuery(const string& qw) : query_word(qw) {}
    QueryResult eval(const TextQuery& tq) const override { return tq.query(query_word); }
    string rep() const override { return query_word; }

    const string query_word;
};

#endif