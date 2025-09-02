#include <bits/stdc++.h>
using namespace std;

int main() {
    string seq; cin >> seq;
    char chr = '0';
    int res = -1, cur = 0;
    for (char i : seq) {
        if (i == chr) cur++;
        else {
            res = max(res, cur);
            cur = 1;
            chr = i;
        }
    }

    cout << max(cur, res) << '\n';

    return 0;
}