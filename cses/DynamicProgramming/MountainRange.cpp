#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;

struct DSU {
    vi par, val;

    DSU(int n) {
        par = vi(n);
        iota(par.begin(), par.end(), 0);
        val = vi(n, 1);
    }

    int find(int u) {
        if (u == par[u]) return u;
        return par[u] = find(par[u]);
    }

    void merge(int u, int v) {
        int p1 = find(u), p2 = find(v);
        par[p2] = p1;
        val[p1] = max(val[p1], val[p2]);
    }

    void set(int i, int v) {
        val[find(i)] = v;
    }

    int get(int i) {
        return val[find(i)];
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vi nums(n);
    map<int, vi> ind;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        ind[nums[i]].push_back(i);
    }


    DSU dsu(n);

    for (auto [num, is] : ind) {
        vector<pii> to_merge;
        for (int i : is) {
            if (i && nums[i-1] < nums[i]) {
                to_merge.emplace_back(i, i-1);
            }
            if (i < n - 1 && nums[i+1] < nums[i]) {
                to_merge.emplace_back(i, i+1);
            }
        }

        set<int> unique_parents;
        for (auto [u, v] : to_merge) {
            dsu.merge(u, v);
        }
        for (auto [u, v] : to_merge) {
            unique_parents.insert(dsu.find(u));
            unique_parents.insert(dsu.find(v));
        }

        for (int unique_parent : unique_parents) {
            dsu.set(unique_parent, dsu.get(unique_parent) + 1);
        }
    }

    cout << *max_element(dsu.val.begin(), dsu.val.end()) << "\n";


}