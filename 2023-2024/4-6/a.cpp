#include <bits/stdc++.h>
using namespace std;

int convert(string num, int base) {
    int res = 0;
    int power = num.size() - 1;
    for (char ch : num) {
        if (ch - '0' >= base) return 0;
        res += (ch - '0') * pow(base, power--);;
    }
    return res;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string num; cin >> num;
        cout << n << " " << convert(num, 8) << " " << num << " " << convert(num, 16) << '\n';
    }
    return 0;
}