#include <bits/stdc++.h>
using namespace std;

int getThird(int a, int b) {
    for (int i = 1; i <= 3; i++) {
        if (a != i && b != i) return i;
    }
    return -1;
}

void f(int amt, int from, int to) {
    if (amt == 0) return;
    if (amt == 1) {
        cout << from << " " << to << '\n';
        return;
    }
    f(amt-1, from, getThird(from, to));
    f(1, from, to);
    f(amt-1, getThird(from, to), to);
}

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    cout << ((1 << n) - 1) << '\n';
    f(n, 1, 3);

    return 0;
}