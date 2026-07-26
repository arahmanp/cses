#include <ios>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int prev, curr;
    std::cin >> prev;

    long long ans = 0;

    for(int i = 0; i < n - 1; i++) {
        std::cin >> curr;

        if(prev > curr) {
            int diff = prev - curr;
            ans += diff * 1LL;
            curr += diff;
        }

        prev = curr;
    }

    std::cout << ans;

    return 0;
}