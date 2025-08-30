#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        if (num % 2) odd.push_back(i + 1);
        else even.push_back(i + 1);
    }
    cout << ((odd.size() == 1) ? odd.back() : even.back()) << '\n';
    
    

    return 0;
}