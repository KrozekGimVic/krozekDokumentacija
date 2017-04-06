#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    // pass = udboxwcs
    if (s.size() == 8 && s[0] == 117 && s[1] == 100 && s[2] == 98 && s[3] == 111 && s[4] == 120 && s[5] == 119 && s[6] == 99 && s[7] == 115) {
        cout << "Pravilno. Naslednja naloga te čaka na:\nhttp://prog.gimvic.org/krozekDokumentacija/_build/html/_static/hack_prog/dict_NvG7LvJm6XaNCYM56Jfa5UjKNiYnO3jqWUT8lCq5\n";
    } else {
        cout << "nepravilno" << std::endl;
    }

    return 0;
}
