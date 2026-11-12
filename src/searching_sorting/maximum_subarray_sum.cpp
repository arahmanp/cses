#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

using ll = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<ll> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];

    // kadane's algorithm
    ll best = -1e9 - 1;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        sum = std::max(a[i], sum + a[i]);
        best = std::max(best, sum);
    }

    std::cout << best << '\n';
}