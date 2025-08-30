#include <bits/stdc++.h>
using namespace std;

typedef struct Node Node;

struct Node {
    int level;
    int skipIndex;
    int skipLen;
    Node * next[26];

    Node(int lvl, int index, int len) {
        level = lvl;
        skipIndex = index;
        skipLen = len;
        for (int i = 0; i < 26; i++) next[i] = nullptr;
    }

    void insert(string &word, int index) {
        if (level == word.size()) return;

        int nextChar = word[level] - 'a';
        if (next[nextChar] == nullptr) {
            next[nextChar] = new Node(level + 1, index, word.size());
        }
        next[nextChar]->insert(word, index);
    }

};

int solve(Node * trie, string &word) {
    int curRes = 0, alt = 1e9;
    int prevSkip = -1;
    Node * cur = trie;

    for (int i = 0; i < word.size(); i++) {
        curRes++;

        if (cur->next[word[i]-'a'] == nullptr) {
            return curRes + word.size() - i - 1;
        }
        if (prevSkip != cur->next[word[i] - 'a']->skipIndex) {
            alt = curRes + cur->next[word[i] - 'a']->skipLen - i;
        } else {
            alt--;
        }
        curRes = min(curRes, alt);
        prevSkip = cur->next[word[i] - 'a']->skipIndex;
        cur = cur->next[word[i] - 'a'];
    }
    return curRes;

}

int main() {
    int n, m; cin >> n >> m;
    Node * trie = new Node(0, -1, 0);
        for (int i = 0; i < n; i++) {
        string word; cin >> word;
        trie->insert(word, i);
    }

    for (int i = 0; i < m; i++) {
        string word; cin >> word;
        cout << solve(trie, word) << '\n';
    }
    
    return 0;
}