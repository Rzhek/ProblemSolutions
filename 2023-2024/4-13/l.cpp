#include <bits/stdc++.h>
using namespace std;

typedef struct Node Node;

struct Node {
    Node * left, * right;

    Node() {
        left = right = nullptr;
    }
};

unordered_map<Node *, int> greenMemo, memo;

int solveMax(Node * node, int green) {
    // cout << node << "\n";
    if (green && greenMemo.count(node)) return greenMemo[node];
    if (!green && memo.count(node)) return memo[node];
    
    // No children
    if (!node->left && !node->right) {
        return green;
    }

    // One child
    if (!node->right) {
        int res = green + solveMax(node->left, !green);
        if (green) greenMemo[node] = res;
        else memo[node] = res;
        return res;
    }

    // Two children
    if (green) {
        greenMemo[node] =  1 + solveMax(node->left, 0) + solveMax(node->right, 0);
        return greenMemo[node];
    }
    memo[node] = max(
        solveMax(node->left, 1) + solveMax(node->right, 0), 
        solveMax(node->left, 0) + solveMax(node->right, 1)
    );
    return memo[node];
}

int solveMin(Node * node, int green) {
    // cout << node << "\n";
    if (green && greenMemo.count(node)) return greenMemo[node];
    if (!green && memo.count(node)) return memo[node]; 
    // No children
    if (!node->left && !node->right) {
        return green;
    }

    // One child
    if (!node->right) {
        int res = green + solveMin(node->left, 0);
        if (green) greenMemo[node] = res;
        else memo[node] = res;
        return res;
    }

    // Two children
    if (green) {
        greenMemo[node] = 1 + solveMin(node->left, 0) + solveMin(node->right, 0);
        return greenMemo[node];
    }
    memo[node] = min(
        solveMin(node->left, 1) + solveMin(node->right, 0),
        solveMin(node->left, 0) + solveMin(node->right, 1)    
    );
    return memo[node];
}

int main() {
    string seq; cin >> seq;
    Node * root = new Node();
    stack<Node *> stk;
    int ind = 1;
    stk.push(root);
    for (int i = 0; i < seq.size(); i++) {
        if (seq[i] == '0') {
            stk.pop();
        } else if (seq[i] == '1') {
            Node * newNode = new Node();
            stk.top()->left = newNode;
            stk.pop();
            stk.push(newNode);
        } else {
            Node * left = new Node();
            Node * right = new Node();
            stk.top()->left = left;
            stk.top()->right = right;
            stk.pop();
            stk.push(left);
            stk.push(right);
        }
    }

    // int ma = 0, mi = 1e5;
    int ma = solveMax(root, 1);
    memo.clear();
    greenMemo.clear();
    int mi = solveMin(root, 0);
    cout << ma << " " << mi << '\n';


    return 0;
}