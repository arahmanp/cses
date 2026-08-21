#include <iostream>
#include <string>

using namespace std;

const int N = 7;
bool visited[N + 2][N + 2]; // Padding dinding di sekeliling grid (index 1..7)
string path;
int ans = 0;

int dx[] = {-1, 0, 1, 0}; // U, R, D, L
int dy[] = {0, 1, 0, -1};

void search(int x, int y, int step) {
    // 1. Tiba di tujuan akhir (7, 1)
    if (x == 7 && y == 1) {
        if (step == 48) ans++;
        return;
    }
    
    // Jika belum 48 langkah tapi sudah sampai di tujuan, potong
    if (step == 48) return;

    // 2. Split Pruning (Memotong grid menjadi 2 bagian terpisah)
    // Depan tertutup, tapi kiri dan kanan kosong -> PASTI TLE / INVALID
    if ((visited[x + 1][y] && visited[x - 1][y]) && (!visited[x][y - 1] && !visited[x][y + 1])) return;
    if ((visited[x][y + 1] && visited[x][y - 1]) && (!visited[x - 1][y] && !visited[x + 1][y])) return;

    // 3. Eksekusi Langkah
    if (path[step] != '?') {
        int dir = -1;
        if (path[step] == 'U') dir = 0;
        else if (path[step] == 'R') dir = 1;
        else if (path[step] == 'D') dir = 2;
        else if (path[step] == 'L') dir = 3;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (!visited[nx][ny]) {
            visited[nx][ny] = true;
            search(nx, ny, step + 1);
            visited[nx][ny] = false;
        }
    } else {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                search(nx, ny, step + 1);
                visited[nx][ny] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Set border dinding luar grid
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= N + 1; j++) {
            if (i == 0 || i == N + 1 || j == 0 || j == N + 1) {
                visited[i][j] = true;
            }
        }
    }

    cin >> path;

    // Start dari (1,1) -> tujuan di (7,1)
    visited[1][1] = true;
    search(1, 1, 0);

    cout << ans << "\n";

    return 0;
}