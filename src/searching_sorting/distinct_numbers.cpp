#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    int ans = 1;

    sort(x.begin(), x.end());

    for(int i = 0; i < n - 1; i++) {
        if(x[i] != x[i + 1]) ans++;
    }

    cout << ans << '\n';
}
