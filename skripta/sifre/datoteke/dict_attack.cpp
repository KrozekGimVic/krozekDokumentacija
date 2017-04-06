#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    if (s == "onomatopoeiapassword") {
        cout << "Pravilno. Naslednja naloga te čaka na:\nhttp://prog.gimvic.org/krozekDokumentacija/_build/html/_static/hack_prog/timed_9uSAmlo8zZ4z2AIKf3Aw9YXpeWooIt2lfotbujB5\n";
    } else {
        cout << "nepravilno" << std::endl;
    }

    return 0;
}
