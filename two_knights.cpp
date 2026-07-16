#include <ios>
#include <iostream>

#define SQ(n) ((n) * (n))

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for(long long k = 1; k <= n; k++) {
        long long semua_kemungkinan = (SQ(k) * (SQ(k) - 1)) / 2;
        long long saling_serang = 4 * (k - 1) * (k - 2);

        std::cout << semua_kemungkinan - saling_serang << '\n';
    }

    return 0;
}