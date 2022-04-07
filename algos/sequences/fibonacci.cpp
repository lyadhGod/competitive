#include <bits/stdc++.h>
#include "../../helpers/helpers.h"

using namespace std;

// Time: O(logN); Space: O(1);
// nth_fibonacci(0): 0; nth_fibonacci(1): 1;
unsigned int nth_fibonacci(const unsigned int& n) {
  if (n < 2) {
    return n;
  }

  // FROM /algos/matrices/pow.cpp#pow_mat()
  auto pow_mat = [](
    const vector<vector<unsigned int>>& mat,
    const unsigned int& exp
  ) -> vector<vector<unsigned int>> {
    vector<vector<unsigned int>> res;

    unsigned int r = mat.size();
    if (r <= 0) {
      return res;
    }
    
    unsigned int c = mat[0].size();
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

    vector<vector<unsigned int>> temp(r);
    for (i = 0; i < r; i++) {
      temp[i].resize(c, 0);
    }
    for (i = 0; i < r; i++) {
      temp[i][i] = 1;
    }

    vector<vector<unsigned int>> n(r);
    for (i = 0; i < r; i++) {
      n[i].resize(c, 0);
    }

    auto copy = [&r, &c](
      const vector<vector<unsigned int>>& from,
      vector<vector<unsigned int>>& to
    ) -> void {
      int i, j;

      for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
          to[i][j] = from[i][j];
        }
      }
    };

    copy(mat, n);

    // FROM /algos/matrices/mul.cpp#mul()
    auto mul = [](
      const vector<vector<unsigned int>>& a,
      const vector<vector<unsigned int>>& b,
      vector<vector<unsigned int>>& mat
    ) -> void {
      unsigned int a1 = a.size();
      unsigned int b1 = b.size();
      unsigned int a2 = a[0].size();
      unsigned int b2 = b[0].size();

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

    return res;
  };

  vector<vector<unsigned int>> mat = {
    { 1, 1 },
    { 1, 0 }
  };

  mat = pow_mat(mat, n - 1);

  unsigned int res = mat[0][0];

  return res;
}

int main() {
  unsigned int res;

  unsigned int n = inp_int("n", true, 0, 20);

  res = nth_fibonacci(n);
  out_int(res, "nth_fibonacci()");

  return 0;
}
