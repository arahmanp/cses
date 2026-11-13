#include <algorithm>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <vector>

using ll = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for(int i = 0; i < n; i++) std::cin >> p[i];

    std::sort(p.begin(), p.end());

    ll ans = 0;

    if(n % 2 != 0) {
        int med_idx = n / 2;
        int target = p[med_idx];

        for(auto el : p) {
            ans += abs(el - target);
        }
    } else {
        int a = n / 2;
        int b = a - 1;

        int target1 = p[a];
        int target2 = p[b];

        ll cost1 = 0;
        ll cost2 = 0;

        for(auto el : p) {
            cost1 += abs(el - target1);
            cost2 += abs(el - target2);
        }

        ans = std::min(cost1, cost2);
    }

    std::cout << ans << '\n';
}