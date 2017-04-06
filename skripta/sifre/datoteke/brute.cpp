#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

int main() {
    std::string comm = "echo udboxw | ./brute_force";
    for (comm[5] = 'a'; comm[5] <= 'z'; comm[5]++)
    for (comm[6] = 'a'; comm[6] <= 'z'; comm[6]++)
    for (comm[7] = 'a'; comm[7] <= 'z'; comm[7]++) {
        // comm[5] = s;
        const char* c = &comm[0];
        printf("%s: ", c);
        fflush(stdout);
        system(c);
    }
}
