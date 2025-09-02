#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef long long ll;

int main() {
    int n; cin >> n;
    viii init_cube(n, vii(n, vi(n, 0)));
    vii dirs = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < n; z++) {
                cin >> init_cube[x][y][z];
            }
        }
    }

    int t; cin >> t;
    for (int test = 1; test <= t; test++) {
        viii cube = init_cube;
        ll res = 0;
        queue<vi> q;
        vi initial(3);
        for (int i = 0; i < 3; i++) cin >> initial[i];
        if (cube[initial[0]][initial[1]][initial[2]]) {
            q.push(initial);
            cube[initial[0]][initial[1]][initial[2]] = 0;
            res++;
        }
        while (!q.empty()) {
            vi u = q.front();
            q.pop();
            for (vi dir : dirs) {
                int x = u[0] + dir[0], y = u[1] + dir[1], z = u[2] + dir[2];
                if (0 <= x && x < n && 0 <= y && y < n && 0 <= z && z < n && cube[x][y][z]) {
                    q.push({x, y, z});
                    cube[x][y][z] = 0;
                    res++;
                } 
            }
        }
        cout << "Simulation #" << test << ", volume cleared is " << res << " cubic feet." << "\n\n";
    }


    return 0;
}