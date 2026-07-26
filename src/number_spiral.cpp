#include <ios>
#include <iostream>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;

    while(t--) {
        ll y, x;

        std::cin >> y >> x;

        if(y == x) {
            std::cout << x * (x - 1) + 1 << '\n';
        } else if(y < x) {
            if(x % 2 == 0) {
                std::cout << x * x - 2 * x + 1 + y << '\n';
            } else {
                std::cout << x * x - y + 1 << '\n';
            }
        } else {
            if(y % 2 == 0) {
                std::cout << y * (y - 1) + 1 + y - x << '\n';
            } else {
                std::cout << y * (y - 1) + 1 - y + x << '\n';
            }
        }
    }

    return 0;
}