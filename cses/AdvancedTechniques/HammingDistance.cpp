#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e4+1;
int n, k, nums[maxn];


// This probably wont work but i gotta try 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = 0; j < k; j++) {
            char ch; cin >> ch;
            num <<= 1;
            num += ch == '1';
        }
        nums[i] = num;
    }

    int mini = k;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            mini = min(mini, __builtin_popcount(nums[i] ^ nums[j]));
        }
    }

    cout << mini << "\n";


}