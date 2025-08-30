#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string str; cin >> str;
    int n = str.size();
    vector<int> freq(26);
    for (char ch : str) {
        freq[ch - 'A']++;
    }

    vector<char>res(n);
    int ind = 0;
    int numOdd = 0;
    for (int i = 0; i < 26; i++) {
        int ch = freq[i];
        numOdd += ch & 1;
        if (numOdd > 1) {
            cout << "NO SOLUTION\n";
            return 0;
        } 
        if (ch & 1) {
            res[n / 2] = i + 'A';
            ch--;
        }
        while (ch > 0) {
            res[ind] = res[n-ind-1] = i + 'A';
            ind++;
            ch -= 2;
        }
    }

    for (char ch : res) cout << ch; cout << '\n';
    return 0;
}