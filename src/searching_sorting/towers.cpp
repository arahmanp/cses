#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v;
    v.reserve(n);

    int first;
    cin >> first;
    v.push_back(first);

    for(int i = 0; i < n - 1; i++) {
        int el;
        cin >> el;

        int idx = -1;

        int l = 0;
        int r = v.size() - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(v[mid] > el) {
                idx = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if(idx == -1) v.push_back(el);
        else v[idx] = el;
    }

    cout << v.size() << '\n';
}