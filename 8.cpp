#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int llui;
typedef unsigned int uint;

struct tDoor {
    llui t;
    llui p;
};

bool match(vector<tDoor> & doors, int i, const llui & n) {
    if (i >= doors.size()-1) {
        return true;
    } else {
        tDoor d1 = doors[i];
        tDoor d2 = doors[i+1];
        llui a = d1.p * n + 1 + d2.t - d1.t;
        if (a % d2.p == 0) {
            return match(doors, i+1, a / d2.p);
        } else {
            return false;
        }
    }
}

unsigned int gcd(uint u, uint v) {
    if (u == v) return u;
    if (u == 0) return v;
    if (v == 0) return u;
    if (~u & 1) {
        if (v & 1) {
            return gcd(u >> 1, v);
        } else {
            return gcd(u >> 1, v >> 1) << 1;
        }
    }
    if (~v & 1) {
        return gcd(u, v >> 1);
    } else if (u > v) {
        return gcd((u - v) >> 1, v);
    } else {
        return gcd((v - u) >> 1, u);
    }
}

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

int main() {
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        int d;
        scanf("%d", &d);
        vector<tDoor> doors;
        for (int j = 0; j < d; j++) {
            unsigned int p, t;
            scanf("%d %d", &p, &t);
            doors.push_back({ .t = t, .p = p });
        }
        if (i < 90) continue;
        bool never = false;
        for (int k = 0; k < doors.size() - 1; k++) {
            if (gcd(doors[k].p, doors[k+1].p) != 1) {
                never = true;
                break;
            }
        }
        if (never) {
            printf("Case #%d: NEVER", i+1);
        } else {
            llui n = 1;
            while (!match(doors, 0, n)) {
                if (n % 100000000 == 0) cout << n << endl;
                n++;
            }
            printf("Case #%d: %llu", i+1, doors[0].p * n - doors[0].t);
        }
        cout << endl;
    }



    /*
    for (int n = 1; n < INT_MAX; n++) {
        if (is_next(-20, 21, n, -3, 27)) {
            printf("n is %d\n", n);
            return 0;
        }
    }
    printf("n not found\n");
    */
}
