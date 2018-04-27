#include <bits/stdc++.h>
using namespace std;

enum tSquare { GROUND, TRAMP, LAVA };

int main() {
    int c;
    scanf("%d\n", &c);
    for (int case_ = 0; case_ < c; case_++) {
        int n, m;
        scanf("%d %d\n", &n, &m);
        printf("%d %d\n", n, m);
        vector<tSquare> map;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                scanf("%c", &c);
                switch (c) {
                case '.': case 'S': case 'P': case 'D': map.push_back(GROUND); break;
                case '*':                               map.push_back(TRAMP); break;
                case '#':                               map.push_back(LAVA); break;
                default: return -1;
                }
                printf("%d", map[i*n+j]);
            }
            scanf("\n");
            printf("\n");
        }
    }
}
