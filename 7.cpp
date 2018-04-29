#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[10];
    vector<char> out;
    while (scanf("%s", s) != -1) {
        if (strcmp(s, "pipi") == 0) out.push_back('>');
        else if (strcmp(s, "pichu") == 0) out.push_back('<');
        else if (strcmp(s, "pi") == 0) out.push_back('+');
        else if (strcmp(s, "ka") == 0) out.push_back('-');
        else if (strcmp(s, "pikachu") == 0) out.push_back('.');
        else if (strcmp(s, "pikapi") == 0) out.push_back(',');
        else if (strcmp(s, "pika") == 0) out.push_back('[');
        else if (strcmp(s, "chu") == 0) out.push_back(']');
        /*
        if (strcmp(s, "pipi") == 0) printf(">");
        else if (strcmp(s, "pichu") == 0) printf("<");
        else if (strcmp(s, "pi") == 0) printf("+");
        else if (strcmp(s, "ka") == 0) printf("-");
        else if (strcmp(s, "pikachu") == 0) printf(".");
        else if (strcmp(s, "pikapi") == 0) printf(",");
        else if (strcmp(s, "pika") == 0) printf("[");
        else if (strcmp(s, "chu") == 0) printf("]");
        */
    }
    reverse(out.begin(), out.end());
    for (auto c : out) {
        printf("%c", c);
    }
    printf("\n");
}
