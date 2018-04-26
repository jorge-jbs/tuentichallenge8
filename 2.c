#include <stdio.h>
#include <string.h>

void print_uint128(__uint128_t n) {
    if (n == 0) {
        printf("0");
        return;
    }
    char str[40] = {0};
    char *s = str + sizeof(str) - 1;
    while (n != 0 && s != str) {
        --s;
        *s = "0123456789"[n % 10];
        n /= 10;
    }
    printf("%s", s);
}

__uint128_t dif(int b) {
    __uint128_t res = 0;
    __uint128_t n = 1;
    for (int i = 0, j = b - 1; j >= 2; i++, j--) {
        res += (j-i)*n;
        n *= b;
    }
    return (b - 2)*n*b + (b - 2)*n - res;
}

int main() {
    int t;
    scanf("%d\n", &t);
    char s[27];
    for (int i = 0; i < t; i++) {
        scanf("%s\n", &s);
        int b = strlen(s);
        printf("Case #%d: ", i + 1);
        print_uint128(dif(b));
        printf("\n");
    }
}
