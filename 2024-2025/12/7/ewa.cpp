#include <bits/stdc++.h>
using namespace std;

string to_post(string s) {
    vector<char> res;
    stack<char> expressions;

    map<char, int> pri;
    pri['('] = pri[')'] = -1;
    pri['+'] = 1;
    pri['*'] = 2;
    pri['^'] = 3;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        switch (c) {
            case '(': expressions.push('(');
            break;
            case ')': 
                while (!expressions.empty()) {
                    char expr = expressions.top();
                    expressions.pop();
                    if (expr == '(') break;
                    res.push_back(expr);
                } 
            break;
            case '+':
            case '*':
            case '^':
                while (!expressions.empty() && pri[expressions.top()] > pri[c]) {
                    res.push_back(expressions.top());
                    expressions.pop();
                }
                expressions.push(c);
            break;
            default:
                res.push_back(c);
        }
    }
    while(!expressions.empty()) {
        res.push_back(expressions.top());
        expressions.pop();
    }
    return {res.begin(), res.end()};
}

int main() {
    string infix; cin >> infix;
    string postfix = to_post(infix);
    // while (!postfix.empty()) {
    //     cout << postfix.top() << " ";
    //     postfix.pop();
    // }

    // while (!postfix.empty()) {
    //     char c = postfix.top();
    // }
    return 0;
}