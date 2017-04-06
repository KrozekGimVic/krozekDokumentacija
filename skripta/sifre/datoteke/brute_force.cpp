#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    // pass = udboxw
    if (s.size() == 6 && s[0] == 117 && s[1] == 100 && s[2] == 98 && s[3] == 111 && s[4] == 120 && s[5] == 119) {
        cout << "Pravilno. Naslednja naloga te čaka na:\nhttp://prog.gimvic.org/krozekDokumentacija/_build/html/_static/hack_prog/dict_NvG7LvJm6XaNCYM56Jfa5UjKNiYnO3jqWUT8lCq5\n";
    } else {
        cout << "nepravilno" << std::endl;
        return 1;
    }

    return 0;
}
