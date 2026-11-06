#include <algorithm>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> events;

    for(int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;

        events.push_back({a, 1});
        events.push_back({b, -1});
    }

    std::sort(events.begin(), events.end());

    int cur = 0;
    int ans = -1;
    for(auto [e, t] : events) {
        cur += t;
        ans = std::max(ans, cur);
    }

    std::cout << ans << '\n';
}