#include <iostream>
#include <string>

using namespace std;

int main() {
    string pass1 = "bbbbbaaabaabaababbbbaabaaabbbbaababaaaabaabaaaaabbbbabaabbaabaaaaababbbbbbbabbbaabbbababbaaabababbaababbaabbabbbbabbaabaabbbbaabaabbaaababaabbbbabbaaaaabaaaaabbabbbbabaaababaaabaabaabbaaaaaaaabaaabbaabaabbabbbaabababbbaaaabbaabbabbbabbbaababbbababaababbaaabbbababbbbbbbbaababbbabbaaababbaabbbaabbaabbabbaabaabbaaaaababbbbabbbbabaaaaaaaabaaabbaaaabbbbbbaaabbaaaabbbbbaaaaaabbbbbbabbbababbbabbaaaabaababbbbabbaabbaaabbababbbaabaabbabababbaabababaabbaababaaaabbbabaabaaabbaabababbabbaabbaababaabbaabaaaaabbabbaabaabbbabbabbababbbbabbbbaabbabbbabbaabaaaababbbbbaaaaaabaabbabaabaaaabbaabaaaaaababbbbbabbbbbbabaabbbbababbaabbabbbabbbabababbaaabbbabbaabbabbbbabaabbbaabbbbbaabbbbbababababbabaaabbaababaaaabbaabaaabbbabbbbaabbabbbababaaaabbbbabbbaabbbabbaaabbbbbbbbabaaabababaaabaababaabababbbbabbaabaabbababaabbbbbabbbbbabbbbaaaaabaaaabaabaaabaabbaaaaaaaabbabaabbabaaabbbbaaabbbabbbbababbbbbbababaaaaabbbbaabaaabaabbabaabbabaaababababbababbbbbbaaabbababaabbbbbabbbbabbbaaabaabbabaaaabaabbaabbaabaaabaabbbbba";
    string pass2 = "aabbbbbabaaaaababbaaaabbbaabaabbbbbabbababaaaababababaaaabbabaabbababaaabaaabaaabbabbbbbbabaaababaaaabbaabbbbaaaabbbaabaabaabbbbbbaaabaabbaaabaabbabbababbaabbabbababbaaabbbbaaabababbbababbabbbabaababbabaabbbabbaaababbabaaaaaabbbbbabaaabaaaabaababaabababbabbabababaaaaabbaaabbaaaaabbaabbbbabaabbbbbbaabaabababbaaabbbaaababaabbabbabbaabbbaabbaaaaaabbbaaabaabaabaabbaaaaaabaabbbabbbbbbaabbbbbababbababbabbababaaaaaabaaabbaababbaabbaabbaaabaabbaabbbaaabbaabbbbbbabaaabbabbababbbbbbbaabababbbbaaabaaaaaabbabbbabaabababbbbbbababbbabaaababaaabbaabaaabbabbbbabbbbbbbaaabbabbbbbbaaabaaabbbbaabbbaaaabbbbbabababbabaabaaabbbabaaaabbbababbababbaaabbbbbababbabbaababbbaabababbaabaabbaababbbbaabbbbbaabaaabbaabbbbbababaaabbabbaaaabbbabaaaabbbbabbabaabbaaaabbabbbabbabaabbaabababbbababbbaaabbaabaaaabbbabbbbbaabaaababaaabbaabaaabbbbbbaabaaaaabbbabababbbbbbbaaaaaaabbbbaabbabbbbabaaabbbabbaaaabbbaabbabbbbbbabbbaaaabaaabbbbbbbabbbababaabbbbabbabbabaaabaaabababaabaaababbbaaabaabbbaaababbbabababbaaaaaabbabbaaaababbba";

    string s;
    getline(cin, s);

    bool prav = true;

    if (s.size() != 1000) {
        cout << "napacno" << std::endl;
        prav = false;
    } else {
        for (int i = 0; i < 1000; ++i) {
            int num = (pass1[i] + pass2[i]) % 2;
            if (num == 0 && s[i] != 'a') {
                cout << "napacno" << endl;
                prav = false;
                return 1;
            }

            if (num == 1 && s[i] != 'b') {
                cout << "napacno" << endl;
                prav = false;
                return 1;
            }
        }
    }

    if (prav) cout << "meatspin.com" << endl;

    return 0;
}
