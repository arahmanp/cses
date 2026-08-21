#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n;
vector<vi> grid;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool is_in_range(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n)
    {
        return true;
    }
    return false;
}

void search(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        for(int k = 0; k < 8; k++)
        {
            int next_i = i + dx[k];
            int next_j = j + dy[k];
            if(is_in_range(next_i, next_j))
            {
                if(grid[next_i][next_j] != -1) continue;
                grid[next_i][next_j] = grid[i][j] + 1;
                q.push({next_i, next_j});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    grid.assign(n, vi(n, -1));
    grid[0][0] = 0;

    search(0, 0);

    for (auto row : grid)
    {
        for (auto el : row)
        {
            cout << el << ' ';
        }
        cout << '\n';
    }

    return 0;
}