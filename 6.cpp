// C++14 needed

#include <bits/stdc++.h>
using namespace std;

struct tSchedule {
    int press;
    int release;
};

bool operator<(tSchedule a, tSchedule b) {
    return a.release < b.release;
}

int best_score(map<tSchedule, int> blocks, auto last_block, int points) {
    //printf("%d ", points);
    auto it = last_block;
    ++it;
    while (it != blocks.end()) {
        cout << points << endl;
        if (last_block->first.release <= it->first.press) {
            points = max(points, best_score(blocks, it, it->second + points));
        }
        it++;
    }
    return points;
}

/*
int best_score(map<tSchedule, int> blocks, int last_block, int time, int points) {
    int i = last_block + 1;
    while (i < blocks.size()) {
        if ((blocks.begin() + last_block).first.release <= (blocks.begin() + i).first.press) {
            points = max(points, best_score(blocks, i, blocks[i].release, blocks[i].second + points))
        }
        i++;
    }
    return points;
}
*/

int main() {
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        cout << "hue" << endl;
        int n;
        scanf("%d", &n);
        map<tSchedule, int> blocks;
        for (int j = 0; j < n; j++) {
            cout << "huo " << j << " " << n << endl;
            int x, l, s, p;
            scanf("%d %d %d %d", &x, &l, &s, &p);
            cout << "1" << endl;
            tSchedule sched = { .press = x/s, .release = (x+l)/s };
            cout << "2" << endl;
            auto em = blocks.emplace(pair<tSchedule, int>(sched, p));
            cout << "3" << endl;
            if (!em.second) {
                cout << "4" << endl;
                em.first->second += p;
            }
            cout << "5" << endl;
        }
        cout << "hola" << endl;
        printf("%d\n", best_score(blocks, blocks.begin(), 0));
    }
}
