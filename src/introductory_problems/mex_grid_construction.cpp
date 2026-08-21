#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    if(n == 0){
        cout << 0;
        return 0;
    }

    vector<unordered_set<int>> v(2 * n - 2, unordered_set<int>());
    vector<vector<int>> ans(n, vector<int>(n));

    ans[0][0] = 0;

    for(int i = 0; i < n - 1; i++) {
        ans[i + 1][0] = i + 1;
        v[i].insert(i + 1);
        ans[0][i + 1] = i + 1;
        v[i + n - 1].insert(i + 1);
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            bool found = false;
            for(int k = 0; !found; k++) {
                if(v[i - 1].count(k) == 0 && v[j + n - 2].count(k) == 0) {
                    found = true;
                    v[i - 1].insert(k);
                    v[j + n - 2].insert(k);
                    ans[i][j] = k;
                }
            }
        }
    }

    for(auto r : ans) {
        for(auto x : r) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}