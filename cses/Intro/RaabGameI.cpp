#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    if (a + b > n || max(a, b) == n || (max(a, b) != 0 && min(a, b) == 0)) {
        cout << "NO\n"; return;
    }

    cout << "YES\n";
    if (max(a, b) == 0) {
        for (int i = 0; i < n; i++) cout << (i + 1) << " "; cout << "\n";
        for (int i = 0; i < n; i++) cout << (i + 1) << " "; cout << "\n";
        return;
    }
    
    vi A, B;
    A.reserve(n);
    B.reserve(n);
    bool rev;
    if (rev = a < b) swap(a, b);
    int delta = a - b;
    for (int i = 1; i <= delta + 1; i++) {
        A.push_back(i + 1);
        B.push_back(i);
        a--;
    }  
    A.push_back(1);
    B.push_back(delta + 2);
    b--;

    assert(a == b);
    int cur = delta + 3;
    while (a--) {
        A.push_back(cur+1);
        B.push_back(cur);
        A.push_back(cur);
        B.push_back(cur+1);
        cur += 2;
    }

    while (cur <= n) {
        A.push_back(cur);
        B.push_back(cur);
        cur++;
    }

    if (rev) swap(A, B);

    for (auto x : A) cout << x << " "; cout << "\n";
    for (auto x : B) cout << x << " "; cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}