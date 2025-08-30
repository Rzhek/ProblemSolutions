#include <bits/stdc++.h>
using namespace std;


const int maxn = 10;
int n, m, transition[maxn][maxn];

int solve(int cur, int nxt, int i) {
    // base case
    if (i == n) {
        // TODO: what?
        return;
    }

    int res = 0;

    // if can place vertical
    if ((cur & (1 << i)) == 0 && (nxt & (1 << i)) == 1) {
        res += solve(cur + (1 << i), nxt - (1 << i), i + 1);
    }

    // place horizontal
    if (i + 2 <= n) {
        int delta = (1 << i) + (1 << (i + 1));
        cur += delta;
        nxt += delta;
    }
    return 0;
}




int main() {
    for (int from = 0; from < (1 << maxn); from++) {
        for (int to = 0; to < (1 << maxn); to++) {
            transition[from][to] = solve(from, to, 0);
        }
    }
}