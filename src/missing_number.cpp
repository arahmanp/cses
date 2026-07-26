#include <ios>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<bool> used(n + 1, false);

    for(int i = 0; i < n - 1; i++) {
        int x;
        std::cin >> x;

        used[x] = true;
    }

    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            std::cout << i;
            break;
        }
    }

    return 0;
}