#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 66668;
    vector<int> seq(n, -1);
    for (int i = 0; i < n; i += 2) {
        seq[i] = i / 2 * 3;
    }
    seq[n-1] = 100'000;
    cout << n << endl;
    while (1) {
        int num; cin >> num;
        if (num == -1) break;
        if (num % 3 == 0) {
            cout << (num / 3 * 2 + 1) << endl;
        } else if (seq[num / 3 * 2 + 1] != num) {
            cout << -1 << endl;
            if (num % 3 == 1) {
                seq[num / 3 * 2 + 1] = num + 1;
            } else {
                seq[num / 3 * 2 + 1] = num - 1;
            }
        } else {
            cout << num / 3 * 2 + 2 << endl;
        }
        cout.flush();
    }

    for (int i = 0; i < n; i++) {
        if (seq[i] == -1) {
            cout << seq[i-1] + 1 << endl;
        } else {
            cout << seq[i] << endl;
        }
    }





    return 0;
}

