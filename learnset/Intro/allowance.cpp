#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int w; cin >> w;
    while (w--) {
        ll n; cin >> n;
        ll curr = 1;
        int res = 1;
        while (curr * 2 + 1 <= n) {
            curr = curr * 2 + 1;
            res++;
        }
        cout << res << " " << curr << endl;
    }


    return 0;
}