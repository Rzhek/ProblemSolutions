#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 5e5;
int n, b, nums[maxn];


int solve(int m) {
    int rem = b;
    for (int i = 0; i < n; i++) {
        rem -= nums[i] / m + (nums[i] % m != 0);
        if (rem < 0) return false;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> n >> b && n != -1 && b != -1) {
        for (int i = 0; i < n; i++) cin >> nums[i];
        ll tot = accumulate(nums, nums + n, 0ll);
        int lo = tot / b, hi = *max_element(nums, nums + n);

        while (lo < hi) {
            int m = (lo + hi) / 2;
            if (solve(m)) hi = m;
            else lo = m + 1;
        }

        cout << lo << "\n";
    }
}