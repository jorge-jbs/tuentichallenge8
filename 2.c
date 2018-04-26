#include <stdio.h>
#include <string.h>

int print_uint128(__uint128_t n) {
    if (n == 0)  return printf("0\n");

    char str[40] = {0}; // log10(1 << 128) + '\0'
    char *s = str + sizeof(str) - 1; // start at the end
    while (n != 0) {
        if (s == str) return -1; // never happens

        *--s = "0123456789"[n % 10]; // save last digit
        n /= 10;                     // drop it
    }
    return printf("%s\n", s);
}

__uint128_t dif3(int b) {
    __uint128_t res = 0;
    __uint128_t n = 1;
    for (int i = 0, j = b - 1; j >= 2; i++, j--) {
        res += (j-i)*n;
        n *= b;
    }
    return (b - 2)*n*b + (b - 2)*n - res;
}

long long unsigned int dif2(int b) {
    long long unsigned int res = 0;
    long long unsigned int n = 1;
    for (int i = 0, j = b - 1; j >= 2; i++, j--) {
        res += (j-i)*n;
        n *= b;
    }
    return (b - 2)*n*b + (b - 2)*n - res;
}

int dif(int b) {
    int res = 0;
    int n = 1;
    for (int i = 0; i < b - 2; i++) {
        res += n;
        n *= b;
    }
    return (b - 2)*n*b + (b - 2)*n - 2*res;
}

long long int max(int b) {
    int n = b;
    int res = 0;
    for (int i = 1; i < b; i++) {
        res += i*n;
        n *= b;
    }
    return res;
}

int main() {
    int t;
    scanf("%d\n", &t);
    char s[27];
    for (int i = 0; i < t; i++) {
        scanf("%s\n", &s);
        int b = strlen(s);
        //printf("Case #%d: %llu\n", i + 1, dif3(b));
        printf("Case #%d: ", i + 1);
        print_uint128(dif3(b));
    }
}
