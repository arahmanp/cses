#include <ios>
#include <iostream>
#include <set>
#include <vector>

using ll = long long;

ll count_subarrays(ll n) {
    return n * (n + 1) / 2;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> x(n);
    for(int i = 0; i < n; i++) std::cin >> x[i];

    ll l = 0;
    ll r = 0;
    ll prev_r = -1;
    ll total = 0;

    std::set<int> seen;

    while(r < n) {
        if(l < r && seen.contains(x[r])) {
            total += count_subarrays(r - l);
            if(prev_r != -1) total -= count_subarrays(prev_r - l + 1);
            prev_r = r - 1;
            while(l < r && seen.contains(x[r])) {
                seen.erase(x[l]);
                l++;
            }
        }
        seen.insert(x[r]);
        r++;
    }

    total += count_subarrays(r - l);
    if(prev_r != -1) total -= count_subarrays(prev_r - l + 1);

    std::cout << total << '\n';
}