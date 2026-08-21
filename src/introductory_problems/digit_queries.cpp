#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fast_exp(ll a, ll b) {
    if(b == 0) return 1;
    ll half = fast_exp(a, b / 2);
    if(b % 2 == 0) return half * half;
    return half * half * a;
}

ll total_digit(int n) {
    return ((9 * n - 1) * fast_exp(10, n) + 1) / 9;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int q;
    cin >> q;

    while(q--) {
        ll k;
        cin >> k;

        int n = 1;
        while(total_digit(n) < k) n++;

        k -= total_digit(n - 1);

        ll start = fast_exp(10, n - 1);

        ll x = (k - 1) / n;
        ll num = start + x;

        ll num_st = x + 1;
        k -= (num_st - 1) * n;
        string num_str = to_string(num);

        char ans = num_str[k - 1];

        cout << ans << '\n';
    }

    return 0;
}
