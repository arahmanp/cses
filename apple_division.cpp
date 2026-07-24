#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    if(n == 1) {
        cout << p[0];
        return 0;
    }

    ll best = 1e9;
    for(int i = 1; i < (1 << n) - 1; i++) {
        int a = i;
        int b = (1 << n) - 1 - a;

        ll w_a = 0, w_b = 0;
        for(int j = n - 1; j >= 0; j--) {
            if(a & (1 << j)) w_a += (ll)p[j];
            if(b & (1 << j)) w_b += (ll)p[j];
        }

        ll diff = abs(w_a - w_b);
        best = min(best, diff);
    }

    cout << best;

    return 0;
}
