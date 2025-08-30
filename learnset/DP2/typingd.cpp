#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<vector<int>> matrix(26, vector<int>(26, 100));

    vector<string> lst(128);
    {

        lst['q'] = "aw";
        lst['w'] = "esa";
        lst['e'] = "rds";
        lst['r'] = "tfd";
        lst['t'] = "ygf";
        lst['y'] = "uhg";
        lst['u'] = "ijh";
        lst['i'] = "okj";
        lst['o'] = "plk";
        lst['p'] = "l";
        
        lst['a'] = "sz";
        lst['s'] = "dxz";
        lst['d'] = "fcx";
        lst['f'] = "gvc";
        lst['g'] = "hbv";
        lst['h'] = "jnb";
        lst['j'] = "kmn";
        lst['k'] = "lm";
        
        lst['z'] = "x";
        lst['x'] = "c";
        lst['c'] = "v";
        lst['v'] = "b";
        lst['b'] = "n";
        lst['n'] = "m";
    }

    for (int u = 'a'; u <= 'z'; u++) {
        matrix[u-'a'][u-'a'] = 0;
        for (char v : lst[u]) {
            matrix[u-'a'][v-'a'] = matrix[v-'a'][u-'a'] = 1;
        }
    }

    for (int k = 0; k < 26; k++) {
        for (int u = 0; u < 26; u++) {
            for (int v = 0; v < 26; v++) {
                matrix[u][v] = min(matrix[u][v], matrix[u][k] + matrix[k][v]);
            }
        }
    }

    auto dist = [&](char a, char b) -> int {
        return matrix[a-'a'][b-'a'];
    };

    // cout << dist('k', 'n') << "\n";

    int t; cin >> t;
    while (t--) {
        string a, b; cin >> a >> b;
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e5));

        for (int i = 0; i <= n; i++) dp[i][0] = i * 5;
        for (int i = 0; i <= m; i++) dp[0][i] = i * 5;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = min(dp[i-1][j] + 5, dp[i][j-1] + 5);
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + dist(a[i-1], b[j-1]));
            }
        }
        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= m; j++) {
        //         cout << setw(3) << dp[i][j] << " ";
                
        //     }
        //     cout << "\n";
        // }
        cout << dp[n][m] << "\n";
    }
    
    
}