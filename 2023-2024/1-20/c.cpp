#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;
typedef long double ld;
typedef pair<ld, ld> pld;

void showpq(priority_queue<pld, vector<pld>, greater<pld>> g) {
    while (!g.empty()) {
        cout << "(" << g.top().first
             << " " << g.top().second
             << ") -> ";
        g.pop();
    }
    cout << endl;
}

int main() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> foodData(n);
    ld l = 0, h;
    for (int i = 0; i < n; ++i) {
        int q, f; cin >> q >> f;
        foodData[i] = {q, f};
    }
    h = foodData[0].first;

    double prev_m = 0;
    while ((h - l) > 1e-9) {
        // cout << l << " " << h << endl;
        priority_queue<pld, vector<pld>, greater<pld>> food;
        long double m = (l + h) / 2;
        // cout << l<< "-" << m << "-" << h << endl;
        if (m == prev_m) break;
        prev_m = m;
            
        bool flag = true;
        for (int day = 0; day < n; day++) {
            ld q = foodData[day].first;
            ld f = foodData[day].second;
            food.push({f, q});
            ld mid = m;
            while (mid > 0 && !food.empty()) {
                // showpq(food);
                ld df = food.top().first, dq = food.top().second; 
                food.pop();
                if (df < day + 1) continue;
                mid -= dq;
                if (mid < 0) {
                    food.push({df, -mid});
                    mid = 0;
                }
            }
            if (mid > 0) {
                // cout << "doesnt work" << endl;
                h = m - 1e-9;
                flag = false;
                break;
            }
        }
        if (flag) {
            // cout << "works" << endl;
            l = m + 1e-9;
        }
    }
    ld res = (l + h) / 2 / k;
    // print(res if res > 1e-9 else -1)
    // cout << (res > 1e-9) ? res : -1;
    cout << setprecision(10);
    if (res > 1e-9) {
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}