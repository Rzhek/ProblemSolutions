#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-6;
int queries = 0;

void query(int x1, int y1, int x2, int y2) {
    queries++;
    assert(queries <= 1024);
    assert(x1 >= 0 && x1 <= 1e5 && 0 <= y1 && y1 <= 1e5);
    assert(x2 >= 0 && x2 <= 1e5 && 0 <= y2 && y2 <= 1e5);
    cout << "query " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}

void answer(int x, int y, int r) {
    cout << "answer " << x << " " << y << " " << r << endl;
}

int main() {
    double dist = 0;
    int cur = 0;
    while (1) {
        query(cur, 0, cur, 100000);
        cin >> dist;
        if (dist > EPS) {
            break;
        }
        cur += 199;
    }

    int lo = cur - 199;
    int hi = cur;

    int lb = -1, ub = -1;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        query(m, 0, m, 100000);
        cin >> dist;
        if (dist > EPS) {
            hi = m - 1;
        } else {
            lo = m + 1;
            lb = m;
        }
    }

    assert(lb != -1);

    // if (lo + 1 <= 100000) {
    //     query(lo + 1, 0, lo + 1, 100000);
    //     cin >> dist;
    //     if (dist < EPS) lo++;
    // }

    // lb = lo;
    // cout << "left bound is found to be " << lb << "\n";

    lo = cur;
    hi = 100000;

    while (lo <= hi) {
        int m = (lo + hi) / 2;
        query(m, 0, m, 100000);
        cin >> dist;
        if (dist > EPS) {
            lo = m + 1;
        } else {
            hi = m - 1;
            ub = m;
        }
    }

    assert(ub != -1);

    // if (hi - 1 >= 0) {
    //     query(hi - 1, 0, hi - 1, 100000);
    //     cin >> dist;
    //     if (dist < EPS) hi--;
    // }

    // cout << "right bound is found to be " << ub << "\n"; 
    // ub = hi;

    int circleX = (lb + ub) / 2;
    int circleY;
    int diameter = ub - lb;
    int r = diameter / 2;

    assert(diameter % 2 == 0);
    
    // cout << r << "\n";
    
    lo = 0, hi = 100000;
    while (1) {
        int m = (lo + hi) / 2;
        query(circleX, m, circleX, 100000);
        cin >> dist;
        if (dist < EPS) {
            hi = m;
        } else if (dist < diameter) {
            circleY = m + dist - r + EPS;
            break;
        } else {
            lo = m;
        }
    }

    answer(circleX, circleY, r);

    
}