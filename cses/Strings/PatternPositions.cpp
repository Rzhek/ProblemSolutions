#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define rep(i, a, b) for (int i = a; i < b; ++i)

using vi = vector<int>;

struct AhoCorasick
{
    enum
    {
        alpha = 26,
        first = 'a'
    }; // change this !
    struct Node
    {
        // (nmatches is optional)
        int back, next[alpha], start = -1, end = -1, nmatches = 0;
        Node(int v) { memset(next, v, sizeof(next)); }
    };
    vector<Node> N;
    vi backp;
    void insert(string &s, int j)
    {
        assert(!s.empty());
        int n = 0;
        for (char c : s)
        {
            int &m = N[n].next[c - first];
            if (m == -1)
            {
                n = m = sz(N);
                N.emplace_back(-1);
            }
            else
                n = m;
        }
        if (N[n].end == -1)
            N[n].start = j;
        backp.push_back(N[n].end);
        N[n].end = j;
        N[n].nmatches++;
    }
    AhoCorasick(vector<string> &pat) : N(1, -1)
    {
        rep(i, 0, sz(pat)) insert(pat[i], i);
        N[0].back = sz(N);
        N.emplace_back(0);
        queue<int> q;
        for (q.push(0); !q.empty(); q.pop())
        {
            int n = q.front(), prev = N[n].back;
            rep(i, 0, alpha)
            {
                int &ed = N[n].next[i], y = N[prev].next[i];
                if (ed == -1)
                    ed = y;
                else
                {
                    N[ed].back = y;
                    (N[ed].end == -1 ? N[ed].end : backp[N[ed].start]) = N[y].end;
                    N[ed].nmatches += N[y].nmatches;
                    q.push(ed);
                }
            }
        }
    }
    vi find(string word)
    {
        int n = 0;
        vi res; // l l count = 0;
        for (char c : word)
        {
            n = N[n].next[c - first];
            res.push_back(N[n].end);
            // count += N[n].nmatches;
        }
        return res;
    }
    vector<vi> findAll(vector<string> &pat, string word)
    {
        vi r = find(word);
        vector<vi> res(sz(word));
        rep(i, 0, sz(word))
        {
            int ind = r[i];
            while (ind != -1)
            {
                res[i - sz(pat[ind]) + 1].push_back(ind);
                ind = backp[ind];
            }
        }
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;

    int n; cin >> n;
    vector<string> patterns(n);
    for (auto &s : patterns) cin >> s;

    AhoCorasick aho(patterns);

    vector<int> res(n, -1);
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        cur = aho.N[cur].next[s[i]-'a'];
        // cout << cur << " " << aho.N[cur].nmatches << "\n";
        if (!aho.N[cur].nmatches) continue;
        int match = aho.N[cur].end;
        while (match != -1 && res[match] == -1) {
            res[match] = i + 2 - patterns[match].size();
            match = aho.backp[match];
        }
    }

    for (auto x : res) cout << x << "\n";

    // rep (i, 0, aho.N.size()) {
    //     auto x = aho.N[i];
    //     cout << i << ": " << x.back << " (back) " << x.start << " (start) " << x.end << " (end) " << x.nmatches << " (nmatches) ";
    //     cout << "{";
    //     for (int j = 0; j < 26; j++) if (x.next[j]) cout << (char)('a'+j) << ": " << x.next[j] << ", ";
    //     cout << "}\n";
    // }

    // for (int i = 0; i < 3; i++) {
    //     cout << i << ": " << aho.backp[i] << "\n";
    // }
}