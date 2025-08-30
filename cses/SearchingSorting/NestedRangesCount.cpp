#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int maxn = 4e5+5; // or whatever the upper bound is
int fen[maxn];
inline void add(int p, int val) { // make sure to convert to 1 base index
    // otherwise uncomment
    for (/*p++*/; p < maxn; p += p&-p) fen[p] += val;
}
inline int get(int p) { // inclusive [0, p]
    int sum = 0;
    for (; p; p -= p&-p) sum += fen[p];
    return sum;
}
inline int get(int a, int b) { // [a, b]
    return get(b) - get(a - 1);
}

void compress(vector<array<int, 3>> &vec) {
    vector<int> unique;
    for (auto [x, y, z] : vec) {
        unique.push_back(x);
        unique.push_back(y);
    }
    sort(unique.begin(), unique.end());
    unique.erase(std::unique(unique.begin(), unique.end()), unique.end());

    for (auto &[x, y, z] : vec) {
        x = lower_bound(unique.begin(), unique.end(), x) - unique.begin() + 1;
        y = lower_bound(unique.begin(), unique.end(), y) - unique.begin() + 1;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    vector<array<int, 3>> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i][0] >> nums[i][1];
        nums[i][2] = i;
    }
    compress(nums);

    vector<pii> ans(n);

    sort(nums.begin(), nums.end(), [](auto &x, auto &y) {
        if (x[1] != y[1]) return x[1] < y[1];
        return x[0] > y[0];
    });
    
    
    for (auto [start, end, idx] : nums) {
        ans[idx].first = get(start, maxn);
        add(start, 1);
    }
    
    sort(nums.begin(), nums.end(), [](auto &x, auto &y) {
        if (x[0] != y[0]) return x[0] < y[0];
        return x[1] > y[1];
    });
    
    memset(fen, 0, sizeof(fen));

    for (auto [start, end, idx] : nums) {
        ans[idx].second = get(end, maxn);
        add(end, 1);
    }

    
    for (int i = 0; i < n; i++) {
        cout << ans[i].first << " ";
    }
    cout << "\n";
    
    for (int i = 0; i < n; i++) {
        cout << ans[i].second << " ";
    }
    cout << "\n";
    
    return 0;
}