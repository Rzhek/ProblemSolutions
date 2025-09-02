#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, t; cin >> n >> t;
    map<int, int> data;
    for (int i = 1; i <= n; i++) {
        int num; cin >> num;
        if (data.count(t - num)) {
            cout << data[t-num] << " " << i << '\n';
            return 0; 
        }
        data[num] = i;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}