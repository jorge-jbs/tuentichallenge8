#include <bits/stdc++.h>
using namespace std;

enum tSquare { GROUND = 0, TRAMP = 1, LAVA = 2 };

struct tCoord {
    int x;
    int y;
};

tCoord operator+(const tCoord & u, const tCoord & v) {
    tCoord w;
    w.x = u.x + v.x;
    w.y = u.y + v.y;
    return w;
}

const bool operator==(const tCoord & u, const tCoord & v) {
    return u.x == v.x && u.y == v.y;
}

const bool operator<(const tCoord & u, const tCoord & v) {
    if (u.x < v.x) {
        return true;
    } else if (u.x > v.x) {
        return false;
    } else {
        return u.y < v.y;
    }
    //return u.x < v.x && u.y < v.y;
}

bool is_in(tCoord u, int n, int m) {
    bool res = u.x >= 0 && u.x < m && u.y >= 0 && u.y < n;
    //printf("%d %d (%d %d) (%d);  ", u.x, u.y, n, m, res);
    return res;
}

struct tNode {
    tCoord pos;
    int cost;
};

tCoord DEST;

double distance(tCoord u, tCoord v) {
    return sqrt(pow(u.x-v.x, 2) + pow(u.y-v.y, 2));
}

const bool operator<(const tNode & a, const tNode & b) {
    //return a.cost + distance(a.pos, DEST) >= b.cost + distance(b.pos, DEST);
    return a.cost >= b.cost;
}

/*
const bool operator==(const tNode & a, const tNode & b) {
    return a.pos == b.pos;
}
*/

int best_path(vector<tSquare> map, int n, int m, tCoord from, tCoord to) {
    DEST = to;
    tNode node = { .pos = from, .cost = 0 };
    priority_queue<tNode> frontier;
    frontier.push(node);
    set<tCoord> explored;
    while (true) {
        if (frontier.empty()) return -1;
        //printf("%d ", frontier.size());
        node = frontier.top();
        frontier.pop();
        explored.insert(node.pos);
        //printf("%d, %d;  ", node.pos.x, node.pos.y);
        if (node.pos == to) return node.cost;
        tCoord small_jump[8] = {
            { .x =  2, .y =  1 },
            { .x = -2, .y =  1 },
            { .x =  2, .y = -1 },
            { .x = -2, .y = -1 },
            { .x =  1, .y =  2 },
            { .x =  1, .y = -2 },
            { .x = -1, .y =  2 },
            { .x = -1, .y = -2 }
        };
        tCoord big_jump[8] = {
            { .x =  4, .y =  2 },
            { .x = -4, .y =  2 },
            { .x =  4, .y = -2 },
            { .x = -4, .y = -2 },
            { .x =  2, .y =  4 },
            { .x =  2, .y = -4 },
            { .x = -2, .y =  4 },
            { .x = -2, .y = -4 }
        };
        tCoord *jump;
        if (map[node.pos.y*m + node.pos.x] == GROUND) {
            jump = small_jump;
        } else {
            jump = big_jump;
        }
        for (int i = 0; i < 8; i++) {
            tNode child = { .pos = node.pos + jump[i], .cost = node.cost + 1 };
            //printf("%d %d (%d);  ", child.pos.x, child.pos.y, map[child.pos.y*m + child.pos.x]);
            if (is_in(child.pos, n, m) && map[child.pos.y*m + child.pos.x] != LAVA) {
                if (explored.find(child.pos) == explored.end()) {
                    //printf("%d, %d;  ", child.pos.x, child.pos.y);
                    //for (auto u : explored) printf("%d,%d; ", u.x, u.y);
                    //printf("\n");
                    frontier.push(child);
                    explored.insert(child.pos);
                }
            }
        }
    }
}

/*
  int best_path(vector<tSquare> map, int n, int m, tCoord from, tCoord to) {
  if (from == to) return 0;
    int best = std::numeric_limits<int>::max();
    tCoord dirs[8] = {
        { .x =  2, .y =  1 },
        { .x = -2, .y =  1 },
        { .x =  2, .y = -1 },
        { .x = -2, .y = -1 },
        { .x =  1, .y =  2 },
        { .x =  1, .y = -2 },
        { .x = -1, .y =  2 },
        { .x = -1, .y = -2 }
    };
    for (int i = 0; i < 8; i++) {
        tCoord from_ = from + dirs[i];
        if (is_in(from_, n, m) && map[from_.y*n + from_.x] != LAVA) {
            best = min(best, 1 + best_path(map, n, m, from_, to));
        }
    }
    return best;
}
*/

int main() {
    int c;
    scanf("%d\n", &c);
    for (int case_ = 0; case_ < c; case_++) {
        int n, m;
        scanf("%d %d\n", &n, &m);
        //printf("%d %d\n", n, m);
        vector<tSquare> map;
        tCoord s, p, d;
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
                //cout << "hueee";
                if (c == 'S') s = { .x = j, .y = i };
                else if (c == 'P') p = { .x = j, .y = i };
                else if (c == 'D') d = { .x = j, .y = i };
                //printf("%d", map[i*n+j]);
            }
            scanf("\n");
            //printf("\n");
        }
        //printf("%d %d; %d %d; %d %d\n", s.x, s.y, p.x, p.y, d.x, d.y);
        int p1 = best_path(map, n, m, s, p);
        int p2 = best_path(map, n, m, p, d);
        printf("Case #%d: ", case_+1);
        if (p1 > 0 && p2 > 0) {
            printf("%d", p1 + p2);
        } else {
            printf("IMPOSSIBLE");
        }
        printf("\n");
    }
}
