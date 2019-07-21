#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include "headers.h"

class QueryResult;

class TextQuery {
    using lineNum = vector<string>::size_type;

   public:
    // The initialization list here is important.
    // this->lines is a shared_ptr and is initialized to 
    // be a nullptr. Thus, when you dereference it, 
    // the behavior is undefined. (In our case, the
    // program terminates without warning or error.)
    // You need to initialize the shared_ptr, with
    // a pointer returned by new or another shared_ptr. 
    TextQuery(const string& file = "./ex12_27_input.txt"): lines(new vector<string>) {
        ifstream ifs(file);
        string line;
        while (getline(ifs, line)) {
            if (line.length() > 50) {
                line = line.substr(0, 50);
            }
            lines->push_back(line);

            istringstream iss(line);
            string word;
            while (iss >> word) {
                auto& lineNums = word2lineNums[word];
                if (!lineNums) {
                    lineNums.reset(new set<lineNum>());
                }
                lineNums->insert(lines->size() - 1);
            }
        }
        cout << "***";
    }

    QueryResult query(const string& keyword) const {
        static shared_ptr<set<lineNum>> notFound(new set<lineNum>());

        auto p = word2lineNums.find(keyword);
        if (p != word2lineNums.end()) {
            return QueryResult(keyword, lines, p->second);
        } else {
            return QueryResult(keyword, lines, notFound);
        }
    }

   private:
    shared_ptr<vector<string>> lines;
    map<string, shared_ptr<set<lineNum>>> word2lineNums;
};

#endif