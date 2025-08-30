#include <bits/stdc++.h>
using namespace std;

string ones[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
string tens[] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
string hundreds[] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};

string convert(int num) {
    string res = "";
    if (num / 100 != 0) res += hundreds[num / 100 - 1];
    num %= 100;
    if (num / 10 != 0) res += tens[num / 10 - 1];
    num %= 10;
    if (num != 0) res += ones[num - 1];
    return res;
}

int index(vector<string> &arr, string el) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].compare(el) == 0) return i;
    }
    return -1;
}

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    vector<string> nums;
    for (int i = 0; i < 1000; i++) {
        nums.push_back(convert(i));
    }
    sort(nums.begin(), nums.end());
    vector<string> pos, neg;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i].compare("M") < 0) pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
    }

    int t; cin >> t;
    while (t--) {
        int num; cin >> num;
        string roman = convert(num % 1000);
        int extra = num / 1000;
        if (roman.compare("M") < 0) {
            cout << index(pos, roman) + extra * pos.size() << '\n';
        } else {
            int ans = neg.size() - index(neg, roman);
            ans += extra * neg.size();
            cout << -ans << '\n';
        }
    }
    return 0;
}