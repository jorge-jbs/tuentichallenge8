#include <bits/stdc++.h>
using namespace std;

int size(vector<int> & a, vector<string> & parts) {
    int sum = 0;
    for (auto i : a) {
        sum += parts[i].size();
    }
    return sum;
}

bool is_match(string a, int n, string b, int m) {
    int asize = a.size();
    int bsize = b.size();
    for (int i = n, j = m; i < asize && j < bsize; i++, j++) {
        if (a[i] != b[j]) {
            return false;
        }
    }
    return true;
}

bool is_in(vector<int> xs, int y) {
    for (auto x : xs) {
        if (x == y) return true;
    }
    return false;
}

bool orig(vector<int> & a, vector<int> & b, vector<string> parts) {
    int alen = size(a, parts);
    int blen = size(b, parts);
    if (alen == blen && alen != 0) {
        return true;
    } else {
        int dif = abs(blen - alen);
        string last;
        if (alen < blen) {
            last = parts[b.back()];
        } else {
            last = parts[a.back()];
        }
        int nparts = parts.size();
        for (int i = 0; i < nparts; i++) {
            if (!is_in(a, i) && !is_in(b, i)) {
                if (alen < blen) {
                    a.push_back(i);
                } else {
                    b.push_back(i);
                }
                if (is_match(parts[i], 0, last, last.size() - dif)) {
                    if (orig(a, b, parts)) {
                        return true;
                    }
                }
                if (alen < blen) {
                    a.pop_back();
                } else {
                    b.pop_back();
                }
            }
        }
        return false;
    }
}

int main() {
    string s;
    getline(cin, s);

    // All messages are passed to this program. It is its responsibility to
    // discard info messages.
    if (s[0] == '>') return 0;

    stringstream ss(s);

    string part;
    vector<string> parts;
    while (getline(ss, part, ' ')) {
        parts.push_back(part);
    }

    vector<int> a;
    vector<int> b;

    int i = 0;
    b.push_back(i);
    do {
        b.pop_back();
        b.push_back(i);
        i++;
    } while (!orig(a, b, parts));

    a.insert(a.end(), b.begin(), b.end());
    sort(a.begin(), a.end());

    for (i = 0; i < a.size() - 1; i++) {
        printf("%d,", a[i]+1);
    }
    printf("%d", a[i]+1);
    cout << endl;
    return 0;
}
