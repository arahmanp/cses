#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, x;
    std::cin >> n >> x;

    std::vector<int> p(n);
    for(int i = 0; i < n; i++) std::cin >> p[i];

    std::sort(p.begin(), p.end());

    int l = 0;
    int r = n - 1;
    int ans = 0;

    while(l < r) {
        if(p[l] + p[r] > x) {
            ans++;
            r--;
        } else {
            ans++;
            l++;
            r--;
        }
    }

    if(l == r) ans++;

    std::cout << ans << '\n';
}