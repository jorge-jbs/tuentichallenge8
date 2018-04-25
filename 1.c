#include <stdio.h>

int main() {
    int c;
    scanf("%d\n", &c);
    for (int i = 0; i < c; i++) {
        int n, m;
        scanf("%d %d\n", &n, &m);
        printf("Case #%d: %d\n", i + 1, (n - 1) * (m - 1));
    }
    return 0;
}
