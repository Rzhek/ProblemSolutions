#include <bits/stdc++.h>
using namespace std;

#define printArr(arr) for (auto x : arr) cout << x << " "; cout << '\n'
#define print2DArr(arr) for (auto &x : arr) {printArr(x);}
#define forn(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int t; cin >> t; while (t--)
#define f first
#define s second

using ll = long long;
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

using board = tuple<pii, pii, pii, pii>;
map<board, board> visited;

board makeBoard(vpi &arr) {
    sort(all(arr), [](pii a, pii b) {
        if (a.f == b.f) return a.s < b.s;
        return a.f < b.f;
    });
    return {arr[0], arr[1], arr[2], arr[3]};
}

vpi move(vpi &old, int ind, int dr, int dc) {
    vpi res = old;
    vpi taken;
    for (int i = 0; i < 4; i++) {
        if (i == ind) continue;
        taken.emplace_back(old[i]);
    }

    int r = res[ind].f, c = res[ind].s; 
    while (0 <= r && r < 6 && 0 <= c && c < 6 && taken[0] != pii(r, c) && taken[1] != pii(r, c) && taken[2] != pii(r, c)) {
        r += dr;
        c += dc;
    }
    res[ind] = {r - dr, c - dc};
    return res;
}

vi findDiff(board &a, board &b) {
    auto &[a1, a2, a3, a4] = a;
    auto &[b1, b2, b3, b4] = b;
    set<pii> board1 = {a1, a2, a3, a4}, board2 = {b1, b2, b3, b4};
    for (auto &x : {b1, b2, b3, b4}) {
        if (board1.count(x)) {
            board1.erase(x);
            board2.erase(x);
        }
    }
    pii before = *board1.begin(), after = *board2.begin();
    return {before.f, before.s, after.f, after.s};
}

void printBoard(board &b) {
    cout << get<0>(b).f << " " << get<0>(b).s << ", ";
    cout << get<1>(b).f << " " << get<1>(b).s << ", ";
    cout << get<2>(b).f << " " << get<2>(b).s << ", ";
    cout << get<3>(b).f << " " << get<3>(b).s << "\n";
    cout << "==================\n";
}

vpi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    vpi init, final;
    forn(i, 4) {
        int r, c; cin >> r >> c;
        init.emplace_back(r, c);
    }
    forn(i, 4) {
        int r, c; cin >> r >> c;
        final.emplace_back(r, c);
    }

    board target = makeBoard(final);
    queue<pair<int, vpi>> q;
    q.emplace(0, init);
    vpi stop = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};
    visited[makeBoard(init)] = makeBoard(stop);
    int steps = 0;
    while (q.size()) {
        auto [w, cur] = q.front();
        q.pop();
        // cout << q.size() << "\n";
        board b = makeBoard(cur);
        if (b == target) {
            // cout << w << "\n";
            steps = w;
            break;
        }
        // if (visited.count(b)) continue;
        for (int i = 0; i < 4; i++) {
            for (auto [dr, dc] : dirs) {
                vpi next = move(cur, i, dr, dc);
                if (next == cur) continue;
                board newB = makeBoard(next);
                if (visited.count(newB)) continue;
                visited[newB] = b;
                q.emplace(w + 1, next);
            }
        }
    }

    cout << steps << "\n";
    vvi diff;
    // diff.pb(findDiff(target, visited[target]));
    // printBoard(target);
    // printBoard(visited[target]);
    while (steps--) {
        // printBoard(target);
        diff.pb(findDiff(target, visited[target]));
        target = visited[target];
    }
    // printBoard(target);

    // cout << diff.size() << "\n";
    for (int i = diff.size() - 1; i >= 0; i--) {
        cout << diff[i][2] << " " << diff[i][3] << " " << diff[i][0] << " " << diff[i][1] << "\n";
        // cout << diff[i].size() << "\n"; 
    }

    // printBoard(target);
    // target = visited[target];
    // printBoard(target);
    // target = visited[target];
    // printBoard(target);

    // vpi board = {{0, 0}, {0, 5}, {5, 0}, {5, 5}};
    // for (auto [x, y] : board) cout << x << " " << y << ", "; cout << '\n';
    // board = move(board, 1, -1, 0);
    // for (auto [x, y] : board) cout << x << " " << y << ", "; cout << '\n';


    
        
    

    
    return 0;
}