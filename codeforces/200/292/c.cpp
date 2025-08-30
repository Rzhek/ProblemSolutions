#include <bits/stdc++.h>
using namespace std;

vector<string> factors = {
    "",
    "",
    "2",
    "3",
    "322",
    "5",
    "35",
    "7",
    "2227",
    "3327"
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string str; cin >> str;
    string res;
    for (int i = 0; i < n; i++) {
        res += factors[str[i] - '0'];
    }

    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());

    cout << res << '\n';

    return 0;
}


