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
        bool found = false;
        int n;
        for (n = 0; n < 1000000; n++) {
            //cout << "trying " << n << endl;
            if (match(doors, 0, n)) {
                found = true;
                break;
            }
        }
        if (found) {
            printf("Case #%d: %d", i+1, doors[0].t + doors[0].p * n);
        } else {
            printf("Case #%d: NEVER", i+1);
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
