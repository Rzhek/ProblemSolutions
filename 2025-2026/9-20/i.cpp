#include <bits/stdc++.h>
using namespace std;


int main() 
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        cout << "1 1 3 4\n";
    }
    cout << 2 * n - 2 << " " << m - n + 1 << " 1 " << m - 4 * (n - 1) << "\n"; 
}