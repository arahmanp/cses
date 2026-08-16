#include <bits/stdc++.h>
using namespace std;

const int N = 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<bool>> visited;

int ans = 0;
int num_visited = 0;
long long num_recursive_calls = 0;

bool is_in_range(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

void search(int x, int y) {
    num_recursive_calls++;

    if(x == N - 1 && y == N - 1 && num_visited != N * N) return;

    if(x == N - 1 && y == N - 1 && num_visited == N * N) {
        ans++;
        return;
    } else {
        if(x == 0 && y == 0) {
            int next_x = x + dx[2];
            int next_y = y + dy[2];

            num_visited++;
            visited[next_x][next_y] = true;
            search(next_x, next_y);
            num_visited--;
            visited[next_x][next_y] = false;
        } else {
            for(int i = 0; i < 4; i++) {
                int next_x = x + dx[i];
                int next_y = y + dy[i];

                if(is_in_range(next_x, next_y)) {
                    if(!visited[next_x][next_y]) {
                        num_visited++;
                        visited[next_x][next_y] = true;
                        search(next_x, next_y);
                        num_visited--;
                        visited[next_x][next_y] = false;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    visited.assign(N, vector<bool>(N, false));

    num_visited++;
    visited[0][0] = true;
    search(0, 0);

    cout << num_recursive_calls << ' ' << ans * 2 << '\n';

    return 0;
}