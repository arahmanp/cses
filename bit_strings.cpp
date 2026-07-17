#include <ios>
#include <iostream>

const int M = 1e9 + 7;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    long long res = 1;
    for(int i = 1; i <= n; i++) {
        res = (2 * res) % M;
    }

    std::cout << res << '\n';

    return 0;
}