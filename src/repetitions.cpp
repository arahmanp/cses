#include <algorithm>
#include <ios>
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    int n = s.length();
    int l = 0, r = 0;
    int best = -1;

    while(1) {
        while(r < n - 1 && s[r + 1] == s[r]) r++;

        best = std::max(best, r - l + 1);
        r++;
        l = r;

        if(r == n) break;
    }

    std::cout << best;

    return 0;
}