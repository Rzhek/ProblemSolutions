#include <bits/stdc++.h>
using namespace std;

int main() {
    int lo = 1, hi = 1e9;
    while (lo < hi) {
        int m = lo + (hi - lo) / 2;
        cout << "? " << m << endl;
        string res; cin >> res;
        if (res == "NO") {
            hi = m;
        } else {
            lo = m + 1;
        }
    }
    cout << "! " << lo << "\n";
}