#include <ios>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    std::cin >> n;

    while(n != 1) {
        std::cout << n << ' ';

        if(n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
    }

    std::cout << 1;

    return 0;
}