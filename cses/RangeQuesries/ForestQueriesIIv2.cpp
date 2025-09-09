#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

using ll = long long;
using vi = vector<int>;

template <typename T> struct BIT2D {
	const int n, m;
	vector<vector<T>> bit;
	BIT2D(int n, int m) : n(n), m(m), bit(n + 1, vector<T>(m + 1)) {}

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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    BIT2D<int> bit(n+1, n+1);
    vector<vi> grid(n, vi(n));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            char ch; cin >> ch;
            if (ch == '*') grid[r][c] = 1, bit.add(r, c, 1);
        }
    }

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int r, c; cin >> r >> c;
            r--; c--;
            if (grid[r][c]) bit.add(r, c, -1);
            else bit.add(r, c, 1);
            grid[r][c] ^= 1;
        } else {
            int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
            r1--; c1--; r2--; c2--;
            cout << bit.query(r1, c1, r2, c2) << "\n";
        }
    }
}