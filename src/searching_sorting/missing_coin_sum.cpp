#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    sort(x.begin(), x.end());

    ll missing = 1;
    for(auto el : x) {
        if(el > missing) break;

        missing += el;
    }

    cout << missing << '\n';
}
