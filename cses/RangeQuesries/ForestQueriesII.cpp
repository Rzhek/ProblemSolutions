#include <bits/stdc++.h>
using namespace std;

struct Node {
    int row_l, row_r, col_l, col_r, row_m, col_m;
    int val = 0;
    Node *q1, *q2, *q3, *q4;

    Node(vector<vector<int>> &grid, int row_l, int row_r, int col_l, int col_r) :
        row_l(row_l), row_r(row_r), col_l(col_l), col_r(col_r), row_m((row_l+row_r)/2), col_m((col_l+col_r)/2) {
        
        if (row_l == row_r || col_l == col_r) return;
            
        if  (row_l + 1 == row_r && col_l + 1 == col_r) {
            val = grid[row_l][col_l];
            q1 = q2 = q3 = q4 = 0;
            return;
        }
        
        // cout << row_l << " " << col_l << " | " << row_r << " " << col_r << "\n";
        q1 = new Node(grid, row_l, row_m, col_l, col_m);
        q2 = new Node(grid, row_l, row_m, col_m, col_r);
        q3 = new Node(grid, row_m, row_r, col_l, col_m);
        q4 = new Node(grid, row_m, row_r, col_m, col_r);
        val = q1->val + q2->val + q3->val + q4->val;
    }

    void update(int r, int c) {
        if (row_l == row_r || col_l == col_r) return;
        if (r < row_l || r >= row_r || c < col_l || c >= col_r) return;
        if (row_l + 1 == row_r && col_l + 1 == col_r) {
            assert(row_l == r);
            assert(col_l == c);
            val ^= 1;
            return;
        }

        q1->update(r, c);  
        q2->update(r, c);  
        q3->update(r, c);  
        q4->update(r, c);  
        val = q1->val + q2->val + q3->val + q4->val;
    }

    int query(int row_lo, int row_hi, int col_lo, int col_hi) {
        // cout << row_lo << " " << col_lo << " | " << row_hi << " " << col_hi << "\n";
        if (row_lo >= row_r || row_hi <= row_l || col_lo >= col_r || col_hi <= col_l) return 0;
        if (row_lo <= row_l && row_r <= row_hi && col_lo <= col_l && col_r <= col_hi) {
            // cout << "YO: " << row_l << " " << col_l << " | " << row_r << " " << col_r << "\n";
            return val;
        }
        
        // cout << row_l << " " << col_l << " | " << row_r << " " << col_r << "\n";
        return q1->query(row_lo, row_hi, col_lo, col_hi) + q2->query(row_lo, row_hi, col_lo, col_hi) + q3->query(row_lo, row_hi, col_lo, col_hi) + q4->query(row_lo, row_hi, col_lo, col_hi);
    }
};

int main() {
    // cin.tie(0)->sync_with_stdio(0);

    int n, q; cin >> n >> q;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            char ch; cin >> ch;
            grid[r][c] = ch == '*';
        }
    }

    Node *QT = new Node(grid, 0, n, 0, n);

    // Node *tmp = QT->q3->q4->q2;

    // cout << tmp->row_l << ", " << tmp->col_l << " -> " << tmp->row_r << ", " << tmp->col_r << "\n";
    // return 0;


    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int r, c; cin >> r >> c;
            QT->update(r-1, c-1);
        } else {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            cout << QT->query(r1 - 1, r2, c1 - 1, c2) << "\n";
        }
    }




}