#include <bits/stdc++.h>
using namespace std;

void solve(int n, int awal, int tujuan, int bantu) {
  if(n == 1) {
    cout << awal << ' ' << tujuan << '\n';
    return;
  }

  solve(n - 1, awal, bantu, tujuan);

  cout << awal << ' ' << tujuan << '\n';

  solve(n - 1, bantu, tujuan, awal);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int n;
  cin >> n;

  cout << (1<<n) - 1 << '\n';

  solve(n, 1, 3, 2);

  return 0;
}

