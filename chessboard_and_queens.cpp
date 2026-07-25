#include <bits/stdc++.h>
using namespace std;

const int N = 8;

typedef vector<int> vi;
typedef vector<char> vc;

vector<vc> grid;
vi col, diag1, diag2;
int ans;

void solve(int r) {
    if(r == N) {
        ans++;
        return;
    } else {
        for(int c = 0; c < N; c++) {
            if(grid[r][c] != '*') {
                if(col[c] || diag1[r - c + N - 1] || diag2[r + c]) continue;
                col[c] = diag1[r - c + N - 1] = diag2[r + c] = 1;
                solve(r + 1);
                col[c] = diag1[r - c + N - 1] = diag2[r + c] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    col.assign(N, 0);
    diag1.assign(2 * N - 1, 0);
    diag2.assign(2 * N - 1, 0);

    // ! be careful when handling input
    grid.assign(N, vc());

    ans = 0;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for(auto c : s) {
            grid[i].push_back(c);
        }
    }

    solve(0);

    cout << ans;

    return 0;
}