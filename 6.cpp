// C++14 needed

#include <bits/stdc++.h>
using namespace std;

struct tSchedule {
    int press;
    int release;
};

bool operator<(tSchedule a, tSchedule b) {
    if (a.release < b.release) {
        return true;
    } else if (a.release > b.release) {
        return false;
    }
    return a.press < b.press;
}

bool operator==(tSchedule a, tSchedule b) {
    return a.press == b.press && a.release == b.release;
}

int score_memo[10000];
bool score_visited[10000] = { false };

int best_score(vector<pair<tSchedule, int> > blocks, int last_block) {
    if (score_visited[last_block]) return score_memo[last_block];
    int best = 0;
    for (int i = last_block+1; i < blocks.size(); i++) {
        if (blocks[last_block].first.release < blocks[i].first.press) {
            best = max(best, blocks[i].second + best_score(blocks, i));
        }
    }
    score_memo[last_block] = best;
    score_visited[last_block] = true;
    return best;
}

int best_best_score(vector<pair<tSchedule, int> > blocks) {
    int score = 0;
    memset(score_visited, false, sizeof(score_visited));
    for (int i = 0; i < blocks.size(); i++) {
        score = max(score, blocks[i].second + best_score(blocks, i));
    }
    return score;
}

int main() {
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        int n;
        scanf("%d", &n);
        vector<pair<tSchedule, int> > blocks;
        for (int j = 0; j < n; j++) {
            int x, l, s, p;
            scanf("%d %d %d %d", &x, &l, &s, &p);
            tSchedule sched = { .press = x/s, .release = (x+l)/s };
            blocks.push_back(pair<tSchedule, int>(sched, p));
        }
        sort(blocks.begin(), blocks.end());
        for(int j = 0; j < blocks.size() - 1; j++) {
            if (blocks[j].first == blocks[j+1].first) {
                blocks[j].second += blocks[j+1].second;
                blocks.erase(blocks.begin() + j + 1);
                j--;
            }
        }
        printf("Case #%d: %d\n", i+1, best_best_score(blocks));
    }
}
