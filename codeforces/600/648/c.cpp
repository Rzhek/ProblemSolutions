#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(x) x.begin(), x.end()

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) {
        int x; cin >> x;
        a[x-1] = i;
    }
    rep(i, 0, n) {
        int x; cin >> x;
        b[x-1] = i;
    }

    vector<int> freq1(n, 0), freq2(n, 0);
    rep(i, 0, n) {
        freq1[(a[i]-b[i]+n)%n]++;
        freq2[(b[i]-a[i]+n)%n]++;
    }

    cout << max(*max_element(all(freq1)), *max_element(all(freq2))) << '\n';



    return 0;
}