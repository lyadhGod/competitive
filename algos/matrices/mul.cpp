#include <bits/stdc++.h>
#include "../../helpers/helpers.h"

using namespace std;

// Time: O(MNP); Space: O(MP);
vector<vector<int>> mul(
  const vector<vector<int>>& a,
  const vector<vector<int>>& b
) {
  vector<vector<int>> mat;

  int a1 = a.size();
  if (a1 <= 0) {
    return mat;
  }

  int b1 = b.size();
  if (b1 <= 0) {
    return mat;
  }

  int a2 = a[0].size();
  int b2 = b[0].size();

  if (a2 != b1) {
    return mat;
  }

  int i, j, k, x;

  mat.resize(a1);
  for (i = 0; i < a1; i++) {
    mat[i].resize(b2);
  }

  for (i = 0; i < a1; i++) {
    for (j = 0; j < b2; j++) {
      x = 0;
      for (k = 0; k < a2; k++) {
        x += a[i][k] * b[k][j];
      }
      mat[i][j] = x;
    }
  }

  return mat;
}

int main() {
  vector<vector<int>> res;

  vector<vector<int>> a = inp_matrix_int("a", true, 2, 3, -10, 10);
  vector<vector<int>> b = inp_matrix_int("b", true, 3, 2, -10, 10);

  res = mul(a, b);
  out_matrix_int(res, "mul()");

  return 0;
}
