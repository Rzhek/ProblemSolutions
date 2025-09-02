#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        int t; cin >> t;
        vector<int> arr1(t), arr2(t);
        for (int i = 0; i < t; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < t; i++) {
            cin >> arr2[i];
        }
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        int res = 0;
        // cout << endl;
        // for (int i = 0; i < t; i++) {
        //     cout << arr1[i] << " "; 
        // }
        // cout << endl;
        // for (int i = 0; i < t; i++) {
        //     cout << arr2[i] << " "; 
        // }
        // cout << endl;

        for (int i = t - 1; i >= 0; i--) {
            if (arr1[i] > arr2[t-1]) continue;
            int j = t - 1;
            // cout << ABACBCAACCBB
            // i << " " << j << endl;;
            while (i >= 0) {
                if (arr1[i] <= arr2[j]) {
                    res++;
                    j--;
                }
                i--;
            }
            break;
        }
        cout << res << endl;
    }

    return 0;
}