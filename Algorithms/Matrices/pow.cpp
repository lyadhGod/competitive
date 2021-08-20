#include <bits/stdc++.h>
#include "../../Helpers/helpers.h"

using namespace std;

// Time: O(N^3logN); Space: O(1);
vector<vector<int>> pow_mat(
  const vector<vector<int>>& mat,
  const unsigned int& exp,
  const bool& _debug = true
) {
  vector<vector<int>> res;

  int r = mat.size();
  if (r <= 0) {
    return res;
  }
  int c = mat[0].size();
  if (c <= 0) {
    return res;
  }
  if (r != c) {
    return res;
  }

  int i;

  res.resize(r);
  for (i = 0; i < r; i++) {
    res[i].resize(c, 0);
  }
  for (i = 0; i < r; i++) {
    res[i][i] = 1;
  }

  vector<vector<int>> temp(r);
  for (i = 0; i < r; i++) {
    temp[i].resize(c, 0);
  }
  for (i = 0; i < r; i++) {
    temp[i][i] = 1;
  }

  vector<vector<int>> n(r);
  for (i = 0; i < r; i++) {
    n[i].resize(c, 0);
  }

  auto copy = [&r, &c](
    const vector<vector<int>>& from,
    vector<vector<int>>& to
  ) -> void {
    int i, j;

    for (i = 0; i < r; i++) {
      for (j = 0; j < c; j++) {
        to[i][j] = from[i][j];
      }
    }
  };

  copy(mat, n);

  // From Matrices/mul.cpp#mul()
  auto mul = [](
    const vector<vector<int>>& a,
    const vector<vector<int>>& b,
    vector<vector<int>>& mat
  ) -> void {
    int a1 = a.size();
    int b1 = b.size();
    int a2 = a[0].size();
    int b2 = b[0].size();

    int i, j, k, x;

    for (i = 0; i < a1; i++) {
      for (j = 0; j < b2; j++) {
        x = 0;
        for (k = 0; k < a2; k++) {
          x += a[i][k] * b[k][j];
        }
        mat[i][j] = x;
      }
    }
  };
  
  unsigned int a = exp;
  while (a > 0) {
    if (a & 1) {
      mul(res, n, temp);
      copy(temp, res);
    }
    mul(n, n, temp);
    copy(temp, n);
    a >>= 1;
  }

  if (_debug) {
    out_matrix_int(res, "pow_mat()");
    cout << "\n";
  }

  return res;
}

int main() {
  vector<vector<int>> mat = inp_matrix_int("mat", 2U, 2U, -10, 10);
  unsigned int exp_int = inp_int("exp", 0, 4);

  pow_mat(mat, exp_int);

  return 0;
}
