#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<string> list1(n), list2(n);
    set<string> set1, set2;
    for (int i = 0; i < n; i++) cin >> list1[i];
    for (int i = 0; i < n; i++) cin >> list2[i];

    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur++;
        string name1 = list1[i], name2 = list2[i];
        set1.insert(name1);
        set2.insert(name2);
        if (set2.count(name1)) {
            set1.erase(name1);
            set2.erase(name1);
        }
        if (set1.count(name2)) {
            set1.erase(name2);
            set2.erase(name2);
        }
        if (set1.size() == 0 && set2.size() == 0) {
            cout << cur << '\n';
            cur = 0;
        }
    }

    if (cur) cout << cur << '\n';


    return 0;
}