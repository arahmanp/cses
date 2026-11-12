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

    std::vector<std::pair<int, int>> movies(n);
    for(int i = 0; i < n; i++) std::cin >> movies[i].first >> movies[i].second;

    std::sort(movies.begin(), movies.end(), [] (const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return a.second < b.second;
    });

    int ans = 0;
    int last = -1;
    for(auto [start, end] : movies) {
        if(start >= last) {
            ans++;
            last = end;
        }
    }

    std::cout << ans << '\n';
}