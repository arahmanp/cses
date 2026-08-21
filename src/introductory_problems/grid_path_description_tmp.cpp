#include <bits/stdc++.h>
using namespace std;

const int N = 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<bool>> visited;

int ans = 0;
int num_visited = 0;
long long num_recursive_calls = 0;

bool is_in_range(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}

bool is_wall(int x, int y)
{
    return !is_in_range(x, y) || visited[x][y];
}

void search(int x, int y)
{
    num_recursive_calls++;

    if (x == N - 1 && y == N - 1 && num_visited != N * N)
        return;

    if (x == N - 1 && y == N - 1 && num_visited == N * N)
    {
        ans++;
        return;
    }
    else
    {
        if (x == 0 && y == 0)
        {
            int next_x = x + dx[2];
            int next_y = y + dy[2];

            num_visited++;
            visited[next_x][next_y] = true;
            search(next_x, next_y);
            num_visited--;
            visited[next_x][next_y] = false;
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                int next_x = x + dx[i];
                int next_y = y + dy[i];

                int ahead_x = next_x + dx[i];
                int ahead_y = next_y + dy[i];

                int left_next_x = next_x + dx[(i + 1) % 4];
                int left_next_y = next_y + dy[(i + 1) % 4];

                int right_next_x = next_x + dx[(i + 3) % 4];
                int right_next_y = next_y + dy[(i + 3) % 4];

                if(is_wall(ahead_x, ahead_y) && !is_wall(left_next_x, left_next_y) && !is_wall(right_next_x, right_next_y)) 
                    continue;

                if (is_in_range(next_x, next_y))
                {
                    if (!visited[next_x][next_y])
                    {
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    visited.assign(N, vector<bool>(N, false));

    num_visited++;
    visited[0][0] = true;
    search(0, 0);

    cout << num_recursive_calls << ' ' << ans * 2 << '\n';

    return 0;
}