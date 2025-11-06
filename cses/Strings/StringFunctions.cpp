#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size();

    vector<int> z(n), p(n);
    int l = -1, r = -1;
    for(int i = 1; i < n; i++) {
        z[i] = i >= r ? 0 : min(r - i, z[i - l]);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
        z[i]++;
        if (i + z[i] > r)
        l = i, r = i + z[i];
    }

    for (int i = 1; i < n; i++) {
        int g = p[i-1];
        while (g && s[i] != s[g]) g = p[g-1];
        p[i] = g + (s[i] == s[g]);
    }

    for (int x : z) cout << x << " "; cout << "\n";
    for (int x : p) cout << x << " "; cout << "\n";

}