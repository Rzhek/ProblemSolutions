#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tests int tt; cin >> tt; while (tt--)
#define f first
#define s second

template<class T>
ostream & operator << (ostream & os, vector<T> v) {
   for (auto x : v) os << x << ' ';
   return os;
}
template<class T, class U>
ostream &operator << (ostream & os, pair<T, U> p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

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
const int mod2inv = 500000004;
const long double EPS = 1e-9;

// ? Suspect overflow? Add this (TLE chances increase by 90%)
#pragma GCC optimize("trapv")

// ? 5 minutes before the contest ends and you need to make your code as fast as possible? Add this
#pragma GCC optimize("O3,unroll-loops,inline")
// * might boost up to 1e10 operations in ~3.5 seconds (with a very small constant factor)

// ? This might help with bitwise stuff
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt") 

// * Increases the stack limit in terminal
// ``` ulimit -s unlimited ```


// * Hashes a file, ignoring all whitespace and comments. Use for
// # verifying that code was correctly typed.
// # Usage:
// #   To make executable, run the command: chmod +x hash.sh
// #   To execute: ./hash.sh < file.cpp
// cpp -dD -P -fpreprocessed | tr -d '[:space:]'| md5sum |cut -c-6


// * bitwise stuff
// (x)&(-x)
// * longest common suffix in 2 nums
// (x^y)&-(x&y)
// * more reliable way to find int log base 2
// (int)log2(num) = 31 - __builtin_clz(num);
//                       ^ CountLeadingZeros

// * lower_bound: index of first element >= val; returns .end() if val > last elem
// * upper_bound: index of first element > val; returns .end() if val >= last elem

// * Indexed set (ordered tree)
// Example Salary queries CSES
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <class T>
// using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// tree.insert(), tree.erase(),
// range query [a, b]: tree.order_of_key({b, MOD}) - tree.order_of_key({a-1, MOD}) << "\n";
// get element by order: *tree.find_by_order(ind);

// * trim a string from both sides
void foo(string string) {
    string.erase(string.find_last_not_of(" \n\r\t")+1);
}

// * splits a string by separator (default is space) 
vector<string> split(string &s, char sep = ' ') {
    stringstream in(s);
    vector<string> res;
    string tmp;
    while (getline(in, tmp, sep)) res.push_back(tmp);
    return res;
}

// * random number generator
mt19937 mt(time(nullptr));
// mt() % n => random num [0, n)

// uniform random numbers
const int maxn = 1e9;
mt19937 gen(rand());
uniform_int_distribution<int> dist(1, maxn);

// * Custom compare function, can be used in sets and maps
struct Compare {
    bool operator()(pii a, pii b){
        if (a.s != b.s) return a.s < b.s;
        return a.f < b.f;
    }
};

// * For any positive integer x, if its prime factorization is:
// x = p1^e1 * p2^r2 * ... * pk^3k
// * Then, the number of divisors d(x) is given  by
// d(x) = (e1 + 1) * (e2 + 1) * ... * (ek + 1) 


// * Binary search hints
// when searching for the first element, answer in hi
while (lo < hi) {
    int m = (lo + hi) / 2;
    if (check(first, m)) hi = m; // check returns val on 000111
    else lo = m + 1;
}
// when searching for the last element, asnwer in lo
while ((hi - lo) > 1) {
    int m = (lo + hi) / 2;
    if (check(last, m)) lo = m; // check returns val on 111000
    else hi = m;
}

// * factors generation
// ! pay attention when want to exclude 1 and n
vi getFactors(int n) {
    vi factors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) factors.push_back(n / i);
        } 
    }
    // sort(all(factors));
    return factors;
}


// * prime sieve
vi primes;
void getPrimes(int n) {
    vi isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i] == 0) continue;
        for (int j = i + i; j <= n; j += i) {
            isPrime[j] = 0;
        }
    }
    for (int i = 2; i <= n; i++) if (isPrime[i]) primes.pb(i); 
}


// * get prime factorization of a number [factor, count]
map<int, int> primeFactorize(int num, const vi &primes) {
    map<int, int> res;
    for (int prime : primes) {
        if (prime * prime > num) break;
        while (num % prime == 0) {
            res[prime]++;
            num /= prime;
        }
    }
    if (num > 1) res[num]++;
    return res;
}

// * prime factorization of a number without precomp of primes
// generally a little faster
vector<int> factor(int n) {
    vector<int> res;
    while (n % 2 == 0) {
        res.push_back(2);
        n = n/2;
    }
    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            res.push_back(i);
            n = n/i;
        }
    }
    if (n > 2) res.push_back(n);
    return res;
}

// * compute phi of n (# of coprime numbers in [1, n) to n)
ll phi(ll n) {
    ll res = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res -= res / i;
            while (n % i == 0) n /= i;
        } 
    }
    if (n > 1) res -= res / n;
    return res;
}


// * Regular SegTree
template <class T, T defVal, T(*op)(T, T), T(*upd)(T, T)>
struct Tree { // [l, r]
    int l, r, m;
    T val;
    Tree *left, *right;
    
    Tree (vector<T> &vals, int l, int r) : l(l), r(r), m((l+r)/2) {
        if (l == r) {
            val = vals[l];
            left = right = nullptr;
        } else {
            left = new Tree(vals, l, m);
            right = new Tree(vals, m+1, r);
            val = op(left->val, right->val);
        }
    }

    Tree (int l, int r) : l(l), r(r), m((l+r)/2) {
        if (l == r) {
            val = defVal;
            left = right = nullptr;
        } else {
            left = new Tree(l, m);
            right = new Tree(m + 1, r);
            val = op(left->val, left->val);
        }
    }

    int query(int lo, int hi) {
        if (lo <= l && r <= hi) return val;
        if (l > hi || r < lo) return 0;
        return op(left->query(lo, hi), right->query(lo, hi));
    }

    void update(int pos, T v) {
        if (l == r) {
            assert(l == pos);
            val = upd(val, v);
            return;
        }
        if (pos <= (l + r) / 2) left->update(pos, v);
        else right->update(pos, v); 
        val = op(left->val, right->val);
    }
};
// Example for sum queries
// int op(int a, int b) { return a + b; }
// int upd(int a, int b) { return a + b; }
// Use: Tree<int, 0, op, upd>  ST(0, n);


// * Lazy Seg Tree
template<class T, T (*e)(), T(*op)(T, T), class F, F (*id)(), T (*onto)(F, T), F (*comp)(F, F)>
struct lazy_segtree {
    int N, log, S;
    vector<T> d;
    vector<F> lz;
    lazy_segtree(const vector<T>& v):
        N(sz(v)), log(__lg(2 * N - 1)), S(1 << log), d(2 * S, e()), lz(S, id()) {
        for (int i = 0; i < N; i++) d[S + i] = v[i];
        for (int i = S - 1; i >= 1; i--) pull(i);
    }
    void apply(int k, F f) {
        d[k] = onto(f, d[k]);
        if (k < S) lz[k] = comp(f, lz[k]);
    }
    void push(int k) {
        apply(2 * k, lz[k]), apply(2 * k + 1, lz[k]), lz[k] = id();
    }
    void push(int l, int r) {
        int zl = __builtin_ctz(l), zr = __builtin_ctz(r);
        for (int i = log; i > min(zl, zr); i--) {
            if (i > zl) push(l >> i);
            if (i > zr) push((r - 1) >> i);
        }
    }
    void pull(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void set(int p, T x) {
        p += S;
        for (int i = log; i >= 1; i--) push(p >> i);
        for (d[p] = x; p /= 2;) pull(p);
    }
    T query(int l, int r) {
        if (l == r) return T{};
        push(l += S, r += S);
        T vl = e(), vr = e();
        for (; l < r; l /= 2, r /= 2) {
            if (l & 1) vl = op(vl, d[l++]);
            if (r & 1) vr = op(d[--r], vr);
        }
        return op(vl, vr);
    }
    void update(int l, int r, F f) {
        if (l == r) return;
        push(l += S, r += S);
        for (int a = l, b = r; a < b; a /= 2, b /= 2) {
            if (a & 1) apply(a++, f);
            if (b & 1) apply(--b, f);
        }
        int zl = __builtin_ctz(l), zr = __builtin_ctz(r);
        for (int i = min(zl, zr) + 1; i <= log; i++) {
            if (i > zl) pull(l >> i);
            if (i > zr) pull((r - 1) >> i);
        }
    }
};
// parameters for min seg tree, change e and op to convert
int e() { return INT_MAX; }                     // default value
int op(int a, int b) { return min(a, b); }      // combine two segments
int id() { return 0; }
int onto(int f, int x) { return x + f; }        // apply function on a segment
int comp(int f, int g) { return f + g; }
// USE: lazy_segtree<int, e, op, int, id, onto, comp> ST(-vi-);


// Fast number expo
// call fastExpo(num, MOD-2) to get inverse mod
ll fastExpo(int a, int e) {
    if (e == 0) return 1ll;
    if (e == 1) return a;
    ll res = fastExpo(a, e / 2);
    res = res * res % MOD;
    if (e & 1) res = res * a % MOD;
    return res;
}

// * Matrix multiplication
vvl multiply(const vvl &A, const vvl &B) {
    assert(A[0].size() == B.size());
    int m = A[0].size();
    int a = A.size(), b = B[0].size();
    vvl res(a, vl(b, 0));
    for (int r = 0; r < a; r++) {
        for (int c = 0; c < b; c++) {
            for (int ind = 0; ind < m; ind++) {
                res[r][c] += A[r][ind] * B[ind][c] % MOD;
                res[r][c] %= MOD;
            }
        }
    }
    return res;
}

// USE: vvl res = multiply(a, b);
vvl fastExpo(vvl &mat, ll p) {
    if (p == 0) { // Identity matrix case
        int n = mat.size();
        vvl identity(n, vl(n, 0));
        for(int i = 0; i < n; i++) identity[i][i] = 1;
        return identity;
    }
    vvl res = fastExpo(mat, p / 2);
    res = multiply(res, res);
    if (p % 2) res = multiply(res, mat);
    return res;
}

// build kmp automaton from p values
// O(N^2)
vvl kmpAuto(string s) {
    int m = s.size();
    vector<int> p(m);
    for (int i = 1; i < m; i++) {
        int g = p[i-1];
        while (g && s[i] != s[g]) g = p[g-1];
        p[i] = g + (s[i] == s[g]);
    }
    
    vvl mat(m + 1, vl(m + 1));
    for (int u = 0; u < m - 1; u++) {
        for (int ch = 0; ch < 26; ch++) {
            int cur = u;
            while (cur >= -1 && cur + 1 < m && s[cur + 1] - 'A' != ch) {
                if (cur == -1) cur--;
                else cur = p[cur] - 1;
            }
            mat[u+1][cur+2]++;
        }
    }
    mat[0][0] = 25;
    mat[0][1] = 1;
    
    // if want to accept any string that was ever in finish state
    fill(mat.back().begin(), mat.back().end(), 0);
    mat[m][m] = 26;
    
    return mat;
}


// * GEO
template<class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T> struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(P p) const {
        return tie(x, y) < tie(p.x, p.y);
    }
    bool operator==(P p) const {
        return tie(x, y) == tie(p.x, p.y);
    }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const {
        return (a - *this).cross(b - *this);
    }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); }
    P perp() const { return P(-y, x); }
    P normal() const { return perp().unit(); }
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

template<class T> T polygonArea2(vector<Point<T>>& v) {
    T a = v.back().cross(v[0]);
    rep(i, 0, sz(v) - 1) a += v[i].cross(v[i+1]);
    return a;
}

// * Geometric median
// finds the minimized sum difference between positions and a point
double getMinDistSum(vector<vector<int>>& positions) {
    auto dist = [](double x1, double y1, double x2, double y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };
    int n = positions.size();
    double xc = 0, yc = 0;
    for (const auto &pos : positions) {
        xc += pos[0];
        yc += pos[1];
    }
    xc /= n;
    yc /= n;

    double change = numeric_limits<double>::max();
    while (change > EPS) {
        double numX = 0, numY = 0, den = 0;
        for (const auto &pos : positions) {
            double x = pos[0], y = pos[1];
            double d = dist(xc, yc, x, y);
            if (d != 0) {
                double w = 1 / d;
                numX += x * w;
                numY += y * w;
                den += w;
            }
        }
        if (den == 0) break;
        double newXC = numX / den;
        double newYC = numY / den;

        change = dist(xc, yc, newXC, newYC);

        xc = newXC;
        yc = newYC;
    }

    double res = 0;
    for (const auto &pos : positions) {
        res += dist(xc, yc, pos[0], pos[1]);
    }

    return res;
}



// * Binary Lifting / LCA
// pass a tree with 2-directed edges, no need to find the root
// passing a large k value to kth method will result in -1
// ! use 0 based index
// lca(-1, 0) = 0
// lca(-1, -1) = -1
struct lift {
    vi d, p, j;
    lift(vector<vi>& adj) : d(sz(adj)), p(d), j(d) {
        dfs(0, adj);
    }
    void dfs(int u, vector<vi>& adj) {
        int jmp = (d[u] + d[j[j[u]]] == 2 * d[j[u]]) ? j[j[u]] : u;
        for (int v : adj[u])
            if (v != p[u])
                d[v] = d[p[v] = u] + 1, j[v] = jmp, dfs(v, adj);
    }
    int lca(int u, int v) {
        if (d[u] < d[v]) swap(u, v);
        while (d[u] > d[v]) u = d[j[u]] >= d[v] ? j[u] : p[u];
        if (u == v) return u;
        while (p[u] != p[v])
            if (j[u] != j[v]) u = j[u], v = j[v];
            else u = p[u], v = p[v];
        return p[u];
    }
    int kth(int u, int k) {
        if (k > d[u]) return -1;
        k = d[u] - k;
        while (d[u] > k) u = d[j[u]] >= k ? j[u] : p[u];
        return u;
    }
    int distance(int u, int v) {
        int l = lca(u, v);
        return d[u] + d[v] - 2 * d[l];
    }
};



// * Find bridges in a graph using Tarjan's algo in O(n)
// * c5b617
// disc, low, and visited are of size n and filled with 0
vpi bridges; // ! dont forget to .clear() for each test case 
// * set u, p, and timer all to 0 for the first call
void findBridges(int u, int p, int timer, vi &disc, vi &low, vi &visited, vvi &edges){
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    for(int v : edges[u]){
        if(v != p){
            if(visited[v]) low[u] = min(low[u], disc[v]);
            else {
                findBridges(v, u, timer, disc, low, visited, edges);
                low[u] = min(low[u], low[v]);
                if(low[v] > disc[u])
                    bridges.push_back({u, v});
            }
        }
    }
}


// * Fenwick Tree | Binary Index Tree (BIT)
// 476fcd (full), 7fe6b9 (no construct)
const int maxn = 2e5+5; // or whatever the upper bound is
ll fen[maxn];
inline void add(int p, int val) { // make sure to convert to 1 base index
    // otherwise uncomment
    for (/*p++*/; p < maxn; p += p&-p) fen[p] += val;
}
inline ll get(int p) { // inclusive [0, p]
    ll sum = 0;
    for (; p; p -= p&-p) sum += fen[p];
    return sum;
}
inline ll get(int a, int b) { // [a, b]
    return get(b) - get(a - 1);
}
inline void construct(vi &vals) {
    int n = vals.size();
    fen[0] = 0;
    for (int i = 1; i <= n; i++) fen[i] = vals[i-1];
    for (int i = 1; i <= n; i++) {
        int j = i + (i&-i);
        if (j <= n) fen[j] = fen[j] + fen[i];
    }
}

/**
 * 2D Fenwick Tree implementation.
 * Note that all cell locations are zero-indexed
 * in this implementation.
*/
// 051484
template <typename T> struct BIT2D {
	const int n, m;
	vector<vector<T>> bit;
	BIT2D(int n, int m) : n(n), m(m), bit(n + 1, vector<T>(m + 1)) {}

	/** adds val to the point (r, c) */
	void add(int r, int c, T val) {
		r++, c++;
		for (; r <= n; r += r & -r) {
			for (int i = c; i <= m; i += i & -i) { bit[r][i] += val; }
		}
	}

	/** @returns sum of points with row in [0, r] and column in [0, c] */
	T query(int r, int c) {
		r++, c++;
		T sum = 0;
		for (; r > 0; r -= r & -r) {
			for (int i = c; i > 0; i -= i & -i) { sum += bit[r][i]; }
		}
		return sum;
	}

	/** @returns sum of points with row in [r1, r2] and column in [c1, c2] */
	T query(int r1, int c1, int r2, int c2) {
		return query(r2, c2) - query(r2, c1 - 1) - query(r1 - 1, c2) +
		       query(r1 - 1, c1 - 1);
	}
};

// * Flow dinic's algo
// can be used to find maximum bipirtite matching
// to find matching values, look at edges with positive values
// ! if doesn't work, add property to flowEdge struct to distinguish from residual edges
struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    // int isResidual;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

struct F {
    ll p, q;
    explicit F(ll p = 1, ll q = 1) : p(p), q(q) {
        ll gcd = __gcd(abs(p), abs(q));
        this->p /= gcd;
        this->q /= gcd;
    }
    F operator+(F f) {
        F res(p * f.q + f.p * q, q * f.q);
        ll gcd = __gcd(abs(res.p), abs(res.q));
        res.p /= gcd;
        res.q /= gcd;
        return res;
    }
    F operator-(F f) {
        return *this + F(-f.p, f.q);
    }
    F operator*(F f) {
        F res(p * f.p, q * f.q);
        ll gcd = __gcd(abs(res.p), abs(res.q));
        res.p /= gcd;
        res.q /= gcd;
        return res;
    }
    F operator/(F f) {
        return *this * F(f.q, f.p);
    }
    F raise(int p) {
        if (p == 0) return F();
        if (p == 1) return *this;
        F res = this->raise(p / 2);
        res = res * res;
        if (p % 2) res = res **this;
        return res;
    }
    friend ostream& operator<<(ostream& os, F f) {
        return os << f.p << " / " << f.q;
    }
};

// * Apocalypse attack dinic
// * d7f0f1
struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};


// * Suffix automaton by meaf
// * 1914a9
// len is the longest-length substring ending here
// pos is the first index in the string matching here
// term is whether this node is a terminal (aka a suffix)
struct st { int len, pos, term; st *link; map<char, st*> next; };
st *suffixAutomaton(string &str) {
    st *last = new st(), *root = last;
    for(auto c : str) {
        st *p = last, *cur = last = new st{last->len + 1, last->len};
        while(p && !p->next.count(c))
            p->next[c] = cur, p = p->link;
        if (!p) cur->link = root;
        else {
            st *q = p->next[c];
            if (p->len + 1 == q->len) cur->link = q;
            else {
                st *clone = new st{p->len+1, q->pos, 0, q->link, q->next};
                for (; p && p->next[c] == q; p = p->link)
                    p->next[c] = clone;
                q->link = cur->link = clone;
            }
        }
    }
    while(last) last->term = 1, last = last->link;
    return root;
}


// centroid decomp
int removed[maxn], sz[maxn];
vector<int> adj[maxn];
int dfs(int u, int p = -1) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p || removed[v]) continue;
        sz[u] += dfs(v, u);;
    }
    return sz[u];
}

int find_centroid(int u, int p, int total) {
    for (int v : adj[u]) {
        if (v == p || removed[v]) continue;
        if (sz[v] * 2 > total) return find_centroid(v, u, total);
    }
    return u;
}

void decomp(int u) {
    int centroid = find_centroid(u, -1, dfs(u));
    vector<int> cur = {1};

    for (int v : adj[centroid]) {
        if (removed[v]) continue;
        // do the processing
        // for example (from CSES - Fixed length paths):

        // vector<int> nxt = {0};
        // count(v, centroid, 1, nxt);
        // for (int i = 1; i < nxt.size(); i++) {
        //     if (cur.size() - 1 < k - i - 1) continue;
        //     res += (ll)nxt[i] * cur[k-i-1];
        // }
        // for (int i = 1; i < nxt.size(); i++) add_val(cur, i, nxt[i]);
    }

    removed[centroid] = 1;
    for (int v : adj[centroid]) {
        if (removed[v]) continue;
        decomp(v);
    }
}

// O(1) line container
// Queries must be monotonic in x (non-decreasing)
// Slopes must be monotomic in one direction (opposite direction of x)
// Querying min value. Change to <= if want max
// ce78a3
struct Line{
    ll k,m;
    ll eval(ll x) { return k * x + m; }
};
struct LineContainer{
    deque<Line> dq;
    bool bad(const Line &a, const Line &b, const Line &c){
        return (b.m - a.m) * (a.k - c.k) >= (c.m - a.m) * (a.k - b.k);
    }
    void add(ll k, ll m){
        Line l = {k,m};
        while (dq.size() >= 2 && bad(dq[dq.size()-2], dq.back(), l)) dq.pop_back();
        dq.push_back(l);
    }
    ll query(ll x){
        while (dq.size() >= 2 && dq[0].eval(x) >= dq[1].eval(x)) dq.pop_front();
        return dq[0].eval(x);
    }
};