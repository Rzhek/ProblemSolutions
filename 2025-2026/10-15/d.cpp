#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100, maxm = 50;
using ll = long long;
using ld = double;
bool vis[maxn+1][maxm][maxm];
vector<int> Aarr, Barr, Carr;
int R, s, n;
int A, B, g, Ag, Bg;
int x, y;

ll euclid(int a, int b, int &x, int &y) {
    if (!b) return x = 1, y = 0, a;
    int d = euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}

// int solve(int ind, int l, int r) {
//     if (ind == n) return 1;
//     if (vis[ind][l][r]) return 0;
//     vis[ind][l][r] = 1;
//     // Ax + By = c;
//     for (int i = 0; i < R; i++) {
//         int delta1 = (A + (i ? Aarr[i-1] : 0) - (l ? Aarr[l-1] : 0));
//         if (delta1 >= A) delta1 -= A;
//         // if (i == 0) cout << A << "!!!! " <<  (i ? Aarr[i-1] : 0) << " - " << (i ? Aarr[l-1] : 0) << ": " << (A + (i ? Aarr[i-1] : 0) - (i ? Aarr[l-1] : 0)) % A << "\n";
//         for (int j = 0; j < s; j++) {
//             int delta2 = (B + (j ? Barr[j-1] : 0) - (r ? Barr[r-1] : 0));
//             if (delta2 >= B) delta2 -= B;

//             int c = Carr[ind] - delta1 - delta2;
//             if (c < 0 || c % g) continue;
//             ll X = (ll)x * c / g;
//             ll Y = (ll)y * c / g;

//             ld lo = -(ld)X/(Bg);
//             if (ceil(lo) <= (ld)Y/Ag) {
//                 // cout << ind << ": " << l << ", " << r << " -> " << i << ", " << j << " | " << x << " " << y << " " << c << " |> " << delta1 << " " << delta2 << " | " << lo << " " << hi << "\n";
//                 // cout << ind << ": " << l << ", " << r << " -> " << i << ", " << j << "\n";
//                 if (solve(ind+1, i, j)) return 1;
//             }
//         }
//     }
//     return 0;
// }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> R >> s >> n;

    Aarr = vector<int>(R);
    Barr = vector<int>(s);
    Carr = vector<int>(n);

    for (int i = 0; i < R; i++) {
        cin >> Aarr[i];
        if (i) Aarr[i] += Aarr[i-1];
    }  
    for (int i = 0; i < s; i++) {
        cin >> Barr[i];
        if (i) Barr[i] += Barr[i-1];
    }  
    for (int i = 0; i < n; i++) {
        cin >> Carr[i];
    }

    A = Aarr.back();
    B = Barr.back();
    g = __gcd(A, B);
    Ag = A / g;
    Bg = B / g;
    euclid(Ag, Bg, x, y);

    vis[0][0][0] = 1;
    int res = 0;
    for (int ind = 0; ind < n; ind++) {
        for (int l = 0; l < R; l++) {
            for (int r = 0; r < s; r++) {
                if (!vis[ind][l][r]) continue;
                for (int i = 0; i < R; i++) {
                    int delta1 = (A + (i ? Aarr[i-1] : 0) - (l ? Aarr[l-1] : 0));
                    if (delta1 >= A) delta1 -= A;

                    for (int j = 0; j < s; j++) {
                        if (vis[ind+1][i][j]) continue;
                        int delta2 = (B + (j ? Barr[j-1] : 0) - (r ? Barr[r-1] : 0));
                        if (delta2 >= B) delta2 -= B;
                        
                        int c = Carr[ind] - delta1 - delta2;
                        if (c < 0 || c % g) continue;
                        ll X = (ll)x * c / g;
                        ll Y = (ll)y * c / g;
                        ld lo = -(ld)X/(Bg);
                        vis[ind+1][i][j] = ceil(lo) <= (ld)Y/Ag;
                        
                        res |= vis[ind+1][i][j] && ind == n - 1; 
                    }
                }
            }
        }
    }

    cout << (res ? "yes" : "no") << "\n";
    
}

// ax + by = c

// 7x + 10y = 44
// x = 2, y = 3

// 7x0 + 10y0 = 1
// x0 = 3, y0 = -2 
// x = 132 + 10t >= 0
// y = -88 - 7t  >= 0

// t >= -13.2
// t <= -12.57


// x + bt >=0
// t >= -x/b
// y - at >= 0
// t >= y/a

// x = x0 + 10
// x = x0 + 10

// ax + by = c
// ax0 + by0 = 1

// x = x0 * c
// y = y0 * c

// acx0 + bcy0 = c