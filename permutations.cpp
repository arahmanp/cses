#include <ios>
#include <iostream>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if(n == 1) {
        std::cout << 1;
        return 0;
    }

    if(n == 2 || n == 3) {
        std::cout << "NO SOLUTION";
        return 0;
    }

    int a = n;
    int b = n - 1;

    if(a % 2 == 0) std::swap(a, b);

    for(int i = a; i >= 1; i -= 2) std::cout << i << ' ';
    for(int i = b; i >= 1; i -= 2) std::cout << i << ' ';

    return 0;
}