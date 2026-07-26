#include <ios>
#include <iostream>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;

    while(t--) {
        int a, b;
        std::cin >> a >> b;

        if(a > b) std::swap(a, b);

        if((a + b) % 3 == 0 && 2 * a >= b) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}