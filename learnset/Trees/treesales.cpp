#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int test = 1; test <= t; test++) {
        int n; cin >> n;
        map<string, string> par;
        map<string, int> data;

        cout << "COMPANY " << test << "\n";
        while (n--) {
            string type; cin >> type;
            if (type == "ADD") {
                string sponsor, emp; cin >> sponsor >> emp;
                par[emp] = sponsor;
                data[emp] = 0;
            } else if (type == "SALE") {
                string emp; cin >> emp;
                int x; cin >> x;
                while (emp != "ROOT") {
                    data[emp] += x;
                    emp = par[emp]; 
                }
            } else if (type == "QUERY") {
                string emp; cin >> emp;
                cout << data[emp] << "\n";
            }
        }
    }

}