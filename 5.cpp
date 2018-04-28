#include <bits/stdc++.h>
using namespace std;

int size(vector<int> a, vector<string> parts) {
    int sum = 0;
    for (auto i : a) {
        sum += parts[a[i]].size();
    }
    return sum;
}

bool is_match(string a, int n, string b, int m) {
    int asize = a.size();
    int bsize = b.size();
    for (int i = n, j = m; i < asize && j < bsize; i++, j++) {
        if (a[i] != b[i]) {
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

vector<int> orig(vector<int> a, vector<int> b, vector<string> parts) {
    int alen = size(a, parts);
    int blen = size(b, parts);
    printf("%d %d", alen, blen);
    cout << endl;
    if (alen == blen && alen != 0) {
        a.insert(a.end(), b.begin(), b.end());
        sort(a.begin(), a.end());
        return a;
    } else {
        if (alen >= blen) {
            vector<int> aux = b;
            b = a;
            a = aux;
            int auxlen = blen;
            blen = alen;
            alen = auxlen;
        }
        int dif = blen - alen;
        string last = parts[b.back()];
        int nparts = parts.size();
        for (int i = 0; i < nparts; i++) {
            if (!is_in(a, i) && !is_in(b, i)) {
                a.push_back(i);
                if (is_match(parts[i], 0, last, last.size() - dif)) {
                    vector<int> o = orig(a, b, parts);
                    cout << "hola " << i << endl;
                    if (!o.empty()) {
                        return o;
                    }
                }
                a.pop_back();
            }
        }
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
    b.push_back(0);
    printf("hue");
    for (auto i : orig(a, b, tokens)) {
        printf("%d,", i);
        printf("hue");
    }
    printf("hue");
    printf("\n");
    return 0;


}
