#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    if (s.size() == 8 && s[0] == 117 && s[1] == 100 && s[2] == 98 && s[3] == 111 && s[4] == 120 && s[5] == 119 && s[6] == 99 && s[7] == 115) {
        cout << "meatspin.com" << std::endl;
    } else {
        cout << "nepravilno" << std::endl;
    }

    return 0;
}
