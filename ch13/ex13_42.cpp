#include "ex13_42_StrVec.h"
#include "ex13_42_QueryResult.h"
#include "ex13_42_TextQuery.h"
#include "headers.h"

QueryResult TextQuery::query(const string& keyword) const {
    static shared_ptr<set<lineNum>> notFound(new set<lineNum>());

    auto p = word2lineNums.find(keyword);
    if (p != word2lineNums.end()) {
        return QueryResult(keyword, lines, p->second);
    } else {
        return QueryResult(keyword, lines, notFound);
    }
}

int main() {
    TextQuery tq = TextQuery();
    while (true) {
        string input;
        cout << "Enter the word for query, or enter 'q' to exit: ";
        if (cin >> input && input.length() > 0 && input != "q") {
            QueryResult res = tq.query(input);
            print(cout, res) << endl;
        } else {
            cout << "Exit." << endl;
            break;
        }
    }
}