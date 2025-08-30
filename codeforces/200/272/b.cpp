#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> ways;
string str1, str2;

void solve(int ind, int pos) {
    if (ind == n) {
        ways[pos]++;
        return;
    }
    if (str2[ind] == '+') {
        solve(ind + 1, pos + 1);
    } else if (str2[ind] == '-') {
        solve(ind + 1, pos - 1);
    } else {
        solve(ind + 1, pos + 1);
        solve(ind + 1, pos - 1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> str1 >> str2;
    n = str1.size();
    int finalPos = 0;
    for (auto x : str1) finalPos += (x == '+' ? 1 : -1);
    solve(0, 0);

    double total = 0, good = ways[finalPos];
    for (auto [x, y] : ways) {
        cout << x << ": " << y << '\n';
        total += y;
    }
    
    cout << fixed << setprecision(10) << good / total << '\n';

    return 0;
}