#include <bits/stdc++.h>
using namespace std;

struct tDoor {
    int t;
    int p;
};

int next(int t1, int p1, int n1, int t2, int p2) {
    int a = t1 + p1 * n1 + 1 - t2;
    return a % p2 == 0 ? a / p2 : -1;
}

bool match(vector<tDoor> doors, int i, int n) {
    if (i >= doors.size()-1) {
        return true;
    } else {
        n = next(doors[i].t, doors[i].p, n, doors[i+1].t, doors[i+1].p);
        return n > -1 && match(doors, i+1, n);
    }
}

unsigned int gcd(unsigned int u, unsigned int v) {
    // simple cases (termination)
    if (u == v)
        return u;

    if (u == 0)
        return v;

    if (v == 0)
        return u;

    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }

    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);

    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);

    return gcd((v - u) >> 1, u);
}

int main() {
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        int d;
        scanf("%d", &d);
        vector<tDoor> doors;
        for (int j = 0; j < d; j++) {
            int p, t;
            scanf("%d %d", &p, &t);
            doors.push_back({ .t = -t, .p = p });
        }
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
            int n = 1;
            while (!match(doors, 0, n)) {
                n++;
            }
            printf("Case #%d: %d", i+1, doors[0].t + doors[0].p * n);
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
