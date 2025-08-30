#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) { printArr(x); }
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int tt; cin >> tt; while (tt--)
#define f first
#define s second

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vpi = vector<pii>;
using vpl = vector<pll>;
using iii = tuple<int, int, int>;

const vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;

const int maxn = 1e5+5;
vector<int> edges[maxn];
int leavesInSubTree[maxn], ableToTake[maxn], potions[maxn];

int countLeaves(int u, int par) {
    if (u != 0 && edges[u].size() == 1) return leavesInSubTree[u] = 1;
    for (int v : edges[u]) {
        if (v == par) continue;
        leavesInSubTree[u] += countLeaves(v, u);
    }
    return leavesInSubTree[u];
}

int countPotions(int u, int par) {
    int take = ableToTake[u];
    for (int v : edges[u]) {
        if (v == par) continue;
        take += countPotions(v, u);
    }
    return min(take, leavesInSubTree[u]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(leavesInSubTree, 0, sizeof leavesInSubTree);
    memset(ableToTake, 0, sizeof ableToTake);

    int n; cin >> n;
    forn (i, n) {
        int a; cin >> a;
        potions[i] = a-1;
    }

    forn (i, n-1) {
        int u, v; cin >> u >> v;
        --u; --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    int numLeaves = countLeaves(0, -1);
    forn (i, numLeaves) ableToTake[potions[i]]++;

    cout << countPotions(0, -1);
    return 0;
}