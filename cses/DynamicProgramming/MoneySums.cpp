#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    set<int> res{0};
    for (int coin : coins) {
        vector<int> newCoins;
        for (int prev : res) {
            newCoins.push_back(prev + coin);
        }
        for (int newCoin : newCoins) {
            res.insert(newCoin);
        }
    }

    res.erase(0);
    cout << res.size() << '\n';
    for (auto sum : res) {
        cout << sum << " ";
    }
    cout << '\n';
}