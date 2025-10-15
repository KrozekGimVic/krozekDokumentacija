#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

std::vector<std::string> split(const std::string& str, const std::string& delim) {
    assert(!delim.empty() && "Delimiter must not be empty.");
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        tokens.emplace_back(str.substr(prev, pos-prev));
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    if (prev == str.length()) tokens.emplace_back("");
    return tokens;
}

enum class GradeType { WRITTEN, ORAL };

struct Entry {
    std::string first_name, last_name, course;
    int grade;
    GradeType grade_type;
};

int main() {
    std::vector<Entry> entries;

    std::string s;
    while (getline(cin, s)) {
        auto d = split(s, ",");
        Entry e;
        e.first_name = d[0];
        e.last_name = d[1];
        e.course = d[2];
        e.grade = stoi(d[3]);
        e.grade_type = (d[4] == "ustno") ? GradeType::ORAL : GradeType::WRITTEN;

        entries.push_back(e);
    }

    for (const Entry& e : entries) {
        cout << e.first_name << " " << e.last_name << " je pri predmetu " << e.course
              << " dobil " << ((e.grade_type == GradeType::ORAL) ? "ustno" : "pisno") << " oceno "
              << e.grade << ".\n";
    }

    return 0;
}
