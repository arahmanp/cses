#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> x(n + 1), pos(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        pos[x[i]] = i;
    }

    int rounds = 1;
    for(int i = 1; i < n; i++) {
        if(pos[i] > pos[i + 1]) rounds++;
    }

    while(m--) {
        int a, b;
        cin >> a >> b;

        int i = x[a];
        int j = x[b];

        set<int> affected = {
            i - 1, i,
            j - 1, j
        };

        for(auto k : affected) {
            if(k >= 1 && k < n) {
                if(pos[k] > pos[k + 1]) rounds--;
            }
        }

        swap(x[a], x[b]);
        swap(pos[i], pos[j]);

        for(auto k : affected) {
            if(k >= 1 && k < n) {
                if(pos[k] > pos[k + 1]) rounds++;
            }
        }

        cout << rounds << '\n';
    }
}