#include <algorithm>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>

using ii = std::pair<int, int>;

int search(const std::vector<ii> &v, int x) {
    int l = 0;
    int r = v.size() - 1;
    int ans = -1;

    while (l <= r && ans == -1) {
        int mid = l + (r - l) / 2;

        if (v[mid].first < x) {
            l = mid + 1;
        } else if (v[mid].first > x) {
            r = mid - 1;
        } else {
            ans = v[mid].second;
        }
    }

    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, x;
    std::cin >> n >> x;

    std::vector<ii> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i + 1;;
    }

    std::sort(a.begin(), a.end());

    int pos_1 = -1;
    int pos_2 = -1;

    for (auto [el, pos] : a) {
        int c = search(a, x - el);

        if (c != -1 && c != pos) {
            pos_1 = pos;
            pos_2 = c;
            break;
        }
    }

    if (pos_1 == -1 && pos_2 == -1) {
        std::cout << "IMPOSSIBLE\n";
    } else {
        std::cout << pos_1 << ' ' << pos_2 << '\n';
    }
}