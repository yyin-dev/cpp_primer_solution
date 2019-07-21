#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include "headers.h"

class QueryResult;

class TextQuery {
   public:
    TextQuery(const string& file = "./ex12_27_input.txt") {
        ifstream ifs(file);
        string line;
        while (getline(ifs, line)) {
            if (line.length() > 50) {
                line = line.substr(0, 50);
            }
            istringstream iss(line);
            string word;
            while (iss >> word) {
                word2lineNums[word].push_back(lines.size());
            }
            lines.push_back(line);
        }
    }

    QueryResult query(const string& keyword) {
        map<int, string> lineNum2text;

        for (auto lineNum : word2lineNums[keyword]) {
            lineNum2text[lineNum] = lines[lineNum];
        }
        return QueryResult(keyword, lineNum2text);
    }

   private:
    // You cannot use () to initialize data members in class!!!! Use {} or = instread.
    vector<string> lines;
    map<string, vector<int>> word2lineNums;
};

#endif