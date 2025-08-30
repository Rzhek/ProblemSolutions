#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    map<string, int> data;
    int n; cin >> n;
    while (n--) {
        string name; cin >> name;
        if (data.find(name) == data.end()) {
            data[name] = 1;
            cout << "OK\n"; 
        } else {
            data[name]++;
            name += to_string(data[name] - 1);
            cout << name << '\n';
        }
    }

}