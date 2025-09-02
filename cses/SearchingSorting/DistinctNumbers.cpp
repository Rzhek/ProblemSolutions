#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> nums;
    int n; cin >> n;
    int res = 0;
    while (n--) {
        int num; cin >> num;
        if (!nums.count(num)) {
            nums.insert(num);
            res++;
        } 
    }
    cout << res << '\n';
    return 0;
}