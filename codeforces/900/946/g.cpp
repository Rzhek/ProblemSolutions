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

int main() {
    tests {
        int n, x; cin >> n >> x;
        priority_queue<int> pq;
        int money = 0;
        int res = 0;
        forn (i, n) {
            int a; cin >> a;
            if (money >= a) {
                res++;
                pq.push(a);
                money -= a;
            } else if (pq.size() && pq.top() > a) {
                money += pq.top() - a;
                pq.pop();
                pq.push(a);
            }
            money += x;
        }
        cout << res << "\n";
    }
    return 0;
}


// template<class T, T (*e)(), T(*op)(T, T), class F, F (*id)(), T (*onto)(F, T), F (*comp)(F, F)>
// struct lazy_segtree {
//     int N, log, S;
//     vector<T> d;
//     vector<F> lz;
//     lazy_segtree(const vector<T>& v):
//         N(sz(v)), log(__lg(2 * N - 1)), S(1 << log), d(2 * S, e()), lz(S, id()) {
//         for (int i = 0; i < N; i++) d[S + i] = v[i];
//         for (int i = S - 1; i >= 1; i--) pull(i);
//     }
//     void apply(int k, F f) {
//         d[k] = onto(f, d[k]);
//         if (k < S) lz[k] = comp(f, lz[k]);
//     }
//     void push(int k) {
//         apply(2 * k, lz[k]), apply(2 * k + 1, lz[k]), lz[k] = id();
//     }
//     void push(int l, int r) {
//         int zl = __builtin_ctz(l), zr = __builtin_ctz(r);
//         for (int i = log; i > min(zl, zr); i--) {
//             if (i > zl) push(l >> i);
//             if (i > zr) push((r - 1) >> i);
//         }
//     }
//     void pull(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
//     void set(int p, T x) {
//         p += S;
//         for (int i = log; i >= 1; i--) push(p >> i);
//         for (d[p] = x; p /= 2;) pull(p);
//     }
//     T query(int l, int r) {
//         if (l == r) return T{};
//         push(l += S, r += S);
//         T vl = e(), vr = e();
//         for (; l < r; l /= 2, r /= 2) {
//             if (l & 1) vl = op(vl, d[l++]);
//             if (r & 1) vr = op(d[--r], vr);
//         }
//         return op(vl, vr);
//     }
//     void update(int l, int r, F f) {
//         if (l == r) return;
//         push(l += S, r += S);
//         for (int a = l, b = r; a < b; a /= 2, b /= 2) {
//             if (a & 1) apply(a++, f);
//             if (b & 1) apply(--b, f);
//         }
//         int zl = __builtin_ctz(l), zr = __builtin_ctz(r);
//         for (int i = min(zl, zr) + 1; i <= log; i++) {
//             if (i > zl) pull(l >> i);
//             if (i > zr) pull((r - 1) >> i);
//         }
//     }
// };

// int e() { return INT_MAX; }
// int op(int a, int b) { return min(a, b); }
// int id() { return 0; }
// int onto(int f, int x) { return x - f; }
// int comp(int f, int g) { return f + g; }


// int main() {
//     cin.tie(0)->sync_with_stdio(0);
//     tests {
//         int m, x; cin >> m >> x;
//         vi nums(m);
//         vpi data;
//         forn(i, m) {
//             cin >> nums[i];
//             data.emplace_back(nums[i], i);
//         }
//         vi money(m);
//         forn(i, m) money[i] = i * x;
//         lazy_segtree<int, e, op, int, id, onto, comp> ST(money);
        
//         sort(all(data));
//         int res = 0;
//         forn(i, m) {
//             auto [val, ind] = data[i];
//             int mini = ST.query(ind, m);
//             if (mini >= val) {
//                 res++;
//                 ST.update(ind, m, val);
//             }
//         }
//         cout << res << "\n";
//     }
    
//     return 0;
// }