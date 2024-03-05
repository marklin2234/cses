#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solve(int path[48], size_t idx, int i, int j, bool vis[9][9]) {
    if (idx == 48) {
        return i == 7 && j == 1;
    }

    if (i == 7 && j == 1) return 0;
    if (vis[i][j-1] && vis[i][j+1] && !vis[i+1][j] && !vis[i-1][j]) {
        return 0;
    }
    if (vis[i+1][j] && vis[i-1][j] && !vis[i][j+1] && !vis[i][j-1]) {
        return 0;
    }

    // D, U, R, L
    int directions[4][2] = { { 1, 0 }, { -1, 0 },
                        { 0, 1}, { 0, -1 } };

    vis[i][j] = true;
    int ret = 0;
    if (path[idx] == 4) {
        for (int (&d)[2] : directions) {
            int r = i + d[0], c = j + d[1];
            if (!(r < 1 || r > 7 || c < 1 || c > 7 || vis[r][c]))
                ret += solve(path, idx + 1, r ,c, vis);
        }
    } else {
        int r = i + directions[path[idx]][0];
        int c = j + directions[path[idx]][1];
        if (!(r < 1 || r > 7 || c < 1 || c > 7 || vis[r][c]))
            ret += solve(path, idx + 1, r ,c, vis);
    }
    vis[i][j] = false;
    return ret;
}

int main(void) {
    string in;
    getline(cin, in);
    int path[48];
    for (size_t i = 0; i < 48; i++) {
        if (in[i] == 'D') path[i] = 0;
        else if (in[i] == 'U') path[i] = 1;
        else if (in[i] == 'R') path[i] = 2;
        else if (in[i] == 'L') path[i] = 3;
        else path[i] = 4;
    }
    bool vis[9][9];
    for (int i = 0; i < 9; i++) fill(vis[i], vis[i] + 9, false);
    for (int i = 0; i < 9; i++) {
        vis[0][i] = true;
        vis[8][i] = true;
        vis[i][0] = true;
        vis[i][8] = true;
    }
    cout << solve(path, 0, 1, 1, vis) << endl;
}