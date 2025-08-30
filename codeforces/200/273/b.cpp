#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll getPairs(ll n) {
    return n * n - n * (n + 1) / 2;
}

int main() {
    int n, m; cin >> n >> m;
    int minNumberOfPeopleInTeam = n / m;
    int extraPeople = n % m;
    ll minPairs = (m - extraPeople) * getPairs(minNumberOfPeopleInTeam) + extraPeople * getPairs(n / m + 1);
    ll maxPairs = getPairs(n - m + 1);

    cout << minPairs << " " << maxPairs << '\n';
}