#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-8;
const int maxn = 3005;
int nums[maxn];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    double p; cin >> p;
    for (int i = 0; i < n; i++) cin >> nums[i];

    int good = 0, bad = 0;
    for (int l = 0; l < n - 2; l++) {
        int sumDiffSq = (nums[l+1] - nums[l]) * (nums[l+1] - nums[l]);
        int sumDiff = nums[l+1] - nums[l];
        for (int r = l + 2; r < n; r++) {
            sumDiff += nums[r] - nums[r-1];
            sumDiffSq += (nums[r] - nums[r-1]) * (nums[r] - nums[r-1]);
            double A = (nums[r] - nums[l]) / (double)(r - l);

            double D = sumDiffSq - 2 * A * sumDiff + (r - l) * A * A;
            D = sqrt(D / (r - l));
 
            if (abs(A) < EPS) continue;
            if (D < EPS) {
                if (A > 0) good++;
                else bad++;
            } else {
                if (A / D >= p) good++;
                else if (A / D <= -p) bad++;
            }
        }
    }
    cout << good << " " << bad << "\n";
}