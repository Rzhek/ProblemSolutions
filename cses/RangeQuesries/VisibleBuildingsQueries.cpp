#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5, maxk = 320;
int nxt[maxn], nextBig[maxn], isBig[maxn], nums[maxn], val[maxn];


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> stk;
    stk.push_back(0);

    for (int i = 1; i < n; i++) {
        while (stk.size() && nums[stk.back()] < nums[i]) {
            nxt[stk.back()] = i;
            stk.pop_back();
        }
        stk.push_back(i);
    }
    
    while (stk.size()) {
        nxt[stk.back()] = n;
        stk.pop_back();
    }

    memset(nextBig, -1, sizeof(nextBig));

    for (int i = 0; i < n; i++) {
        if (nextBig[i] != -1) continue;
        stk.push_back(i);
        while (nxt[stk.back()] != n && nextBig[stk.back()] == -1 && stk.size() < maxk) {
            stk.push_back(nxt[stk.back()]);
        }
        int big;

        if (nxt[stk.back()] == n) {
            big = n;
            val[big] = 0;
        } else if (stk.size() == maxk) {
            isBig[big = stk.back()] = 1;
            stk.pop_back();
            val[big] = 0;
        } else if (nextBig[stk.back()] != -1) {
            big = nextBig[stk.back()];
            stk.pop_back();
            val[big] = 0;
        } else assert(false);


        while (stk.size()) {
            val[stk.back()] = val[nxt[stk.back()]] + 1;
            nextBig[stk.back()] = big;
            stk.pop_back();
        }
    }

    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        int res = 0;
        while (nextBig[l] <= r) {
            res += val[l];
            l = nextBig[l];
        }
        while (l <= r) {
            res++;
            l = nxt[l];
        }
        cout << res << "\n";
    }
}