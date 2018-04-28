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
        //printf("%c<->%c", a[i], b[i]);
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
    //printf("%d %d", alen, blen);
    //cout << endl;
    if (alen == blen && alen != 0) {
        /*
        a.insert(a.end(), b.begin(), b.end());
        sort(a.begin(), a.end());
        return a;
        */
        return true;
    } else {
        /*
        if (alen >= blen) {
            vector<int> aux = b;
            b = a;
            a = aux;
            int auxlen = blen;
            blen = alen;
            alen = auxlen;
        }
        */
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
                    //cout << "hola " << i << endl;
                    if (orig(a, b, parts)) {
                        //cout << "nos vamos" << endl;
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

/*
pair<vector<int>, vector<int> > cont(vector<int> a, vector<int> b, vector<string> parts) {
    int alen = size(a);
    int blen = size(b);
    if (alen < blen) {
        int dif = blen - alen;
        string last = parts[b.back()];
        for (auto p : parts) {
            //if (p `is not in a or b`) {

            //}
        }
    } else {
    }
}

vector<int> orig(vector<string> parts) {
    int len = parts.size();
    for (int i = 0; i < len; i++) {
    }
}
*/


int main() {
    string s;
    getline(cin, s);

    if (s[0] == '>') return 0;

    stringstream ss(s);

    string item;
    vector<string> tokens;
    while (getline(ss, item, ' ')) {
        tokens.push_back(item);
    }
    //cout << tokens[1];
    vector<int> a;
    vector<int> b;

    int i = 0;
    b.push_back(i);
    do {
        b.pop_back();
        b.push_back(i);
        i++;
    } while (!orig(a, b, tokens));

    a.insert(a.end(), b.begin(), b.end());
    sort(a.begin(), a.end());

    for (i = 0; i < a.size() - 1; i++) {
        printf("%d,", a[i]+1);
    }
    printf("%d", a[i]+1);
    cout << endl;
    return 0;


}
