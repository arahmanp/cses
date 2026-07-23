#include <ios>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for(int i = 0; i < (1<<n); i++) {
        int x = i ^ (i>>1);

        for(int j = n - 1; j >= 0; j--) {
            if(x & (1<<j)) std::cout << 1;
            else std::cout << 0;
        }

        std::cout << '\n';
    }

    return 0;
}