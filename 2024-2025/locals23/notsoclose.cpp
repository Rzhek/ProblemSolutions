#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

bool isValid(int mask, int c) {
    for (int i = 0; i < c; i++) {
        if ((mask & (1 << i)) && (mask & (1 << (i + 1)))) return false;
    }
    return true;
}

bool canTransition(int prev_mask, int curr_mask, int c) {
    for (int i = 0; i < c; i++) {
        if ((curr_mask & (1 << i))) {
            if ((prev_mask & (1 << i)) || 
                (i > 0 && (prev_mask & (1 << (i - 1)))) || 
                (i < c-1 && (prev_mask & (1 << (i + 1))))) 
                return false;
        }
    }
    return true;
}

int main() {
    int r, c;
    cin >> r >> c;

    int max_mask = 1 << c;
    vector<vector<int>> dp(r+1, vector<int>(max_mask, 0));
    
    for (int mask = 0; mask < max_mask; mask++) {
        if (isValid(mask, c)) dp[1][mask] = 1;
    }
    
    for (int i = 2; i <= r; i++) {
        for (int curr_mask = 0; curr_mask < max_mask; curr_mask++) {
            if (!isValid(curr_mask, c)) continue;
            for (int prev_mask = 0; prev_mask < max_mask; prev_mask++) {
                if (isValid(prev_mask, c) && canTransition(prev_mask, curr_mask, c)) {
                    dp[i][curr_mask] = (dp[i][curr_mask] + dp[i-1][prev_mask]) % MOD;
                }
            }
        }
    }
    
    int result = 0;
    for (int mask = 0; mask < max_mask; mask++) {
        result = (result + dp[r][mask]) % MOD;
    }
    
    cout << result << endl;
    return 0;
}
