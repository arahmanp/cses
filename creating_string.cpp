#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  string s;
  cin >> s;

  int len = s.length();

  sort(s.begin(), s.end());

  vector<int> fact(9, 1);
  for(int i = 2; i <= 8; i++) fact[i] = fact[i - 1] * i;

  int ans = fact[len];
  
  unordered_map<char,int> m;
  for(auto c : s) m[c]++;

  for(auto [c, f] : m) ans /= fact[f];

  cout << ans << '\n';

  do {
    cout << s << '\n';
  } while(next_permutation(s.begin(), s.end()));

  return 0;
}

