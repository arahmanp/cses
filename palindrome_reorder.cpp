#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    std::unordered_map<char, int> freq;

    for(auto c : s) {
        freq[c]++;
    }

    int n = s.length();

    if(n % 2 == 0) {
        bool possible = true;

        for(auto [c, f] : freq) {
            if(f % 2 != 0) {
                possible = false;
                break;
            }
        }

        if(!possible) {
            std::cout << "NO SOLUTION";
            return 0;
        }

        std::string s1 = "", s2 = "";

        for(auto [c, f] : freq) {
            for(int i = 1; i <= f / 2; i++) s1 += c;
        }

        for(auto [c, f] : freq) {
            for(int i = 1; i <= f / 2; i++) s2 += c;
        }

        std::reverse(s2.begin(), s2.end());

        std::cout << s1 + s2;
    } else {
        int num_odd = 0;
        char chr_odd;

        for(auto [c, f] : freq) {
            if(f % 2 != 0) {
                num_odd++;
                chr_odd = c;
            }
        }

        if(num_odd != 1) {
            std::cout << "NO SOLUTION";
            return 0;
        }

        freq[chr_odd]--;

        std::string s1 = "", s2 = "";

        for(auto [c, f] : freq) {
            for(int i = 1; i <= f / 2; i++) s1 += c;
        }

        for(auto [c, f] : freq) {
            for(int i = 1; i <= f / 2; i++) s2 += c;
        }

        std::reverse(s2.begin(), s2.end());

        std::cout << s1 + chr_odd + s2;
    }

    return 0;
}