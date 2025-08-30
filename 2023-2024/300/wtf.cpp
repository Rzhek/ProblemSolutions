void addTop(queue<pair<int, vpi>> &q, int w, int ind, vpi &cur) {
    vpi next = cur;
    int early = 1;
    while (next[ind].f > 0 && early) {
        next[ind].f--;
        for (int i = 0; i < 4 && early; i++) {
            if (i == ind) continue;
            if (next[ind] == next[i]) {
                next[ind].f++;
                early = 0;
                break;
            }
        }
    }
    if (next[ind] == cur[ind]) return;
    board b = makeBoard(next);
    if (visited.count(b)) return;
    visited[b] = makeBoard(cur);
    q.emplace(w, next);
}

void addBottom(queue<pair<int, vpi>> &q, int w, int ind, vpi &cur) {
    vpi next = cur;
    int early = 1;
    while (next[ind].f < 5 && early) {
        next[ind].f++;
        for (int i = 0; i < 4 && early; i++) {
            if (i == ind) continue;
            if (next[ind] == next[i]) {
                next[ind].f--;
                early = 0;
                break;
            }
        }
    }
    if (next[ind] == cur[ind]) return;
    board b = makeBoard(next);
    if (visited.count(b)) return;
    visited[b] = makeBoard(cur);
    q.emplace(w, next);
}

void addLeft(queue<pair<int, vpi>> &q, int w, int ind, vpi &cur) {
    vpi next = cur;
    int early = 1;
    while (next[ind].s > 0 && early) {
        next[ind].s--;
        for (int i = 0; i < 4 && early; i++) {
            if (i == ind) continue;
            if (next[ind] == next[i]) {
                next[ind].s++;
                early = 0;
                break;
            }
        }
    }
    if (next[ind] == cur[ind]) return;
    board b = makeBoard(next);
    if (visited.count(b)) return;
    visited[b] = makeBoard(cur);
    q.emplace(w, next);
}

void addRight(queue<pair<int, vpi>> &q, int w, int ind, vpi &cur) {
    vpi next = cur;
    int early = 1;
    while (next[ind].s < 5 && early) {
        next[ind].s++;
        // cout << next[ind].s << "\n";
        for (int i = 0; i < 4 && early; i++) {
            if (i == ind) continue;
            if (next[ind] == next[i]) {
                next[ind].s--;
                early = 0;
                break;
            }
        }
    }
    if (next[ind] == cur[ind]) return;
    board b = makeBoard(next);
    if (visited.count(b)) return;
    visited[b] = makeBoard(cur);
    q.emplace(w, next);
}