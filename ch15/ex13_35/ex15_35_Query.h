#ifndef EX_15_35_QUERY_H
#define EX_15_35_QUERY_H


#include "ex15_35_StrBlob_StrBlobPtr.h"
#include "ex15_35_TextQuery_QueryResult.h"
#include "ex15_35_Query_base.h"
#include "ex15_35_WordQuery.h"
#include "headers.h"

// Here you should not #include NotQuery, AndQuery or OrQuery. 
// Do not include files that you do not need. Include them only
// when you need it. 
// TODO: But what is the reason? If I include it, the code cannot compile. 

/*
Usage:

std::ifstream file("test.txt");
TextQuery tQuery(file);
Query q = Query("fiery") & Query("bird") | Query("wind"); 
std::cout << q.eval(tQuery);

Query is the inteface class the user would use. Each Query object would contains a shared_ptr
to an object of type derived from Query_base. The Query class would have the same operations 
as the Query_base class: eval(const Query &) and rep().

~ would generate a Query, bound to a NotQuery;
& would generate a Query, bound to a AndQuery;
| would generate a Query, bound to a OrQuery;
The constructor Query(const string &) would generate a new WordQuery.
 */

class Query {
    friend Query operator~(const Query& q);
    friend Query operator&(const Query& lhs, const Query& rhs);  
    friend Query operator|(const Query& lhs, const Query& rhs);  

   public:
    Query(const string& qw): query(new WordQuery(qw)) {}
    QueryResult eval(const TextQuery& tq) const { return query -> eval(tq); }
    string rep () const { return query -> rep(); }

   private:
    Query(shared_ptr<Query_base> sp_qb) : query(sp_qb) {}
    shared_ptr<Query_base> query;
};

void operator<<(ostream& os, const Query & q) {
    os << q.rep() << endl;
}

#endif