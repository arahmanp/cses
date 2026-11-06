#include <algorithm>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) std::cin >> a[i];
    for(int i = 0; i < m; i++) std::cin >> b[i];

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int i = 0, j = 0, ans = 0;
    while(i < n && j < m) {
        if(b[j] < a[i] - k) j++;
        else if(b[j] > a[i] + k) i++;
        else if(b[j] >= a[i] - k && b[j] <= a[i] + k) {
            ans++;
            i++;
            j++;
        }
    }

    std::cout << ans << '\n';
}