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
        int have01 = 0;
        int num0 = 0, num1 = 0;
        char cur = str[0];
        if (cur == '0') num0++;
        else num1++;
        for (char ch : str) {
            if (ch == '1') {
                if (cur == '0') {
                    have01 = 1;
                    num1++;
                }
            } else {
                if (cur == '1') num0++;
            }
            cur = ch;
        }

        // cout << str << '\n';
        // cout << num0 << " " << num1 << " " <<  have01 << '\n';
        cout << num0 + num1 - have01 << '\n';
        
    }

    return 0;
}