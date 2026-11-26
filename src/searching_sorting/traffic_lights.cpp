#include <ios>
#include <iostream>
#include <iterator>
#include <set>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x;
    std::cin >> x;

    std::set<int> lights = {0, x};
    std::multiset<int> lengths = {x};

    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        int p;
        std::cin >> p;

        auto it = lights.lower_bound(p);

        int right = *it;
        int left = *std::prev(it);

        lights.insert(p);

        lengths.erase(lengths.find(right - left));
        lengths.insert(p - left);
        lengths.insert(right - p);

        std::cout << *lengths.rbegin() << ' ';
    }

    std::cout << '\n';
}