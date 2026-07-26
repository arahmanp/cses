#include <ios>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    long long total_sum = (1LL * n * (n + 1)) / 2;

    if(total_sum % 2 != 0) {
        std::cout << "NO\n";
        return 0;
    }

    std::cout << "YES\n";

    long long half = total_sum / 2;

    std::vector<bool> used(n + 1, false);
    std::vector<int> first, second;

    long long tmp = half;
    int i = n;
    while(tmp != 0) {
        if(tmp >= i) {
            used[i] = true;
            first.push_back(i);
            tmp -= i;
        }
        i--;
    }

    for(int i = 1; i <= n; i++) {
        if(!used[i]) second.push_back(i);
    }

    std::cout << first.size() << '\n';
    for(auto el : first) std::cout << el << ' ';

    std::cout << '\n';

    std::cout << second.size() << '\n';
    for(auto el : second) std::cout << el << ' ';

    std::cout << '\n';

    return 0;
}