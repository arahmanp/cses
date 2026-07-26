#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;

        if(a + b > n || ((a == 0 || b == 0) && (a != 0 || b != 0))) {
            cout << "NO\n";
            continue;
        }

        int win = a;
        int lose = b;
        int draw = n - a - b;

        vector<int> card_a, card_b;

        for(int i = 1; i <= draw; i++) {
            card_a.push_back(i);
            card_b.push_back(i);
        }

        for(int i = n, count = 1; count <= win; i--, count++) {
            card_a.push_back(i);
        }

        for(int i = draw + win, count = 1; count <= win; i--, count++) {
            card_b.push_back(i);
        }

        for(int i = draw + 1, count = 1; count <= lose; i++, count++) {
            card_a.push_back(i);
        }

        for(int i = draw + win + 1, count = 1; count <= lose; i++, count++) {
            card_b.push_back(i);
        }

        cout << "YES\n";

        for(auto x : card_a) cout << x << ' ';

        cout << '\n';

        for(auto x : card_b) cout << x << ' ';

        cout << '\n';
    }

    return 0;
}
