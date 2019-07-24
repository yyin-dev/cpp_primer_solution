#include "headers.h"

class Employee {
    friend ostream& operator<<(ostream& os, const Employee& e);
    friend istream& operator>>(istream& is, Employee& e);
    friend bool operator==(const Employee& lhs, const Employee& rhs);
    friend bool operator!=(const Employee& lhs, const Employee& rhs);

   public:
    Employee(const char& g, const string& l, string w, set<string> skillset);
    Employee(const char& g);

    Employee(const Employee& other);
    Employee(Employee&& other);

    Employee& operator=(const Employee& rhs);
    Employee& operator=(Employee&& rhs);

    ~Employee();

   private:
    char gender = 'M';
    string level = "Junior";
    string worksite = "onsite";
    set<string>* skillset;

    void free();
};

Employee::Employee(const char& g, const string& l, string r, set<string> skillset = set<string>{"C++"})
    : gender(g), level(l), worksite(r), skillset(new set<string>(skillset)) {}

Employee::Employee(const char& g) : Employee(g, "Junior", "onsite") {}

Employee::Employee(const Employee& other)
    : gender(other.gender), level(other.level), worksite(other.worksite), skillset(new set<string>(*(other.skillset))) {}

Employee::Employee(Employee&& other)
    : gender(other.gender), level(other.level), worksite(other.worksite), skillset(other.skillset) {
    other.skillset = nullptr;
}

Employee& Employee::operator=(const Employee& rhs) {
    auto new_skillset = new set<string>(*(rhs.skillset));
    free();
    gender = rhs.gender;
    level = rhs.level;
    worksite = rhs.worksite;
    skillset = new_skillset;
    return *this;
}

Employee& Employee::operator=(Employee&& rhs) {
    if (*this != rhs) {
        free();

        gender = rhs.gender;
        level = rhs.level;
        worksite = rhs.worksite;
        skillset = rhs.skillset;

        rhs.skillset = nullptr;
    }
    return *this;
}

Employee::~Employee() { free(); }

void Employee::free() { delete skillset; }

// Friend functions and operators below
ostream& operator<<(ostream& os, const Employee& e) {
    os << e.gender << " "
       << " " << e.level << " " << e.worksite;
    os << "{ ";
    for (auto skill : *(e.skillset)) {
        cout << skill << " ";
    }
    cout << " }";
    return os;
}

istream& operator>>(istream& is, Employee& e) {
    is >> e.gender >> e.level >> e.worksite;
    string skill;
    while (is >> skill) {
        if (skill != "end") {
            e.skillset->insert(skill);
        } else {
            break;
        }
    }
    if (is) {
        e = Employee('M', "Junior", "onsite");
    }
}

bool operator==(const Employee& lhs, const Employee& rhs) {
    return (lhs.gender == rhs.gender && lhs.level == rhs.level && lhs.worksite == rhs.worksite);
}

bool operator!=(const Employee& lhs, const Employee& rhs) {
    return !(lhs == rhs);
}
