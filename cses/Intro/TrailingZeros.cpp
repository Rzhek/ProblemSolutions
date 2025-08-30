#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int res = 0;
    for (int i = 5; i <= n; i += 5) {
        int cur = i;
        while (cur % 5 == 0) {
            res++;
            cur /= 5;
        }
    }

    cout << res << '\n';


    return 0;
}