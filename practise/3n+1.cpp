#include <bits/stdc++.h>

using namespace std;

int main() {
  int i, j, k;

  int n = 20;

  for (i = 1; i <= n; i++) {
    k = i;
    cout << k << " ";
    while (k != 1) {
      k = (k & 1) ? ((k << 1) + k + 1) : (k >> 1);
      if (k & 1) cout << k << " ";
    }
    cout << "\n";
  }

  return 0;
}