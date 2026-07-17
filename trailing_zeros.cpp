#include <ios>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int res = 0;
    for(long long i = 5; i <= n; i *= 5) {
        res += n / i;
    }

    std::cout << res << '\n';

    return 0;
}