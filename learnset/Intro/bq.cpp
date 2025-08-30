#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, s; cin >> n >> s;
        unordered_set<string> names;
        for (int i = 0; i < n; i++) {
            string name; cin >> name;
            names.insert(name);
        } 

        for (int i = 0; i < s; i++) {
            string name; cin >> name;
            if (names.find(name) != names.end()) names.erase(name);
            if (names.size() == 1) {
                cout << *names.begin() << " " << i + 1 << endl;
                names.clear();
            }
        }
    }
    

    return 0;
}