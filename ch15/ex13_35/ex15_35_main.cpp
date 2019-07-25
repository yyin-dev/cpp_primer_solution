#include "headers.h"
#include "ex15_35_Query.h"
#include "ex15_35_WordQuery.h"
#include "ex15_35_AndQuery.h"
#include "ex15_35_NotQuery.h"
#include "ex15_35_OrQuery.h"
#include "ex15_35_TextQuery_QueryResult.h"

/*
g++ ./*.cpp -o ex13_35_main

 */

int main() {
    Query q = Query("#include") & Query("<functional>");
    ifstream ifs("./headers.h");
    TextQuery tq(ifs);
    cout << q.eval(tq);
}