#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        int num; cin >> num;
        vector<vector<int>> arr(num, vector<int>(3));
        for (int i = 0; i < num; i++) {
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        }
        
        sort(arr.begin(), arr.end(), [](auto a, auto b) {
            return a[0] < b[0];
        });
        int ans = arr[0][1];
        for (int i = 1; i < num; i++) {
            int maxAdd = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j][0] + arr[j][2] <= arr[i][0]) {
                    maxAdd = max(maxAdd, arr[j][1]);
                }
            }
            arr[i][1] += maxAdd;
            ans = max(ans, arr[i][1]);
        }
        cout << ans << endl;

    }


    return 0;
}