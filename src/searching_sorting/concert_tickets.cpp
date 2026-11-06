#include <ios>
#include <iostream>
#include <set>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> h(n), t(m);
    for(int i = 0; i < n; i++) std::cin >> h[i];
    for(int i = 0; i < m; i++) std::cin >> t[i];

    std::multiset<int> s;
    for(auto el : h) s.insert(el);

    for(auto el : t) {
        auto it = s.upper_bound(el);

        if(it != s.begin()) {
            it--;
            std::cout << *it << '\n';
            s.erase(it);
        } else {
            std::cout << -1 << '\n';
        }
    }
}