#include <bits/stdc++.h>
using namespace std;

int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);

        int n, m;
        cin >> n >> m;

        string grid[n];
        for(int i = 0; i < n; i++) {
                cin >> grid[i];
        }

        // (i + j) genap -> A atau B
        // ganjil -> C atau D
        for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                        if((i + j) % 2 == 0) {
                                if(grid[i][j] == 'A') cout << 'B';
                                else cout << 'A';
                        } else {
                                if(grid[i][j] == 'C') cout << 'D';
                                else cout << 'C';
                        }
                }
                cout << '\n';
        }

        return 0;
}