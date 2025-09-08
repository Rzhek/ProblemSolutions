#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
bitset<86400> data;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;

    for (int ttt = 1; ttt <= tt; ttt++) {
        int n, k; cin >> n >> k;
        k--;
        vi lengths(n);
        for (auto &x : lengths) cin >> x;
        int totalTime = accumulate(lengths.begin(), lengths.end(), 0);
        int otherTime = totalTime - lengths[k];

        // cout << totalTime << " " << otherTime << "\n";
        // int sum = 0;
        // for (int x : lengths) cout << (sum += x) << " "; cout << "\n";

        int d; cin >> d;


        cout << "CD #" << ttt << ":\n";
        

        for (int j = 0; j < d; j++) {

            int intervals; cin >> intervals;

            vi times(intervals);
            for (int i = 0; i < intervals; i++) {
                cin >> times[i];
            }
                
            int rem = 0;
            int res = 0;


            for (int i = 0; i < intervals; i++) {
                // cout << rem << " " << res << "\n";

                if (i % 2 == 0) {
                    // in car
                    res += times[i];
                    rem = (lengths[k] - times[i] % lengths[k]) % lengths[k];
                } else {
                    // not in car
                    int freeTime = times[i];
                    freeTime -= rem;
                    if (freeTime <= 0) {
                        res += times[i];
                        rem = 0;
                        continue;
                    }
                    res += rem;
                    rem = 0;
                    
                    int totalCycles = freeTime / totalTime;
                    res += totalCycles * lengths[k];
                    
                    int timeRem = freeTime % totalTime;
                    if (timeRem > otherTime) res += timeRem - otherTime;
                }
            }
            cout << res << "\n";

            
        }

        


    }
}