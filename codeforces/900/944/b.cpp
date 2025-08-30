#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string str; cin >> str;
        int n = str.size();
        int found = 0;
        for (int i = 0; i < n && !found; i++) {
            for (int j = i + 1; j < n; j++) {
                if (str[i] != str[j]) {
                    char tmp = str[i];
                    str[i] = str[j];
                    str[j] = tmp;
                    found = 1;
                    break;
                }
            }
        }
        if (found) {
            cout << "YES\n";
            cout << str << '\n';
        } else {
            cout << "NO\n";
        }
        
    }

    return 0;
}