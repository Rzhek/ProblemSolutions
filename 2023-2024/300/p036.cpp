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

const ll inf = 1e18;
const int MOD = 1e9+7;
const long double EPS = 1e-9;
const vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Tree;
map<string, int> countMap;
map<string, set<pair<int, string>>> won;
map<string, Tree*> leafs;
struct Tree {
    // left wins right
    Tree *left, *right, *par;
    string val;
    Tree(string &team, Tree *p = nullptr) : val(team), par(p) {
        if (won[team].empty()) {
            leafs[team] = this;
            return;
        };
        auto it = won[team].end();
        it--;
        string other = it->second;
        won[team].erase(it);
        
        left = new Tree(team, this);
        right = new Tree(other, this);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int k, n; cin >> k >> n;
    map<string, vector<string>> wonTmp;
    forn (i, (1 << k) - 1) {
        string teamA, scoreA, tmp, teamB, scoreB;
        cin >> teamA >> scoreA >> tmp >> scoreB >> teamB;
        countMap[teamA]++;
        countMap[teamB]++;
        if (scoreA.find('(') != -1) {
            while (scoreA[0] != '(') scoreA = scoreA.substr(1, scoreA.size()-1);
            scoreA = scoreA.substr(1, scoreA.size()-2);
            while (scoreB[0] != '(') scoreB = scoreB.substr(1, scoreB.size()-1);
            scoreB = scoreB.substr(1, scoreB.size()-2);
        }
        if (stoi(scoreA) > stoi(scoreB)) {
            wonTmp[teamA].pb(teamB);
        } else {
            wonTmp[teamB].pb(teamA);
        }
    }

    for (auto &[win, lose] : wonTmp) {
        for (auto &l : lose) won[win].insert({countMap[l], l});
    }

    string winner;
    for (auto [k, v] : won) {
        if (v.size() > won[winner].size()) winner = k;
    }

    Tree tree(winner);

    forn (i, n) {
        string teamA, teamB; cin >> teamA >> teamB;
        int round = 0;
        Tree *a = leafs[teamA], *b = leafs[teamB];
        for (; a != b; round++) {
            a = a->par;
            b = b->par;
        }
        cout << round << "\n";
    }
    return 0;
}