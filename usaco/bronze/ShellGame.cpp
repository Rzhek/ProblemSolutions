#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("shell.in", "r", stdin);
    int n; cin >> n;
    vector<int> shells = {0, 1, 2}, guesses = {0, 0, 0};
    for (int i = 0; i < n; ++i) {
        int a, b, c; cin >> a >> b >> c;
        swap(shells[--a], shells[--b]);
        guesses[shells[--c]]++;
    }
    freopen("shell.out", "w", stdout);
    cout << *max_element(guesses.begin(), guesses.end()) << '\n';
    return 0;
}