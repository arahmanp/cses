#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> k(n);
    for(int i = 0; i < n; i++) cin >> k[i];

    int longest = 0;
    set<int> seen;

    int l = 0;
    int r = 0;

    while(r < n) {
        while(l < r && seen.count(k[r]) == 1) {
            seen.erase(k[l]);
            l++;
        }
        seen.insert(k[r]);
        longest = max(longest, r - l + 1);
        r++;
    }

    if(l != r) longest = max(longest, r - l);

    cout << longest << '\n';
}