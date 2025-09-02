#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int res = 0;
int sum;

int get(vi &arr, vi ind) {
    int res = 0;
    for (auto i: ind) res += arr[i-1];
    return res;
}

// priority {i, j} means we have to put jth element into ith index of permutation  
void solve(vi &nums, vi&perm, vi& taken, int i, pair<int, int> priority) {
    // cout << i << "\n";
    if (i == 12) {
        int a = get(perm, {8, 6, 10, 12});
        int b = get(perm, {9, 3, 11, 12});
        res += a == b && a == sum;
        return;
    }
    if (i == 4) if (get(perm, {1, 2, 3, 4}) != sum) return;
    if (i == 7) if (get(perm, {1, 5, 6, 7}) != sum) return;
    if (i == 9) if (get(perm, {8, 5, 2, 9}) != sum) return;
    if (i == 11) if (get(perm, {7, 10, 11, 4}) != sum) return;
    
    if (i == priority.first) {
        if (taken[priority.second]) return;
        perm[i] = nums[priority.second];
        taken[priority.second] = 1;
        solve(nums, perm, taken, i + 1, priority);
        taken[priority.second] = 0;
    } else {
        for (int j = 0; j < 12; j++) if (!taken[j]) {
            perm[i] = nums[j];
            taken[j] = 1;
            solve(nums, perm, taken, i + 1, priority);
            taken[j] = 0;
        }
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    while (1) {
        vi nums(12), perm(12, 0), taken(12, 0);
        for (int i = 0; i < 12; i++) cin >> nums[i];
        sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == 0) break;
        if (sum % 3) {
            cout << 0 << "\n";
            continue;
        }
        sum /= 3;

        res = 0;
        solve(nums, perm, taken, 0, {0, 0});
        solve(nums, perm, taken, 0, {1, 0});
        cout << res / 2 << "\n";
        
    }

    return 0;
}