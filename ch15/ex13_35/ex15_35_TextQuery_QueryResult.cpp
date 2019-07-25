#include "ex15_35_StrBlob_StrBlobPtr.h"
#include "ex15_35_TextQuery_QueryResult.h"
#include "headers.h"

using namespace std;

void operator<<(ostream& os, const QueryResult& qr) {
    if (qr.line_nos->size() == 0) {
        os << "Not found." << endl;
    } else {
        os << qr.line_nos->size() << " lines found." << endl;
        for (TextQuery::lineNo ln : *(qr.line_nos)) {
            cout << "\t(line " << ln << ")\t" << StrBlobPtr(*(qr.file_lines_sp), ln).deref() << endl;
        }
    }
}

TextQuery::TextQuery(istream& is) : file_lines_sp(new StrBlob()) {
    string line;
    lineNo curr = -1;
    while (getline(is, line)) {
        file_lines_sp->push_back(line);
        ++curr;
        istringstream iss(line);
        string word;
        while (iss >> word) {
            if (word_map.find(word) != word_map.end()) {
                auto pair_p = word_map.find(word);
                (pair_p->second)->insert(curr);
            } else {
                word_map[word] = shared_ptr<set<lineNo>>(new set<lineNo>{curr});
            }
        }
    }
}

QueryResult TextQuery::query(const string& target) const {
    // TODO: The static variable is defined here, so sure of the reason
    static shared_ptr<set<lineNo>> not_found(new set<lineNo>()); 
    
    auto p = word_map.find(target);
    if (p->second->size() > 0) {
        return QueryResult(target, file_lines_sp, p->second);
    } else {
        return QueryResult(target, file_lines_sp, not_found);
    }
}